/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shading.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:39:48 by nryser            #+#    #+#             */
/*   Updated: 2025/04/23 16:39:48 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"

/**
 * @brief Applies the Phong reflection model to compute surface color.
 *
 * Calculates ambient, diffuse, and specular lighting based on the
 * material, light source, eye vector, and surface normal. Returns
 * the final color contribution at a given point on the surface.
 *
 * @param L A struct containing lighting and geometry information.
 * @return The resulting color at the shaded point.
 */
t_colour	ft_shading(t_shading L, bool in_shadow)
{
	t_colour	result;
	t_phong		ph;

	if (L.m.pattern && L.m.pattern->transform && L.obj && ((t_object *)L.obj)->transf)
		ph.effective_colour = mult_colours(
			pattern_colour_at_world(L.m.pattern, L.obj, L.point), L.l->lum);
	else
		ph.effective_colour = mult_colours(L.m.c, L.l->lum);
	ph.lightv = normalize(diff_tuple(L.l->pos, L.point));
	ph.ambient = mult_colour(ph.effective_colour, L.m.ambient);
	if (in_shadow)
		return (ph.ambient);
	ph.light_dot_normal = dot(ph.lightv, L.normalv);
	if (ph.light_dot_normal < 0)
	{
		ph.diffuse = ft_colour(0, 0, 0);
		ph.specular = ft_colour(0, 0, 0);
	}
	else
	{
		ph.diffuse = mult_colour(ph.effective_colour, L.m.diffuse * ph.light_dot_normal);
		ph.reflectv = ft_reflect(ft_negate(ph.lightv), L.normalv);
		ph.reflect_dot_eye = dot(ph.reflectv, L.eyev);
		if (ph.reflect_dot_eye <= 0)
			ph.specular = ft_colour(0, 0, 0);
		else
		{
			ph.factor = pow(ph.reflect_dot_eye, L.m.shininess);
			ph.specular = mult_colour(L.l->lum, L.m.specular * ph.factor);
		}
	}
	result = add_colours(ph.ambient, add_colours(ph.diffuse, ph.specular));
	return (result);
}


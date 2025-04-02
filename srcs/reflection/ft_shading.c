/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shading.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:33:26 by ameechan          #+#    #+#             */
/*   Updated: 2025/04/01 15:37:39 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_colour	ft_shading(t_shading L)
{
	t_colour	result = ft_colour(3, 3, 3);
	t_phong		ph;

	ph.effective_colour = mult_colours(L.m->c, L.l->lum);
	ph.lightv = normalise(diff_tuple(L.l->pos, L.point));
	ph.ambient = mult_colour(ph.effective_colour, L.m->ambient);
	ph.light_dot_normal = dot(ph.lightv, L.normalv);
	if (ph.light_dot_normal < 0)
	{
		ph.diffuse = ft_colour(0, 0, 0);
		ph.specular = ft_colour(0, 0, 0);
	}
	else
	{
		ph.diffuse = mult_colour(ph.effective_colour, L.m->diffuse * ph.light_dot_normal);
		ph.reflectv = ft_reflect(ft_negate(ph.lightv), L.normalv);
		ph.reflect_dot_eye = dot(ph.reflectv, L.eyev);
		if (ph.reflect_dot_eye <= 0)
			ph.specular = ft_colour(0, 0, 0);
		else
		{
			ph.factor = pow(ph.reflect_dot_eye, L.m->shininess);
			ph.specular = mult_colour(L.l->lum, L.m->specular * ph.factor);
		}
	}
	result = add_colours(ph.ambient, add_colours(ph.diffuse, ph.specular));
	return (result);
}

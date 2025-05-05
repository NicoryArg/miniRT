/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_add_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:01:08 by nryser            #+#    #+#             */
/*   Updated: 2025/05/05 10:01:23 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

int	valid_sphere(char **sp)
{
	if (count_split(sp) != 4)
		return (0);
	if (!is_vec3(sp[1]))
		return (0);
	if (!is_float(sp[2]))
		return (0);
	if (!is_color(sp[3]))
		return (0);
	return (1);
}

int	add_spheres(t_object **objects, t_parsed_scene *scene, int start)
{
	int					i;
	t_sphere_input		in;
	t_sphere			*sphere;
	t_matrix			*scale_m;
	t_matrix			*trans_m;

	i = 0;
	while (i < scene->sphere_count)
	{
		in = scene->spheres[i];
		sphere = ft_sphere(1);
		sphere->base.m = ft_material();
		sphere->base.m.c = in.color;
		scale_m = scale(in.diameter / 2.0,
				in.diameter / 2.0,
				in.diameter / 2.0);
		trans_m = translate(in.position.x, in.position.y, in.position.z);
		set_transf(sphere, multiply_and_free(scale_m, trans_m));
		objects[start + i] = (t_object *)sphere;
		i++;
	}
	return (start + i);
}

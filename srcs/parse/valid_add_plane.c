/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_add_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:19:37 by nryser            #+#    #+#             */
/*   Updated: 2025/05/06 20:19:37 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

int	valid_plane(char **tokens)
{
	if (count_split(tokens) != 5)
		return (0);
	if (!is_vec3(tokens[1]))
		return (0);
	if (!is_vec3(tokens[2]))
		return (0);
	if (!is_color(tokens[3]))
		return (0);
	if (!is_int(tokens[4]))
		return (0);
	return (1);
}

int	add_planes(t_object **objects, t_parsed_scene *scene, int start)
{
	int				i;
	t_plane_input	in;
	t_plane			*plane;
	t_matrix		*rot_m;
	t_matrix		*trans_m;

	i = 0;
	while (i < scene->plane_count)
	{
		in = scene->planes[i];
		plane = ft_plane();
		plane->base.m = ft_material();
		plane->base.m.c = in.color;
		plane->base.m.ambient = 0.1;
		plane->base.m.diffuse = 0.9;
		plane->base.m.specular = 0.0;
		if (in.patt_type >= 1 && in.patt_type <= 7)
			plane->base.m.pattern = create_pattern_by_type(in.patt_type, in.color, SHAPE_PLANE);
		rot_m = align_up_vector(normalize(in.normal));
		trans_m = translate(in.position.x, in.position.y, in.position.z);
		set_transf(plane, multiply_and_free(rot_m, trans_m));
		objects[start + i] = (t_object *)plane;
		i++;
	}
	return (start + i);
}

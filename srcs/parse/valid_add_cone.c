/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_add_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:25:25 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 18:25:56 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

int	valid_cone(char **tokens)
{
	double	diameter;
	double	min;
	double	max;

	if (count_split(tokens) != 8)
		return (0);
	if (!is_vec3(tokens[1]) || !is_vec3(tokens[2]))
		return (0);
	if (!is_float(tokens[3]) || !is_float(tokens[4]) || !is_float(tokens[5]))
		return (0);
	diameter = ft_atof(tokens[3]);
	min = ft_atof(tokens[4]);
	max = ft_atof(tokens[5]);
	if (diameter <= 0.0 || min >= max)
		return (0);
	if (!is_color(tokens[6]))
		return (0);
	if (ft_atoi(tokens[7]) > 5 || ft_atoi(tokens[7]) < 0)
		return (0);
	return (1);
}

static t_cone	*build_cone(t_cone_input in)
{
	t_cone		*cone;
	t_matrix	*scale_m;
	t_matrix	*align_m;
	t_matrix	*trans_m;
	t_matrix	*tmp;

	cone = ft_cone();
	cone->base.m = ft_material();
	cone->base.m.c = in.color;
	if (in.patt_type >= 1 && in.patt_type <= 7)
		cone->base.m.patt = create_patt_by_type(
				in.patt_type, in.color, SHAPE_CONE);
	cone->min = in.min;
	cone->max = in.max;
	cone->closed = true;
	scale_m = scale(in.diameter / 2.0, 1, in.diameter / 2.0);
	align_m = align_up_vector(normalize(in.normal));
	trans_m = translate(in.position.x, in.position.y, in.position.z);
	tmp = multiply_and_free(scale_m, align_m);
	set_transf(cone, multiply_and_free(tmp, trans_m));
	return (cone);
}

int	add_cones(t_object **objects, t_parsed_scene *scene, int start)
{
	int	i;

	i = 0;
	while (i < scene->cone_count)
	{
		objects[start + i] = (t_object *)build_cone(scene->cones[i]);
		i++;
	}
	return (start + i);
}

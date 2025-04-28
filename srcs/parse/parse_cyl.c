/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cyl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:27:34 by nryser            #+#    #+#             */
/*   Updated: 2025/04/28 19:27:43 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/parse.h"
#include "../../includes/engine.h"

typedef struct s_cyl_data
{
	t_tuple	pos;
	t_tuple	axis;
	double	diameter;
	double	height;
	t_colour	color;
}	t_cyl_data;


static void	parse_cylinder_data(char **split_line, t_cyl_data *data)
{
	data->pos = parse_tuple(split_line[1], POINT);
	data->axis = parse_tuple(split_line[2], VECTOR);
	data->diameter = ft_atof(split_line[3]);
	data->height = ft_atof(split_line[4]);
	data->color = parse_color(split_line[5]);
}

static void	build_cylinder_transform(t_cylinder *cyl, t_cyl_data data)
{
	t_tuple	default_axis;
	t_matrix	*rotation;
	t_matrix	*translation;
	t_matrix	*final_transform;

	default_axis = ft_tuple(0, 1, 0, VECTOR);
	rotation = rotation_matrix(default_axis, data.axis);
	translation = translate(data.pos.x, data.pos.y, data.pos.z);
	final_transform = multiply_matrices(translation, rotation);
	set_transf(&(cyl->base), final_transform);
	free_matrix(rotation);
	free_matrix(translation);
	free_matrix(final_transform);
}

t_cylinder	*parse_cylinder(char **split_line)
{
	t_cyl_data	data;
	t_cylinder	*cyl;

	parse_cylinder_data(split_line, &data);
	cyl = ft_cylinder();
	build_cylinder_transform(cyl, data);
	cyl->centre = data.pos;
	cyl->radius = data.diameter / 2.0;
	cyl->min = 0;
	cyl->max = data.height;
	cyl->closed = true;
	cyl->base.m.c = data.color;
	return (cyl);
}

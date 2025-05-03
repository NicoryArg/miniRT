/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 08:10:05 by nryser            #+#    #+#             */
/*   Updated: 2025/05/03 08:10:12 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

void	load_ambient(char **tokens, t_parsed_scene *scene)
{
	scene->ambient_ratio = ft_atof(tokens[1]);
	scene->ambient_color = parse_color(tokens[2]);
	scene->has_ambient = 1;
}

void	load_camera(char **tokens, t_parsed_scene *scene)
{
	scene->camera_pos = parse_point(tokens[1]);
	scene->camera_dir = parse_tuple(tokens[2], VECTOR);
	scene->fov = ft_atof(tokens[3]);
	printf("Parsed FOV: %f\n", scene->fov);
	scene->has_camera = 1;
}
void	load_light(char **tokens, t_parsed_scene *scene)
{
	if (scene->light_count >= MAX_LIGHTS)
		return;

	scene->light_positions[scene->light_count] = parse_point(tokens[1]);
	scene->light_colours[scene->light_count] = parse_color(tokens[2]);
	scene->light_count++;
}

void	load_sphere(char **sp, t_parsed_scene *scene)
{
	t_sphere_input	sphere;

	sphere.position = parse_point(sp[1]);
	sphere.diameter = ft_atof(sp[2]);
	sphere.color = parse_color(sp[3]);
	scene->spheres[scene->sphere_count++] = sphere;
}

void	load_plane(char **tokens, t_parsed_scene *scene)
{
	t_plane_input	p;

	p.position = parse_point(tokens[1]);
	p.normal = parse_point(tokens[2]);
	p.color = parse_color(tokens[3]);

	scene->planes[scene->plane_count++] = p;
}

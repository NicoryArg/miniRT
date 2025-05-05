/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_unique.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:00:10 by nryser            #+#    #+#             */
/*   Updated: 2025/05/05 10:00:19 by nryser           ###   ########.ch       */
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
		return ;
	scene->light_positions[scene->light_count] = parse_point(tokens[1]);
	scene->light_colours[scene->light_count] = parse_color(tokens[2]);
	scene->light_count++;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:01:39 by nryser            #+#    #+#             */
/*   Updated: 2025/05/05 10:01:39 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

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

void	load_cylinder(char **tokens, t_parsed_scene *scene)
{
	t_cylinder_input	cy;

	cy.position = parse_point(tokens[1]);
	cy.normal = normalize(parse_point(tokens[2]));
	cy.diameter = ft_atof(tokens[3]);
	cy.height = ft_atof(tokens[4]);
	cy.color = parse_color(tokens[5]);
	scene->cylinders[scene->cylinder_count++] = cy;
}

void	load_cone(char **tokens, t_parsed_scene *scene)
{
	t_cone_input	cone;

	cone.position = parse_point(tokens[1]);
	cone.normal = parse_tuple(tokens[2], VECTOR);
	cone.diameter = ft_atof(tokens[3]);
	cone.min = ft_atof(tokens[4]);
	cone.max = ft_atof(tokens[5]);
	cone.color = parse_color(tokens[6]);
	scene->cones[scene->cone_count++] = cone;
}

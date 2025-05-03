/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 08:36:27 by nryser            #+#    #+#             */
/*   Updated: 2025/05/03 08:38:06 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"
#include "tests.h"


t_matrix	*align_up_vector(t_vector3d normal)
{
	t_vector3d	up;

	up = ft_vector(0, 1, 0);
	if (equal_tuple(normalize(normal), up))
		return (create_identity_matrix(4));
	return (rotation_matrix(up, normal));
}
t_world	*convert_scene_to_world(t_parsed_scene *scene)
{
	t_world		*w;
	t_sphere	*sphere;
	t_plane		*plane;
	t_object	**objects;
	int			i;
	int			obj_count;

	w = ft_world();
	if (!w)
		malloc_err("Failed to allocate world");

	obj_count = scene->sphere_count + scene->plane_count;
	objects = malloc(sizeof(t_object *) * obj_count);
	if (!objects)
		malloc_err("Failed to allocate objects");

	i = 0;
	// Spheres
	for (int s = 0; s < scene->sphere_count; s++)
	{
		t_sphere_input in = scene->spheres[s];
		sphere = ft_sphere(1);
		sphere->base.m = ft_material();
		sphere->base.m.c = in.color;

		double radius = in.diameter / 2.0;
		t_matrix *scale_m = scale(radius, radius, radius);
		t_matrix *trans_m = translate(in.position.x, in.position.y, in.position.z);
		t_matrix *transform = multiply_and_free(scale_m, trans_m);
		set_transf(sphere, transform);

		objects[i++] = (t_object *)sphere;
	}

	// Planes
	for (int p = 0; p < scene->plane_count; p++)
	{
		t_plane_input in = scene->planes[p];
		plane = ft_plane();
		plane->base.m = ft_material();
		plane->base.m.c = in.color;
		plane->base.m.ambient = 0.1;
		plane->base.m.diffuse = 0.9;
		plane->base.m.specular = 0.0;

		t_vector3d n = normalize(in.normal);
		t_matrix *rot_m = align_up_vector(n);
		t_matrix *trans_m = translate(in.position.x, in.position.y, in.position.z);
		t_matrix *transform = multiply_and_free(rot_m, trans_m);
		set_transf(plane, transform);
		print_matrix(plane->base.transf);  // Add after set_transf

		objects[i++] = (t_object *)plane;
	}

	w->ambient.ratio = scene->ambient_ratio;
	w->ambient.colour = scene->ambient_color;
	w->objects = (void **)objects;
	w->object_count = obj_count;

	for (int i = 0; i < scene->light_count; i++)
		add_light_to_world(w,
			ft_light(scene->light_positions[i], scene->light_colours[i]));

	return (w);
}


t_parsed_scene	build_scene_from_tokens(t_tokens *head)
{
	t_parsed_scene	scene;
	t_tokens		*current;

	scene.sphere_count = 0;
	scene.plane_count = 0;
	scene.light_count = 0;
	scene.has_ambient = 0;
	scene.has_camera = 0;
	current = head;
	while (current)
	{
		if (current->type == A)
		{
			if (!valid_ambient(current->tokens))
				printf("Invalid ambient light\n");
			load_ambient(current->tokens, &scene);
		}
		if (current->type == C)
		{
			if (!valid_camera(current->tokens))
				printf("Invalid camera\n");
			load_camera(current->tokens, &scene);
		}
		else if (current->type == L)
		{
			if (!valid_light(current->tokens))
				printf("Invalid light\n");
			load_light(current->tokens, &scene);
		}
		else if (current->type == PL)
		{
			if (!valid_plane(current->tokens))
				printf("Invalid plane\n");
			load_plane(current->tokens, &scene);
		}
		else if (current->type == SP)
		{
			if (!valid_sphere(current->tokens))
				printf("Invalid sphere\n");
			load_sphere(current->tokens, &scene);
		}
		// else if (current->type == CY)
		// {
		// 	if (!valid_cylinder(current->tokens))
		// 		printf("Invalid cylinder\n");
		// 	load_cylinder(current->tokens, &scene);
		// }

		current = current->next;
	}
	return (scene);
}

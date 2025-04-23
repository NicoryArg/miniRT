/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene_pattern.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:03:18 by nryser            #+#    #+#             */
/*   Updated: 2025/04/23 17:04:43 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"
#include "engine.h"
#include "tests.h"

t_world	*scene_pattern(void)
{
	t_world		*w;
	t_sphere	*s1;
	t_sphere	*s2;
	t_sphere	*s3;
	t_plane		*floor;
	t_plane		*left_wall;
	t_plane		*right_wall;
	t_pattern	*pat1;
	t_pattern	*pat2;
	t_pattern	*pat3;
	t_pattern	*floor_pat;
	t_pattern	*wall_pat_left;
	t_pattern	*wall_pat_right;
	t_matrix	*transform;
	t_matrix	*left_rot;
	t_matrix	*right_rot;
	int			object_count;

	object_count = 0;

	// Sphere 1 — Diagonal red/yellow stripes
	// Sphere 1 — UV checkers
	s1 = ft_sphere(1);
	s1->base.m = ft_material();
	pat1 = malloc(sizeof(t_pattern));
	*pat1 = uv_checkers_pattern(
		ft_colour(1, 0.2, 1), ft_colour(1, 1, 0), 12, 12);
	pat1->transform = create_identity_matrix(4);
	s1->base.m.pattern = pat1;
	s1->base.m.specular = 0.3;
	s1->base.m.diffuse = 0.7;
	transform = multiply_matrices(scale(0.9, 0.9, 0.9), translate(-0.5, 0.9, 0.5));
	set_transf(s1, transform);
	object_count++;

	// Sphere 2 — math ring pattern
	s2 = ft_sphere(1);
	s2->base.m = ft_material();
	pat2 = malloc(sizeof(t_pattern));
	*pat2 = ring_pattern(ft_colour(0, 0.5, 0), ft_colour(0, 0.9, 0));
	pat2->transform = create_identity_matrix(4);
	s2->base.m.pattern = pat2;
	s2->base.m.specular = 0.3;
	s2->base.m.diffuse = 0.7;
	transform = multiply_matrices(scale(0.5, 0.5, 0.5), translate(3, 1, -2.8));
	set_transf(s2, transform);
	object_count++;

	// Sphere 3 — gradient
	s3 = ft_sphere(1);
	s3->base.m = ft_material();
	pat3 = malloc(sizeof(t_pattern));
	*pat3 = gradient_pattern(
		ft_colour(1, 0.8, 1), ft_colour(1, 0.2, 1));
	pat3->transform = scale(0.25, 1.0, 1.0);
	s3->base.m.pattern = pat3;
	s3->base.m.specular = 0.3;
	s3->base.m.diffuse = 0.7;
	transform = multiply_matrices(scale(0.33, 0.33, 0.33), translate(-5, 0.8, -2.7));
	set_transf(s3, transform);
	object_count++;

	// Floor — UV checkers
	floor = ft_plane();
	floor->base.m = ft_material();
	floor->base.m.specular = 0;
	floor_pat = malloc(sizeof(t_pattern));
	*floor_pat = uv_checkers_pattern(
		ft_colour(0.5, 0, 0.9), ft_colour(0, 0.8, 0.8), 2, 2);
	floor_pat->transform = create_identity_matrix(4);
	floor->base.m.pattern = floor_pat;
	object_count++;

	// Left wall — UV gradient
	left_wall = ft_plane();
	left_wall->base.m = ft_material();
	left_wall->base.m.specular = 0;
	wall_pat_left = malloc(sizeof(t_pattern));
	*wall_pat_left = uv_gradient_pattern(
		ft_colour(0.5, 0, 0.9), ft_colour(0, 0.8, 0.8), 0, 0);
	wall_pat_left->transform = multiply_matrices(
		rotate_y(-M_PI / 4), multiply_matrices(rotate_x(M_PI / 2), scale(1, 1, 1)));
	left_wall->base.m.pattern = wall_pat_left;
	left_rot = multiply_matrices(rotate_y(-M_PI / 4), rotate_x(M_PI / 2));
	set_transf(left_wall, multiply_matrices(translate(-5, 0, 0), left_rot));
	free_matrix(left_rot);
	object_count++;

	// Right wall — UV stripes
	right_wall = ft_plane();
	right_wall->base.m = ft_material();
	right_wall->base.m.specular = 0;
	wall_pat_right = malloc(sizeof(t_pattern));
	*wall_pat_right = uv_stripe_pattern(
		ft_colour(0.5, 0, 0.9), ft_colour(0, 0.8, 0.8), 10, 1);
	wall_pat_right->transform = multiply_matrices(
		rotate_y(M_PI / 4), multiply_matrices(rotate_x(M_PI / 2), scale(1, 1, 1)));
	right_wall->base.m.pattern = wall_pat_right;
	right_rot = multiply_matrices(rotate_y(M_PI / 4), rotate_x(M_PI / 2));
	set_transf(right_wall, multiply_matrices(translate(5, 0, 0), right_rot));
	free_matrix(right_rot);
	object_count++;


	// World and light
	w = ft_world();
	w->light = ft_light(ft_tuple(-10, 10, -10, POINT), ft_colour(1, 1, 1));
	w->objects = malloc(sizeof(t_object *) * object_count);
	if (!w->objects)
		return (NULL);

	w->objects[0] = &s1->base;
	w->objects[1] = &s2->base;
	w->objects[2] = &s3->base;
	w->objects[3] = &floor->base;
	w->objects[4] = &left_wall->base;
	w->objects[5] = &right_wall->base;
	w->object_count = object_count;

	return (w);
}


void	draw_scene_patterns(t_engine *engine)
{
	t_world		*w;
	t_camera	cam;

	w = scene_pattern();
	cam = ft_camera(WIN_SIZE, WIN_SIZE, 60);
	cam.transf = view_transform(
		ft_tuple(0, 2, -7, POINT),   // camera position
		ft_tuple(0, 0, 10, POINT),   // look-at target
		ft_tuple(0, 1, 0, VECTOR));  // up vector

	render(cam, w, &engine->image);

	mlx_put_image_to_window(engine->mlx, engine->window,
		engine->image.img_ptr, 0, 0);

	free_world(w);
	free_matrix(cam.transf);
}

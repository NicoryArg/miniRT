/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:00:34 by nryser            #+#    #+#             */
/*   Updated: 2025/04/25 15:27:13 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"
#include "engine.h"
#include "tests.h"


static t_world	*scene_cone_capped()
{
	t_world		*w;
	t_cone	*cone1;
	t_cone	*cone2;
	// t_cone	*cone3;
	t_matrix	*transform;
	int			object_count = 0;

	//dark green cylinder
	cone1 = ft_cone();
	cone1->base.m.c = ft_colour(1, 1, 0.5);
	cone1->base.m.diffuse = 0.7;
	cone1->base.m.specular = 0.3;
	cone1->min = 0;
	cone1->max = 1;
	cone1->closed = true;
	transform = translate(-2, 3, 0);

	set_transf((t_object *)cone1, transform);
	printf("[cone-transformed] min: %.2f max: %.2f\n", cone1->min, cone1->max);
	object_count++;

// //light green cylinder
	cone2 = ft_cone();
	cone2->base.m.c = ft_colour(0, 1, 1);
	cone2->base.m.diffuse = 0.7;
	cone2->base.m.specular = 0.3;
	cone2->min = -4;
	cone2->max = 4;
	cone2->closed = true;
	transform = multiply_matrices(translate(2.5, 2, -3), rotate_z(M_PI / 2));
	set_transf(cone2, transform);
	object_count++;

// //Lilac cylinder
// 	cone3 = ft_cone();
// 	cone3->base.m.c = ft_colour(1, 0.8, 1);
// 	cone3->base.m.diffuse = 0.7;
// 	cone3->base.m.specular = 0.3;
// 	cone3->min = -22;
// 	cone3->max = -5;
// 	cone3->closed = true;
// 	transform = multiply_matrices(scale(0.6, 0.6, 0.6), translate(-13.2, 0.8, -2.7));
// 	set_transf(cone3, transform);
// 	object_count++;

//Floor
	t_plane	*floor = ft_plane();
	floor->base.m.c = ft_colour(0.8, 0.8, 0.8);
	floor->base.m.specular = 0;
	object_count++;

//right wall
	t_plane	*right_wall = ft_plane();
	set_transf(right_wall, multiply_matrices(rotate_y(M_PI/4), rotate_x(M_PI/2)));
	set_transf(right_wall, multiply_matrices(translate(0,0,10), right_wall->base.transf));
	right_wall->base.m.c = ft_colour(0.8, 0.8, 0.8);
	right_wall->base.m.specular = 0;
	object_count++;

//left wall
	t_plane	*left_wall = ft_plane();
	set_transf(left_wall, multiply_matrices(rotate_y(-M_PI/4), rotate_x(M_PI/2)));
	set_transf(left_wall, multiply_matrices(translate(0,0,10), left_wall->base.transf));
	left_wall->base.m.c = ft_colour(0.8, 0.8, 0.8);
	left_wall->base.m.specular = 0;
	object_count++;

//World
	w = ft_world();
	w->light = ft_light(ft_tuple(-10, 10, -10, POINT), ft_colour(1, 1, 1));
	w->objects = malloc(sizeof(t_object *) * object_count);
	if (!w->objects)
		return (NULL);
	w->objects[0] = floor;
	w->objects[1] = right_wall;
	w->objects[2] = left_wall;
	w->objects[3] = cone1;
	w->objects[4] = cone2;
	// w->objects[2] = cone3;
	w->object_count = object_count;
	return (w);
}

void	draw_cone(t_engine *engine)
{
	t_world		*w;
	t_camera	cam;
	t_tuple		n;

	w = scene_cone_capped();
	n = normal_at((t_object *)w->objects[3], ft_tuple(1, 3, 0, POINT));
	printf("Side normal: (%.2f, %.2f, %.2f)\n", n.x, n.y, n.z);
	cam = ft_camera(WIN_SIZE, WIN_SIZE, 60);//try to not change
	cam.transf = view_transform(
		ft_tuple(0, 5, -15, POINT),//from camera
		ft_tuple(0, 0, 10, POINT),//look at target
		ft_tuple(0, 1, 0, VECTOR));//up vector
	printf("render\n");
	render(cam, w, &engine->image);
	mlx_put_image_to_window(engine->mlx, engine->window,
		engine->image.img_ptr, 0, 0);
	free_world(w);
	free_matrix(cam.transf);
}

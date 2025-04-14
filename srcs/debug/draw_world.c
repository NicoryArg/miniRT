/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:58:42 by nryser            #+#    #+#             */
/*   Updated: 2025/04/14 17:58:42 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"

void	draw_world(t_engine *engine)
{
	t_world		*w;
	t_camera	cam;

	w = default_scene();
	cam = ft_camera(500, 500, 60);//try to not change
	cam.transf = view_transform(
		ft_tuple(0, 0, -5, POINT),//from camera
		ft_tuple(0, 0, 0, POINT),//look at target
		ft_tuple(0, 1, 0, VECTOR));//up vector
	render(cam, w, &engine->image);
	mlx_put_image_to_window(engine->mlx, engine->window,
		engine->image.img_ptr, 0, 0);
	free_world(w);
	free_matrix(cam.transf);
}

/*(Eye-level View)
cam.transf = view_transform(
	ft_tuple(0, 0, -5, POINT),     // from: camera position
	ft_tuple(0, 0, 0, POINT),      // to: where camera is looking
	ft_tuple(0, 1, 0, VECTOR));    // up: camera's "up" direction

	(Top-down View)
	cam.transf = view_transform(
	ft_tuple(0, 10, 0, POINT),     // from: camera placed 10 units "above"
	ft_tuple(0, 0, 0, POINT),      // to: looking at the origin
	ft_tuple(0, 0, -1, VECTOR));   // up: z-axis now defines camera's "up"

	(from above and behind)
	cam.transf = view_transform(
	ft_tuple(5, 5, -5, POINT),     // camera up and back
	ft_tuple(0, 0, 0, POINT),      // looking at the center
	ft_tuple(0, 1, 0, VECTOR));    // standard up
	*/


void	init_engine_world(t_engine *engine)
{
	engine->mlx = mlx_init();
	if (!engine->mlx)
		error_message("MLX init failed", 1);
	engine->window = mlx_new_window(engine->mlx, WIDTH, HEIGHT, "Ray Tracer");
	if (!engine->window)
		error_message("Window creation failed", 1);
	engine->image.img_ptr = mlx_new_image(engine->mlx, WIDTH, HEIGHT);
	engine->image.addr_ptr = mlx_get_data_addr(engine->image.img_ptr,
		&engine->image.pixel_bits,
		&engine->image.line_len,
		&engine->image.endian);
}

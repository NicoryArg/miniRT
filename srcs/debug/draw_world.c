/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:09:53 by nryser            #+#    #+#             */
/*   Updated: 2025/04/11 17:09:53 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"

void	draw_world(t_engine *engine)
{
	t_world		*w;
	t_camera	cam;

	w = default_scene();
	cam = ft_camera(WIDTH, HEIGHT, M_PI / 3);
	cam.transf = view_transform(
		ft_tuple(0, 1.5, -5, POINT),
		ft_tuple(0, 1, 0, POINT),
		ft_tuple(0, 1, 0, VECTOR));

	render(cam, w, engine->image);
	mlx_put_image_to_window(engine->mlx, engine->window,
		engine->image.img_ptr, 0, 0);
	free_world(w);
	free_matrix(cam.transf);
}


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

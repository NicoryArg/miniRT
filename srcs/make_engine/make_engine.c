/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:45:51 by nryser            #+#    #+#             */
/*   Updated: 2025/04/18 18:46:05 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/engine.h"

int	on_key_hook_event(int key, t_engine *engine)
{
	if (key == KEY_ESC)
		on_destroy_event(engine);
	else if (key == KEY_H)
	{
		mlx_clear_window(engine->mlx, engine->window);
		//display_help_message(engine);
	}
	return (0);
}


void	init_engine(t_engine *engine)
{
	int	pixel_bits;
	int	line_len;
	int	endian;

	if (!engine)
		return ;
	engine->mlx = mlx_init();
	if (!engine->mlx)
		error_message("[MLX ERROR]: can't do mlx_init!\n", 1);
	engine->window = mlx_new_window(engine->mlx, WIN_SIZE, WIN_SIZE,
												"MiniRt project");
	engine->image.img_ptr = mlx_new_image(engine->mlx, WIN_SIZE, WIN_SIZE);
	if (!engine->window || !engine->image.img_ptr)
	{
		mlx_destroy_image(engine->mlx, engine->image.img_ptr);
		mlx_destroy_window(engine->mlx, engine->window);
		error_message("[MLX ERROR]: can't handle object creation!\n", 1);
	}
	engine->image.addr_ptr = mlx_get_data_addr(engine->image.img_ptr,
								&pixel_bits, &line_len, &endian);
	engine->image.pixel_bits = pixel_bits;
	engine->image.line_len = line_len;
	engine->image.endian = endian;
}

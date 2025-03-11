/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:52:44 by nryser            #+#    #+#             */
/*   Updated: 2025/03/11 19:52:44 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/engine.h"


void	error_message(char *text, int mode)
{
	if (mode == 0)
		perror(text);
	else if (text)
		ft_putstr_fd(text, 2);
	exit(EXIT_FAILURE);
}

//Initializes the engine with command-line arguments.
void	init_engine(t_engine *engine)
{
	int	pixel_bits;
	int	line_len;
	int	endian;

	if (!engine)
		return ;
	// reset_engine(engine, SPHERE);//TODO
	// set_shape_type(engine, arg);//TODO
	engine->mlx = mlx_init();
	if (!engine->mlx)
		error_message("[MLX ERROR]: can't do mlx_init!\n", 1);
	engine->window = mlx_new_window(engine->mlx, WIN_SIZE, WIN_SIZE, \
												"MiniRt project");
	engine->image.img_ptr = mlx_new_image(engine->mlx, WIN_SIZE, WIN_SIZE);
	if (!engine->window || !engine->image.img_ptr)
	{
		mlx_destroy_image(engine->mlx, engine->image.img_ptr);
		mlx_destroy_window(engine->mlx, engine->window);
		error_message("[MLX ERROR]: can't handle object creation!\n", 1);
	}
	engine->image.addr_ptr = mlx_get_data_addr(engine->image.img_ptr, \
								&pixel_bits, &line_len, &endian);
	engine->image.pixel_bits = pixel_bits;
	engine->image.line_len = line_len;
	engine->image.endian = endian;
	display_help_message(engine);
}

int	on_destroy_event(t_engine *engine)
{
	mlx_destroy_image(engine->mlx, engine->image.img_ptr);
	mlx_destroy_window(engine->mlx, engine->window);
	exit(EXIT_SUCCESS);
}



void	cleanup(t_engine *engine)
{
	if (engine->image.img_ptr)
	{
		printf("Destroying image\n");
		mlx_destroy_image(engine->mlx, engine->image.img_ptr);
		engine->image.img_ptr = NULL;
	}
	if (engine->window)
	{
		printf("Destroying window\n");
		mlx_destroy_window(engine->mlx, engine->window);
		engine->window = NULL;
	}
}

int	on_key_hook_event(int key, t_engine *engine)
{
	if (key == KEY_ESC)
		on_destroy_event(engine);
	else if (key == KEY_H)
	{
		mlx_clear_window(engine->mlx, engine->window);
		display_help_message(engine);
	}
	return (0);
}

void	display_help_message(t_engine *engine)
{
	int y = 20;

	mlx_string_put(engine->mlx, engine->window, 20, y, 0xFFFFFF, "MiniRT - Usage Guide");
	y += 30;
	mlx_string_put(engine->mlx, engine->window, 20, y, 0xFFFFFF, "Usage: ./miniRT <scene.rt>");
	y += 30;
	mlx_string_put(engine->mlx, engine->window, 20, y, 0xFFFFFF, "Example: ./miniRT scene.rt");
	y += 50;
	mlx_string_put(engine->mlx, engine->window, 20, y, 0xFFFFFF, "Ambient Light: A <ratio> <R,G,B>");
	y += 30;
	mlx_string_put(engine->mlx, engine->window, 20, y, 0xFFFFFF, "Camera: C <x,y,z> <dir_x,dir_y,dir_z> <FOV>");
	y += 30;
	mlx_string_put(engine->mlx, engine->window, 20, y, 0xFFFFFF, "Light: L <x,y,z> <brightness> <R,G,B>");
	y += 30;
	mlx_string_put(engine->mlx, engine->window, 20, y, 0xFFFFFF, "Sphere: sp <x,y,z> <diameter> <R,G,B>");
	y += 30;
	mlx_string_put(engine->mlx, engine->window, 20, y, 0xFFFFFF, "Plane: pl <x,y,z> <norm_x,norm_y,norm_z> <R,G,B>");
	y += 30;
	mlx_string_put(engine->mlx, engine->window, 20, y, 0xFFFFFF, "Cylinder: cy <x,y,z> <axis_x,axis_y,axis_z> <diameter> <height> <R,G,B>");
	y += 50;
	mlx_string_put(engine->mlx, engine->window, 20, y, 0xFFFFFF, "Press ESC to close the window.");
}

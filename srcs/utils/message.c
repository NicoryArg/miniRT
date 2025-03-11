/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:53:03 by nryser            #+#    #+#             */
/*   Updated: 2025/03/11 19:53:03 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"

// void	display_help_message(t_engine *engine)
// {
// 	int y = 20;

// 	mlx_string_put(engine->mlx, engine->window, 20, y, 0xFFFFFF, "MiniRT - Usage Guide");
// 	y += 30;
// 	mlx_string_put(engine->mlx, engine->window, 20, y, 0xFFFFFF, "Usage: ./miniRT <scene.rt>");
// 	y += 30;
// 	mlx_string_put(engine->mlx, engine->window, 20, y, 0xFFFFFF, "Example: ./miniRT scene.rt");
// 	y += 50;
// 	mlx_string_put(engine->mlx, engine->window, 20, y, 0xFFFFFF, "Ambient Light: A <ratio> <R,G,B>");
// 	y += 30;
// 	mlx_string_put(engine->mlx, engine->window, 20, y, 0xFFFFFF, "Camera: C <x,y,z> <dir_x,dir_y,dir_z> <FOV>");
// 	y += 30;
// 	mlx_string_put(engine->mlx, engine->window, 20, y, 0xFFFFFF, "Light: L <x,y,z> <brightness> <R,G,B>");
// 	y += 30;
// 	mlx_string_put(engine->mlx, engine->window, 20, y, 0xFFFFFF, "Sphere: sp <x,y,z> <diameter> <R,G,B>");
// 	y += 30;
// 	mlx_string_put(engine->mlx, engine->window, 20, y, 0xFFFFFF, "Plane: pl <x,y,z> <norm_x,norm_y,norm_z> <R,G,B>");
// 	y += 30;
// 	mlx_string_put(engine->mlx, engine->window, 20, y, 0xFFFFFF, "Cylinder: cy <x,y,z> <axis_x,axis_y,axis_z> <diameter> <height> <R,G,B>");
// 	y += 50;
// 	mlx_string_put(engine->mlx, engine->window, 20, y, 0xFFFFFF, "Press ESC to close the window.");
// }

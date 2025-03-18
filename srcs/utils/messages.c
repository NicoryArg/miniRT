/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:13:11 by nryser            #+#    #+#             */
/*   Updated: 2025/03/18 20:13:11 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/engine.h"

void	put_help_text(t_engine *engine, int *y, char *text)
{
	mlx_string_put(engine->mlx, engine->window, 20, *y, 0xFFFFFF, text);
	*y += 30;
}

void	display_help_message(t_engine *engine)
{
	int	y;

	y = 20;
	put_help_text(engine, &y, "MiniRT - Usage Guide");
	y += 10;
	put_help_text(engine, &y, "Usage: ./miniRT <scene.rt>");
	put_help_text(engine, &y, "Example: ./miniRT scene.rt");
	y += 20;
	put_help_text(engine, &y, "Ambient Light: A <ratio> <R,G,B>");
	put_help_text(engine, &y, "Camera: C <x,y,z> <dir_x,dir_y,dir_z> <FOV>");
	put_help_text(engine, &y, "Light: L <x,y,z> <brightness> <R,G,B>");
	put_help_text(engine, &y, "Sphere: sp <x,y,z> <diameter> <R,G,B>");
	put_help_text(engine, &y, "Plane: pl <x,y,z> <norm_x,norm_y,norm_z> <R,G,B>");
	put_help_text(engine, &y, "Cylinder: cy <x,y,z> <axis_x,axis_y,axis_z> <diameter> <height> <R,G,B>");
	y += 20;
	put_help_text(engine, &y, "Press ESC to close the window.");
}

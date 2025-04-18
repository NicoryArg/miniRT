/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:16:11 by nryser            #+#    #+#             */
/*   Updated: 2025/04/18 19:16:11 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"
#include "engine.h"

static void	draw_circle_loop(t_image *img, int cx, int cy, int r, int color)
{
	int	x;
	int	y;

	y = -r;
	while (y <= r)
	{
		x = -r;
		while (x <= r)
		{
			if (x * x + y * y <= r * r)
				put_pixel(img, cx + x, cy + y, color);
			x++;
		}
		y++;
	}
}

void	draw_circle_scene(t_engine *engine)
{
	int	cx;
	int	cy;
	int	r;

	cx = WIN_SIZE / 2;
	cy = WIN_SIZE / 2;
	r = WIN_SIZE / 5;
	draw_circle_loop(&engine->image, cx, cy, r, RED);
}

int	draw_circle(int run)
{
	if (run == 0)
		return (0);
	return (1);
}

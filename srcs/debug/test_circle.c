/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:31:33 by nryser            #+#    #+#             */
/*   Updated: 2025/03/18 19:31:37 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"

void	draw_circle(t_image *img, int center_x, int center_y, int radius, int color)
{
	int x, y;

	for (y = -radius; y <= radius; y++)
	{
		for (x = -radius; x <= radius; x++)
		{
			if (x * x + y * y <= radius * radius) // Circle equation
				put_pixel(img, center_x + x, center_y + y, color);
		}
	}
}

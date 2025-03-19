/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:08:56 by nryser            #+#    #+#             */
/*   Updated: 2025/03/18 20:08:56 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/engine.h"

void	put_pixel(t_image *img, int x, int y, int color)
{
	if (x >= 0 && x < WIN_SIZE && y >= 0 && y < WIN_SIZE) // Bounds check
	{
		char	*pixel;
		pixel = img->addr_ptr + (y * img->line_len + x * (img->pixel_bits / 8));
		*(unsigned int *)pixel = color;
	}
}

void	draw_marker(t_image *img, int x, int y, int color, int marker_size)
{
	int	i;
	int	j;

	i = -marker_size / 2;
	while (i <= marker_size / 2)
	{
		j = -marker_size / 2;
		while (j <= marker_size / 2)
		{
			put_pixel(img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

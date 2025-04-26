/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 08:59:07 by nryser            #+#    #+#             */
/*   Updated: 2025/04/26 08:59:07 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/engine.h"

void	put_pixel(t_image *img, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < WIN_SIZE && y >= 0 && y < WIN_SIZE)
	{
		pixel = img->addr_ptr + (y * img->line_len + x * (img->pixel_bits / 8));
		*(unsigned int *)pixel = color;
	}
}

//function for debug * comment it out after//
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

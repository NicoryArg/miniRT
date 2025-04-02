/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:36:09 by nryser            #+#    #+#             */
/*   Updated: 2025/04/02 12:42:10 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"

void	ft_swap(t_hit **a, t_hit **b)
{
	t_hit	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

double	ft_max(double a, double b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

double	ft_min(double a, double b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

/**
 * Converts a t_colour (with float RGB values in range [0.0, 1.0])
 * into a 24-bit packed integer in 0xRRGGBB format.
 *
 * Steps:
 * 1. Each component (r, g, b) is
 *  multiplied by 255 to scale from [0,0–1,0] to [0–255].
 * 2. Values are clamped to stay within 0–255.
 * 3. Components are shifted into their proper byte positions:
 *      - Red   << 16 (high byte)
 *      - Green << 8  (middle byte)
 *      - Blue       (low byte)
 * 4. The final integer is returned as: 0xRRGGBB.
 * Example:
 * colour(1.0, 0.5, 0.25) → (255, 128, 64)
 * → (255 << 16 | 128 << 8 | 64) = 0xFF8040 = 16744448
 * because:   16711680  // red
 *          +    32768 // green
 *          +       64 // blue
 *           ---------
 *          = 16744448
 */
int	convert_colour_to_int(t_colour col)
{
	int	r;
	int	g;
	int	b;

	r = ft_min(ft_max(col.r * 255, 0), 255);
	g = ft_min(ft_max(col.g * 255, 0), 255);
	b = ft_min(ft_max(col.b * 255, 0), 255);
	return (r << 16 | g << 8 | b);
}

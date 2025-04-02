/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:32:49 by nryser            #+#    #+#             */
/*   Updated: 2025/04/02 14:32:49 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_colour	ft_colour(double r, double g, double b)
{
	t_colour	c;

	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
}

t_colour	add_colours(t_colour	a, t_colour b)
{
	t_colour	new;

	new.r = a.r + b.r;
	new.g = a.g + b.g;
	new.b = a.b + b.b;
	return (new);
}

t_colour	mult_colour(t_colour c, double num)
{
	t_colour	new;
	new.r = c.r * num;
	new.g = c.g * num;
	new.b = c.b * num;
	return (new);
}
t_colour	mult_colours(t_colour c1, t_colour c2)
{
	t_colour	new;

	new.r = c1.r * c2.r;
	new.g = c1.g * c2.g;
	new.b = c1.b * c2.b;
	return (new);
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

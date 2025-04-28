/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_mapping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:40:44 by nryser            #+#    #+#             */
/*   Updated: 2025/04/20 15:40:44 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"

/**
 * @brief Maps a point on a sphere to UV coordinates.
 *
 * The UV coordinates wrap around like a world globe:
 * - U goes from 0 to 1 horizontally (longitude)
 * - V goes from 0 to 1 vertically (latitude)
 *
 * @param point A point on the surface of a sphere (in object space).
 * @return A t_uv struct with u and v in [0,1] (longitude, latitude).
 */
t_uv	uv_spherical(t_tuple point)
{
	double	theta;
	double	radius;
	double	phi;
	t_uv	uv;

	theta = atan2(point.x, point.z);
	radius = sqrt(point.x * point.x + point.y * point.y + point.z * point.z);
	phi = acos(point.y / radius);
	uv.u = 1.0 - (theta + M_PI) / (2 * M_PI);
	uv.v = 1.0 - phi / M_PI;
	return (uv);
}

/**
 * @brief Returns the color at a UV coordinate from a checkerboard pattern.
 *
 * The checkerboard is split into `width` x `height` tiles.
 * The color alternates based on the tile indices at that UV coordinate.
 *
 * @param pattern The checker pattern with width and height defined.
 * @param uv The UV coordinate in [0,1].
 * @return Either color A or B depending on parity of the tile indices.
 */
t_colour	uv_checkers_at(t_pattern *pattern, t_uv uv)
{
	int	width;
	int	height;
	int	u_index;
	int	v_index;

	width = pattern->width;
	if (width <= 0)
		width = 8;
	height = pattern->height;
	if (height <= 0)
		height = 8;
	u_index = fmin(width - 1, (int)(uv.u * width));
	v_index = fmin(height - 1, (int)(uv.v * height));
	if ((u_index + v_index) % 2 == 0)
		return (pattern->a);
	else
		return (pattern->b);
}

/**
 * @brief Returns color from a UV-based stripe pattern.
 *
 * Stripes run vertically in UV space, alternating between color A and B
 * based on horizontal `u` position.
 *
 * @param pattern The stripe pattern with `width` controlling stripe count.
 * @param uv The UV coordinate.
 * @return The alternating stripe color at the UV coordinate.
 */
t_colour	uv_stripe_at(t_pattern *pattern, t_uv uv)
{
	int	width;
	int	u_index;

	width = pattern->width;
	if (width <= 0)
		width = 10;
	u_index = fmin(width - 1, (int)(uv.u * width));
	if (u_index % 2 == 0)
		return (pattern->a);
	else
		return (pattern->b);
}

/**
 * @brief Returns a smooth gradient between two colors across U.
 *
 * @param pattern The gradient pattern (colors A to B).
 * @param uv The UV coordinate.
 * @return Interpolated color from A to B along U axis.
 *
 * This produces a continuous blend from color A (left) to B (right).
 */
t_colour	uv_gradient_at(t_pattern *pattern, t_uv uv)
{
	t_colour	distance;
	double		fraction;

	distance = diff_colours(pattern->b, pattern->a);
	fraction = uv.u;
	return (add_colours(pattern->a, mult_colour(distance, fraction)));
}

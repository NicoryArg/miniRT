/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_patterns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 17:01:49 by nryser            #+#    #+#             */
/*   Updated: 2025/04/20 17:11:29 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"

/**
 * @brief Creates a stripe pattern alternating between two colors.
 *
 * @param a The first color of the stripe pattern.
 * @param b The second color of the stripe pattern.
 * @return A t_pattern struct with type STRIPE and identity transform.
 *
 * The frequency field is initialized to 10.0 and determines how many
 * stripes appear per unit distance along the x-axis.
 */
t_pattern	stripe_pattern(t_colour a, t_colour b)
{
	t_pattern	p;

	p.type = PATTERN_STRIPE;
	p.a = a;
	p.b = b;
	p.a_pattern = NULL;
	p.b_pattern = NULL;
	p.transform = create_identity_matrix(4);
	p.frequency = 10.0;
	return (p);
}

/**
 * @brief Returns the color of a stripe pattern at a given point.
 *
 * @param pattern The pattern containing stripe colors and frequency.
 * @param point A point in pattern space.
 * @return Color A or B depending on the x-position.
 *
 * The pattern alternates between color A
 *  and B every 1/frequency units along the x-axis.
 */
t_colour	stripe_at(t_pattern *pattern, t_tuple point)
{
	double	freq;
	int		stripe_index;

	if (pattern->frequency > 0)
		freq = pattern->frequency;
	else
		freq = 1.0;
	stripe_index = (int)floor(point.x * freq);
	if (stripe_index % 2 == 0)
	{
		if (pattern->a_pattern)
			return (pattern_colour_at(pattern->a_pattern, point));
		return (pattern->a);
	}
	else
	{
		if (pattern->b_pattern)
			return (pattern_colour_at(pattern->b_pattern, point));
		return (pattern->b);
	}
}



/**
 * @brief Returns a gradient color between two base colors.
 *
 * @param pattern The gradient pattern.
 * @param point The point in pattern space.
 * @return A blended color between pattern->a and pattern->b based on x-position.
 *
 * The interpolation occurs between floor(x) and x, blending proportionally.
 * Frequency is not used in this pattern.
 */
t_colour	gradient_at(t_pattern *pattern, t_tuple point)
{
	t_colour	distance;
	double		fraction;

	distance = diff_colours(pattern->b, pattern->a);
	fraction = point.x - floor(point.x);
	return (add_colours(pattern->a, mult_colour(distance, fraction)));
}

/**
 * @brief Returns the color of a ring pattern at a given point.
 *
 * @param pattern The pattern with colors and frequency.
 * @param point A point in pattern space (typically object-local space).
 * @return Color A or B depending on the ring index.
 *
 * This pattern creates concentric rings (circles) using
 * the distance from the origin
 * in the XZ plane. The frequency determines how many rings
 * appear per unit of distance.
 *
 * ring_offset is a small value added to avoid the center always
 * rendering as a solid color.
 * frequency controls the number of rings per unit — higher = more
 * tightly packed rings.
 */
t_colour	ring_at(t_pattern *pattern, t_tuple point)
{
	double		dist;
	int			ring_index;
	double		ring_offset;
	double		freq;

	ring_offset = 0.01;
	if (pattern->frequency > 0)
		freq = pattern->frequency;
	else
		freq = 12.0;
	dist = sqrt(point.x * point.x + point.z * point.z);
	dist += ring_offset;
	ring_index = (int)floor(dist * freq);
	if (ring_index % 2 == 0)
	{
		if (pattern->a_pattern)
			return (pattern_colour_at(pattern->a_pattern, point));
		return (pattern->a);
	}
	else
	{
		if (pattern->b_pattern)
			return (pattern_colour_at(pattern->b_pattern, point));
		return (pattern->b);
	}
}

/**
 * @brief Returns the color for a 3D checkers pattern at a given point.
 *
 * @param pattern The pattern with two alternating colors.
 * @param point The point in pattern space.
 * @return Color A or B depending on the parity of the integer position sum.
 *
 * This pattern alternates color on every integer step in X, Y, or Z,
 * producing a 3D checkerboard effect. Frequency is not used.
 */
t_colour	checkers_at(t_pattern *pattern, t_tuple point)
{
	int			sum;
	double		freq;

	if (pattern->frequency > 0)
		freq = pattern->frequency;
	else
		freq = 1.0;
	sum = (int)(floor(point.x * freq)
			+ floor(point.y * freq)
			+ floor(point.z * freq));
	if (sum % 2 == 0)
	{
		if (pattern->a_pattern)
			return (pattern_colour_at(pattern->a_pattern, point));
		return (pattern->a);
	}
	else
	{
		if (pattern->b_pattern)
			return (pattern_colour_at(pattern->b_pattern, point));
		return (pattern->b);
	}
}

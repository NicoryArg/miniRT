/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_patterns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:22:53 by nryser            #+#    #+#             */
/*   Updated: 2025/04/19 15:22:59 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"

/**
 * @brief Creates a stripe pattern between two colors.
 *
 * The pattern initially uses an identity transform.
 */
t_pattern	stripe_pattern(t_colour a, t_colour b)
{
	t_pattern	p;

	p.type = PATTERN_STRIPE;
	p.a = a;
	p.b = b;
	p.transform = create_identity_matrix(4);
	return (p);
}

/**
 * @brief Determines the color at a specific point for a stripe pattern.
 *
 * Alternates between color a and b based on the floor of x-coordinate.
 */
t_colour	stripe_at(t_pattern *pattern, t_tuple point)
{
	if ((int)ft_floor(point.x) % 2 == 0)
		return (pattern->a);
	else
		return (pattern->b);
}

t_colour	gradient_at(t_pattern *pattern, t_tuple point)
{
	t_colour	distance;
	double		fraction;

	distance = diff_colours(pattern->b, pattern->a);
	fraction = point.x - ft_floor(point.x);
	return (add_colours(pattern->a, mult_colour(distance, fraction)));
}

t_colour	ring_at(t_pattern *pattern, t_tuple point)
{
	double	dist;

	dist = sqrt(point.x * point.x + point.z * point.z);
	if ((int)ft_floor(dist) % 2 == 0)
		return (pattern->a);
	else
		return (pattern->b);
}

t_colour	checkers_at(t_pattern *pattern, t_tuple point)
{
	int sum = (int)(ft_floor(point.x) + ft_floor(point.y) + ft_floor(point.z));

	if (sum % 2 == 0)
		return pattern->a;
	else
		return pattern->b;
}


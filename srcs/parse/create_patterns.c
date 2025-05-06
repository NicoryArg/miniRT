/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_patterns.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 21:10:02 by nryser            #+#    #+#             */
/*   Updated: 2025/05/06 21:10:57 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

static t_colour	secondary_colour(t_colour c)
{
	return (ft_colour(c.r * 0.5, c.g * 0.5, c.b * 0.5));
}

t_pattern *create_pattern_for_sphere(int type, t_colour base)
{
	t_colour alt = secondary_colour(base);
	t_pattern *pat = malloc(sizeof(t_pattern));
	if (!pat)
		return (NULL);

	if (type == PATTERN_STRIPE)
		*pat = stripe_pattern(base, alt), pat->frequency = 10.0;
	else if (type == PATTERN_GRADIENT)
		*pat = gradient_pattern(base, alt), pat->frequency = 4.0;
	else if (type == PATTERN_RING)
		*pat = ring_pattern(base, alt), pat->frequency = 12.0;
	else if (type == PATTERN_CHECKERS)
		*pat = checkers_pattern(base, alt), pat->frequency = 1.0;
	else if (type == PATTERN_UV_STRIPE)
		*pat = uv_stripe_pattern(base, alt, 10, 1);
	else if (type == PATTERN_UV_GRADIENT)
		*pat = uv_gradient_pattern(base, alt, 0, 0);
	else if (type == PATTERN_UV_CHECKERS)
		*pat = uv_checkers_pattern(base, alt, 8, 8);
	else
		return (free(pat), NULL);
	return (pat);
}

t_pattern *create_pattern_for_plane(int type, t_colour base)
{
	t_colour alt = secondary_colour(base);
	t_pattern *pat = malloc(sizeof(t_pattern));
	if (!pat)
		return (NULL);

	if (type == PATTERN_STRIPE)
		*pat = stripe_pattern(base, alt), pat->frequency = 3.0;
	else if (type == PATTERN_GRADIENT)
		*pat = gradient_pattern(base, alt), pat->frequency = 2.0;
	else if (type == PATTERN_RING)
		*pat = ring_pattern(base, alt), pat->frequency = 4.0;
	else if (type == PATTERN_CHECKERS)
		*pat = checkers_pattern(base, alt), pat->frequency = 0.5;
	else if (type == PATTERN_UV_STRIPE)
		*pat = uv_stripe_pattern(base, alt, 4, 1);
	else if (type == PATTERN_UV_GRADIENT)
		*pat = uv_gradient_pattern(base, alt, 0, 0);
	else if (type == PATTERN_UV_CHECKERS)
		*pat = uv_checkers_pattern(base, alt, 4, 4);
	else
		return (free(pat), NULL);
	return (pat);
}

t_pattern *create_pattern_for_cylinder(int type, t_colour base)
{
	t_colour alt = secondary_colour(base);
	t_pattern *pat = malloc(sizeof(t_pattern));
	if (!pat)
		return (NULL);

	if (type == PATTERN_STRIPE)
		*pat = stripe_pattern(base, alt), pat->frequency = 15.0;
	else if (type == PATTERN_GRADIENT)
		*pat = gradient_pattern(base, alt), pat->frequency = 5.0;
	else if (type == PATTERN_RING)
		*pat = ring_pattern(base, alt), pat->frequency = 8.0;
	else if (type == PATTERN_CHECKERS)
		*pat = checkers_pattern(base, alt), pat->frequency = 1.0;
	else if (type == PATTERN_UV_STRIPE)
		*pat = uv_stripe_pattern(base, alt, 12, 1);
	else if (type == PATTERN_UV_GRADIENT)
		*pat = uv_gradient_pattern(base, alt, 0, 0);
	else if (type == PATTERN_UV_CHECKERS)
		*pat = uv_checkers_pattern(base, alt, 12, 6);
	else
		return (free(pat), NULL);
	return (pat);
}

t_pattern *create_pattern_for_cone(int type, t_colour base)
{
	t_colour alt = secondary_colour(base);
	t_pattern *pat = malloc(sizeof(t_pattern));
	if (!pat)
		return (NULL);

	if (type == PATTERN_STRIPE)
		*pat = stripe_pattern(base, alt), pat->frequency = 20.0;
	else if (type == PATTERN_GRADIENT)
		*pat = gradient_pattern(base, alt), pat->frequency = 6.0;
	else if (type == PATTERN_RING)
		*pat = ring_pattern(base, alt), pat->frequency = 14.0;
	else if (type == PATTERN_CHECKERS)
		*pat = checkers_pattern(base, alt), pat->frequency = 1.5;
	else if (type == PATTERN_UV_STRIPE)
		*pat = uv_stripe_pattern(base, alt, 10, 1);
	else if (type == PATTERN_UV_GRADIENT)
		*pat = uv_gradient_pattern(base, alt, 0, 0);
	else if (type == PATTERN_UV_CHECKERS)
		*pat = uv_checkers_pattern(base, alt, 50, 50);
	else
		return (free(pat), NULL);
	return (pat);
}


t_pattern *create_pattern_by_type(int type, t_colour base, int shape_type)
{
	if (shape_type == SHAPE_PLANE)
		return (create_pattern_for_plane(type, base));
	else if (shape_type == SHAPE_CYLINDER)
		return (create_pattern_for_cylinder(type, base));
	else if (shape_type == SHAPE_CONE)
		return (create_pattern_for_cone(type, base));
	else
		return (create_pattern_for_sphere(type, base));
}

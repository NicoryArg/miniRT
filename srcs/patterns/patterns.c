/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:12:27 by nryser            #+#    #+#             */
/*   Updated: 2025/04/18 16:12:38 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	ft_floor(double x)
{
	int		i;
	double	result;

	i = (int)x;
	if (x >= 0)
		result = (double)i;
	else
	{
		if (x == (double)i)
			result = (double)i;
		else
			result = (double)(i - 1);
	}
	return (result);
}

t_pattern	stripe_pattern(t_colour a, t_colour b)
{
	t_pattern	p;

	p.type = PATTERN_STRIPE;
	p.a = a;
	p.b = b;
	p.transform = create_identity_matrix(4);
	return (p);
}


t_colour	stripe_at(t_pattern *pattern, t_tuple point)
{
	if ((int)ft_floor(point.x) % 2 == 0)
		return (pattern->a);
	else
		return (pattern->b);
}

t_colour	stripe_at_object(t_pattern *pattern, t_object *object, t_tuple world_point)
{
	t_matrix	*object_inverse;
	t_matrix	*pattern_inverse;
	t_tuple		object_point;
	t_tuple		pattern_point;
	t_colour	result;

	object_inverse = invert_matrix(object->transf);
	object_point = matrix_to_tuple(multiply_matrices(object_inverse, tuple_to_matrix(world_point)));
	pattern_inverse = invert_matrix(pattern->transform);
	pattern_point = matrix_to_tuple(multiply_matrices(pattern_inverse, tuple_to_matrix(object_point)));
	result = stripe_at(pattern, pattern_point);
	free_matrix(object_inverse);
	free_matrix(pattern_inverse);
	return (result);
}
t_colour	test_pattern_at(t_pattern *pattern, t_tuple point)
{
	(void)pattern;
	return (ft_colour(point.x, point.y, point.z));
}

t_pattern	test_pattern(void)
{
	t_pattern	p;

	p.type = 99; // or make a PATTERN_TEST constant
	p.a = ft_colour(0, 0, 0); // unused
	p.b = ft_colour(0, 0, 0); // unused
	p.transform = create_identity_matrix(4);
	return (p);
}

t_colour	pattern_at_object(t_pattern *pattern, t_object *object, t_tuple world_point)
{
	t_matrix	*object_inverse;
	t_matrix	*pattern_inverse;
	t_tuple		object_point;
	t_tuple		pattern_point;
	t_colour	result;

	object_inverse = invert_matrix(object->transf);
	object_point = matrix_to_tuple(multiply_matrices(object_inverse, tuple_to_matrix(world_point)));
	pattern_inverse = invert_matrix(pattern->transform);
	pattern_point = matrix_to_tuple(multiply_matrices(pattern_inverse, tuple_to_matrix(object_point)));
	if (pattern->type == PATTERN_STRIPE)
		result = stripe_at(pattern, pattern_point);
	else if (pattern->type == 99) // test pattern
		result = test_pattern_at(pattern, pattern_point);
	// later: else if (pattern->type == PATTERN_GRADIENT) ...
	else
		result = ft_colour(0, 0, 0); // fallback
	free_matrix(object_inverse);
	free_matrix(pattern_inverse);
	return (result);
}

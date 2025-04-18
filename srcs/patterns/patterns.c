/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 23:01:34 by nryser            #+#    #+#             */
/*   Updated: 2025/04/18 23:01:56 by nryser           ###   ########.ch       */
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

static t_tuple	transform_world_to_object(t_tuple world_point, t_matrix *inverse)
{
	t_matrix	*wm;
	t_matrix	*rm;
	t_tuple		result;

	wm = tuple_to_matrix(world_point);
	rm = multiply_matrices(inverse, wm);
	result = matrix_to_tuple(rm);
	free_matrix(wm);
	free_matrix(rm);
	return (result);
}

static t_tuple	transform_object_to_pattern(t_tuple object_point, t_matrix *inverse)
{
	t_matrix	*objm;
	t_matrix	*resm;
	t_tuple		result;

	objm = tuple_to_matrix(object_point);
	resm = multiply_matrices(inverse, objm);
	result = matrix_to_tuple(resm);
	free_matrix(objm);
	free_matrix(resm);
	return (result);
}

t_colour	pattern_at_object(t_pattern *pattern, t_object *object, t_tuple world_point)
{
	t_matrix	*object_inv;
	t_matrix	*pattern_inv;
	t_tuple		object_point;
	t_tuple		pattern_point;

	if (!pattern || !pattern->transform || !object || !object->transf)
	{
		printf(AKA"❌ ERROR: invalid object or pattern\n"RES);
		exit(1);
	}
	object_inv = invert_matrix(object->transf);
	object_point = transform_world_to_object(world_point, object_inv);
	free_matrix(object_inv);

	pattern_inv = invert_matrix(pattern->transform);
	pattern_point = transform_object_to_pattern(object_point, pattern_inv);
	free_matrix(pattern_inv);

	if (pattern->type == PATTERN_STRIPE)
		return (stripe_at(pattern, pattern_point));
	if (pattern->type == 99)
		return (test_pattern_at(pattern, pattern_point));
	return (ft_colour(0, 0, 0));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 00:14:21 by nryser            #+#    #+#             */
/*   Updated: 2025/04/19 00:21:16 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/**
 * @brief Returns the largest integer less than or equal to x.
 *
 * Handles both positive and negative values, simulating math-style floor behavior.
 */
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

/**
 * @brief Calculates the pattern color at a world-space point on a given object.
 *
 * Transforms the point from world space → object space → pattern space.
 */
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

/**
 * @brief A pattern used for testing: maps x/y/z to RGB.
 *
 * This helps visualize coordinates on surfaces.
 */
t_colour	test_pattern_at(t_pattern *pattern, t_tuple point)
{
	(void)pattern;
	return (ft_colour(point.x, point.y, point.z));
}

/**
 * @brief Creates a basic test pattern.
 *
 * Type is set to 99 for test identification. Colors are unused.
 */
t_pattern	test_pattern(void)
{
	t_pattern	p;

	p.type = 99; // or make a PATTERN_TEST constant
	p.a = ft_colour(0, 0, 0); // unused
	p.b = ft_colour(0, 0, 0); // unused
	p.transform = create_identity_matrix(4);
	return (p);
}

/**
 * @brief Transforms a world point to object space using the inverse transform.
 */
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

/**
 * @brief Transforms a point from object space to pattern space.
 */
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

/**
 * @brief Computes the color at a world-space point using an object's pattern.
 *
 * Transforms the point from world space to object space, then to pattern space,
 * and applies the pattern function (e.g., stripes or test) at that point.
 * Exits if the object or pattern is invalid.
 * @param pattern The pattern applied to the object.
 * @param object The object receiving the pattern.
 * @param world_point The point in world coordinates to evaluate.
 * @return The resulting color from the pattern.
 */
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

/*
✅ Implemented:

t_pattern struct with type, colors a and b, and transform matrix.
stripe_pattern() for creating default stripe patterns with identity transform.
stripe_at() to return color a or b based on the floor of point.x.
test_pattern_at() for debugging, returning point.x/y/z as RGB color.
pattern_at_object():
Converts a world_point → object space → pattern space.
Applies pattern based on final point.
Added helper functions:
transform_world_to_object()
transform_object_to_pattern()
⚠️ Fixed Issues:
Memory leaks due to missing free_matrix() calls.
Segfaults from accessing uninitialized or invalid pattern/transform pointers.
Uninitialized values in shade_hit() → fixed by always setting valid t_hit->obj.
Ensured pattern->transform is initialized using create_identity_matrix() or a valid scale/rotate.
💡 Design Notes:
Each object gets its own dynamically allocated pattern with a unique transform.
Patterns are modular — different colors and angles applied per object.
Stripe density is controlled by scale(x, y, z) — smaller scale = denser stripes.
Pattern logic is handled after object/world transforms, allowing flexible appearance.
Patterns are optional: if no pattern is set, fallback to object’s base color.
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_patterns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:40:00 by nryser            #+#    #+#             */
/*   Updated: 2025/04/23 16:44:48 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"
#include "engine.h"
#include "tests.h"

int	stripe_pattern_test(int run)
{
	if (run == 0)
		return (0);

	int			i;
	t_pattern	p;
	t_tuple		pt;
	t_colour	expected;
	t_colour	actual;

	i = 1;
	print_test_banner("Stripe pattern is constant in Y");
	print_test_number(&i);

	p.type = PATTERN_STRIPE;
	p.a = ft_colour(1, 1, 1);
	p.b = ft_colour(0, 0, 0);
	p.transform = create_identity_matrix(4);

	// Helper macro
	#define TEST_STRIPE_AT(x, y, z, exp_col, label) { \
		pt = ft_tuple((double)(x), (double)(y), (double)(z), POINT); \
		expected = exp_col; \
		actual = stripe_at(&p, pt, NULL); \
		printf("→ %s at point (%.1f, %.1f, %.1f)\n", label, (double)(x), (double)(y), (double)(z)); \
		printf("Expected: (%.1f, %.1f, %.1f)\n", expected.r, expected.g, expected.b); \
		printf("Actual:   (%.1f, %.1f, %.1f)\n", actual.r, actual.g, actual.b); \
		if (equal_colour(actual, expected)) \
			printf(GR"✔ Passed\n\n"RES); \
		else \
			return (printf(AKA"❌ Failed\n\n"RES)); \
	}


	// Constant in Y
	TEST_STRIPE_AT(0, 0, 0, p.a, "Constant Y");
	TEST_STRIPE_AT(0, 1, 0, p.a, "Constant Y");
	TEST_STRIPE_AT(0, 2, 0, p.a, "Constant Y");

	print_test_banner("Stripe pattern is constant in Z");
	print_test_number(&i);

	// Constant in Z
	TEST_STRIPE_AT(0, 0, 0, p.a, "Constant Z");
	TEST_STRIPE_AT(0, 0, 1, p.a, "Constant Z");
	TEST_STRIPE_AT(0, 0, 2, p.a, "Constant Z");

	print_test_banner("Stripe pattern alternates in X");
	print_test_number(&i);

	// Alternates in X
	TEST_STRIPE_AT(0, 0, 0, p.a, "Stripe X");
	TEST_STRIPE_AT(0.9, 0, 0, p.a, "Stripe X");
	TEST_STRIPE_AT(1.0, 0, 0, p.b, "Stripe X");
	TEST_STRIPE_AT(-0.1, 0, 0, p.b, "Stripe X");
	TEST_STRIPE_AT(-1.0, 0, 0, p.b, "Stripe X");
	TEST_STRIPE_AT(-1.1, 0, 0, p.a, "Stripe X");

	printf(G_B"✔ All stripe pattern tests passed\n"RES);
	free_matrix(p.transform);
	return (0);
}


int	pattern_lighting_test(int run)
{
	if (run == 0)
		return (0);

	int			i;
	t_material	m;
	t_pattern	pattern;
	t_tuple		eyev;
	t_tuple		normalv;
	t_tuple		point;
	t_light		*light;
	t_colour	expected;
	t_colour	actual;
	t_shading	L;

	i = 1;
	print_test_banner("Lighting with a pattern applied");
	print_test_number(&i);

	// Setup pattern
	pattern.type = PATTERN_STRIPE;
	pattern.a = ft_colour(1, 1, 1); // white
	pattern.b = ft_colour(0, 0, 0); // black
	pattern.transform = create_identity_matrix(4);

	// Setup material
	m.c = ft_colour(1, 1, 1); // will be overridden by pattern
	m.ambient = 1.0;
	m.diffuse = 0.0;
	m.specular = 0.0;
	m.shininess = 0.0;
	m.pattern = &pattern;

	// Common vectors and light
	eyev = ft_tuple(0, 0, -1, VECTOR);
	normalv = ft_tuple(0, 0, -1, VECTOR);
	light = ft_light(ft_tuple(0, 0, -10, POINT), ft_colour(1, 1, 1), 1.0);

	// Test point 0.9 → should be white
	point = ft_tuple(0.9, 0, 0, POINT);
	L.m = m;
	L.l = light;
	L.point = point;
	L.eyev = eyev;
	L.normalv = normalv;
	actual = ft_shading(L, false);
	expected = ft_colour(1, 1, 1);

	printf("Point: (%.1f, %.1f, %.1f)\n", point.x, point.y, point.z);
	printf("Expected: (%.1f, %.1f, %.1f)\n", expected.r, expected.g, expected.b);
	printf("Actual:   (%.1f, %.1f, %.1f)\n", actual.r, actual.g, actual.b);
	if (equal_colour(actual, expected))
		printf(GR"✔ Lighting is correct at point 0.9 (white stripe)\n\n"RES);
	else
		return (printf(AKA"❌ Lighting failed at point 0.9\n\n"RES));

	// Test point 1.1 → should be black
	point = ft_tuple(1.1, 0, 0, POINT);
	L.point = point;
	actual = ft_shading(L, false);
	expected = ft_colour(0, 0, 0);

	printf("Point: (%.1f, %.1f, %.1f)\n", point.x, point.y, point.z);
	printf("Expected: (%.1f, %.1f, %.1f)\n", expected.r, expected.g, expected.b);
	printf("Actual:   (%.1f, %.1f, %.1f)\n", actual.r, actual.g, actual.b);
	if (equal_colour(actual, expected))
		printf(GR"✔ Lighting is correct at point 1.1 (black stripe)\n"RES);
	else
		return (printf(AKA"❌ Lighting failed at point 1.1\n"RES));

	free(light);
	free_matrix(pattern.transform);
	return (0);
}

int	stripe_transform_test(int run)
{
	if (run == 0)
		return (0);

	int			i;
	t_pattern	pattern;
	t_sphere	*s;
	t_tuple		world_point;
	t_colour	expected;
	t_colour	actual;

	i = 1;
	print_test_banner("Stripes with object transformation");
	print_test_number(&i);

	s = ft_sphere(1);
	pattern = stripe_pattern(ft_colour(1, 1, 1), ft_colour(0, 0, 0));
	set_transf(s, scale(2, 2, 2));

	world_point = ft_tuple(1.5, 0, 0, POINT);
	expected = ft_colour(1, 1, 1);
	actual = pattern_colour_at_world(&pattern, (t_object *)s, world_point);

	printf("Point: (%.1f, %.1f, %.1f)\n", world_point.x, world_point.y, world_point.z);
	printf("Expected: (%.1f, %.1f, %.1f)\n", expected.r, expected.g, expected.b);
	printf("Actual:   (%.1f, %.1f, %.1f)\n", actual.r, actual.g, actual.b);
	if (equal_colour(actual, expected))
		printf(GR"✔ Passed: object transform\n\n"RES);
	else
		return (printf(AKA"❌ Failed: object transform\n\n"RES));

	print_test_banner("Stripes with pattern transformation");
	print_test_number(&i);

	s = ft_sphere(1);
	set_transf(s, create_identity_matrix(4));
	pattern = stripe_pattern(ft_colour(1, 1, 1), ft_colour(0, 0, 0));
	free_matrix(pattern.transform);
	pattern.transform = scale(2, 2, 2);

	world_point = ft_tuple(1.5, 0, 0, POINT);
	expected = ft_colour(1, 1, 1);
	actual = pattern_colour_at_world(&pattern, (t_object *)s, world_point);

	printf("Point: (%.1f, %.1f, %.1f)\n", world_point.x, world_point.y, world_point.z);
	printf("Expected: (%.1f, %.1f, %.1f)\n", expected.r, expected.g, expected.b);
	printf("Actual:   (%.1f, %.1f, %.1f)\n", actual.r, actual.g, actual.b);
	if (equal_colour(actual, expected))
		printf(GR"✔ Passed: pattern transform\n\n"RES);
	else
		return (printf(AKA"❌ Failed: pattern transform\n\n"RES));

	print_test_banner("Stripes with object and pattern transformations");
	print_test_number(&i);

	s = ft_sphere(1);
	set_transf(s, scale(2, 2, 2));
	pattern = stripe_pattern(ft_colour(1, 1, 1), ft_colour(0, 0, 0));
	free_matrix(pattern.transform);
	pattern.transform = translate(0.5, 0, 0);

	world_point = ft_tuple(2.5, 0, 0, POINT);
	expected = ft_colour(1, 1, 1);
	actual = pattern_colour_at_world(&pattern, (t_object *)s, world_point);

	printf("Point: (%.1f, %.1f, %.1f)\n", world_point.x, world_point.y, world_point.z);
	printf("Expected: (%.1f, %.1f, %.1f)\n", expected.r, expected.g, expected.b);
	printf("Actual:   (%.1f, %.1f, %.1f)\n", actual.r, actual.g, actual.b);
	if (equal_colour(actual, expected))
		printf(GR"✔ Passed: object + pattern transform\n\n"RES);
	else
		return (printf(AKA"❌ Failed: object + pattern transform\n\n"RES));

	free_matrix(pattern.transform);
	free_sphere(s);
	return (0);
}

int	pattern_generalization_test(int run)
{
	if (run == 0)
		return (0);

	// int			i;
	// t_pattern	pattern;
	// t_sphere	*s;
	// t_tuple		world_point;
	// t_colour	expected;
	// t_colour	actual;

	// i = 1;
	// print_test_banner("Pattern with object transformation");
	// print_test_number(&i);

	// s = ft_sphere(1);
	// pattern = test_pattern();
	// set_transf(s, scale(2, 2, 2));

	// world_point = ft_tuple(2, 3, 4, POINT);
	// expected = ft_colour(1, 1.5, 2);
	// actual = pattern_colour_at_world(&pattern, (t_object *)s, world_point);

	// printf("Expected: (%.2f, %.2f, %.2f)\n", expected.r, expected.g, expected.b);
	// printf("Actual:   (%.2f, %.2f, %.2f)\n", actual.r, actual.g, actual.b);
	// if (equal_colour(actual, expected))
	// 	printf(GR"✔ Passed: object transformation\n\n"RES);
	// else
	// 	return (printf(AKA"❌ Failed: object transformation\n\n"RES));

	// print_test_banner("Pattern with pattern transformation");
	// print_test_number(&i);

	// s = ft_sphere(1);
	// pattern = test_pattern();
	// free_matrix(pattern.transform);
	// pattern.transform = scale(2, 2, 2);

	// world_point = ft_tuple(2, 3, 4, POINT);
	// expected = ft_colour(1, 1.5, 2);
	// actual = pattern_colour_at_world(&pattern, (t_object *)s, world_point);

	// printf("Expected: (%.2f, %.2f, %.2f)\n", expected.r, expected.g, expected.b);
	// printf("Actual:   (%.2f, %.2f, %.2f)\n", actual.r, actual.g, actual.b);
	// if (equal_colour(actual, expected))
	// 	printf(GR"✔ Passed: pattern transformation\n\n"RES);
	// else
	// 	return (printf(AKA"❌ Failed: pattern transformation\n\n"RES));

	// print_test_banner("Pattern with object and pattern transformation");
	// print_test_number(&i);

	// s = ft_sphere(1);
	// pattern = test_pattern();
	// set_transf(s, scale(2, 2, 2));
	// free_matrix(pattern.transform);
	// pattern.transform = translate(0.5, 1, 1.5);

	// world_point = ft_tuple(2.5, 3, 3.5, POINT);
	// expected = ft_colour(0.75, 0.5, 0.25);
	// actual = pattern_colour_at_world(&pattern, (t_object *)s, world_point);

	// printf("Expected: (%.2f, %.2f, %.2f)\n", expected.r, expected.g, expected.b);
	// printf("Actual:   (%.2f, %.2f, %.2f)\n", actual.r, actual.g, actual.b);
	// if (equal_colour(actual, expected))
	// 	printf(GR"✔ Passed: object + pattern transformation\n"RES);
	// else
	// 	return (printf(AKA"❌ Failed: object + pattern transformation\n"RES));

	// free_matrix(pattern.transform);
	// free_sphere(s);
	return (0);
}

int	gradient_pattern_test(int run)
{
	if (run == 0)
		return (0);

	int			i = 1;
	t_pattern	pattern;
	t_tuple		p;
	t_colour	expected;
	t_colour	actual;

	print_test_banner("Gradient Pattern Linearly Interpolates Between Colors");

	// Setup
	pattern.type = PATTERN_GRADIENT;
	pattern.a = ft_colour(1, 1, 1); // white
	pattern.b = ft_colour(0, 0, 0); // black
	pattern.transform = create_identity_matrix(4);

	// Test 1
	print_test_number(&i);
	p = ft_tuple(0, 0, 0, POINT);
	expected = ft_colour(1, 1, 1);
	actual = gradient_at(&pattern, p);
	printf("Expected: (%.2f, %.2f, %.2f)\n", expected.r, expected.g, expected.b);
	printf("Actual:   (%.2f, %.2f, %.2f)\n", actual.r, actual.g, actual.b);
	if (equal_colour(actual, expected))
		printf(GR"✔ Passed: point(0,0,0) = white\n\n"RES);
	else
		return (printf(AKA"❌ Failed: point(0,0,0)\n\n"RES));

	// Test 2
	print_test_number(&i);
	p = ft_tuple(0.25, 0, 0, POINT);
	expected = ft_colour(0.75, 0.75, 0.75);
	actual = gradient_at(&pattern, p);
	printf("Expected: (%.2f, %.2f, %.2f)\n", expected.r, expected.g, expected.b);
	printf("Actual:   (%.2f, %.2f, %.2f)\n", actual.r, actual.g, actual.b);
	if (equal_colour(actual, expected))
		printf(GR"✔ Passed: point(0.25,0,0)\n\n"RES);
	else
		return (printf(AKA"❌ Failed: point(0.25,0,0)\n\n"RES));

	// Test 3
	print_test_number(&i);
	p = ft_tuple(0.5, 0, 0, POINT);
	expected = ft_colour(0.5, 0.5, 0.5);
	actual = gradient_at(&pattern, p);
	printf("Expected: (%.2f, %.2f, %.2f)\n", expected.r, expected.g, expected.b);
	printf("Actual:   (%.2f, %.2f, %.2f)\n", actual.r, actual.g, actual.b);
	if (equal_colour(actual, expected))
		printf(GR"✔ Passed: point(0.5,0,0)\n\n"RES);
	else
		return (printf(AKA"❌ Failed: point(0.5,0,0)\n\n"RES));

	// Test 4
	print_test_number(&i);
	p = ft_tuple(0.75, 0, 0, POINT);
	expected = ft_colour(0.25, 0.25, 0.25);
	actual = gradient_at(&pattern, p);
	printf("Expected: (%.2f, %.2f, %.2f)\n", expected.r, expected.g, expected.b);
	printf("Actual:   (%.2f, %.2f, %.2f)\n", actual.r, actual.g, actual.b);
	if (equal_colour(actual, expected))
		printf(GR"✔ Passed: point(0.75,0,0)\n\n"RES);
	else
		return (printf(AKA"❌ Failed: point(0.75,0,0)\n\n"RES));

	free_matrix(pattern.transform);
	return (0);
}

int	ring_pattern_test(int run)
{
	if (!run)
		return (0);

	int i = 1;
	t_pattern pattern;
	t_colour expected, actual;

	print_test_banner("Ring Pattern Should Extend in Both X and Z");

	pattern.type = PATTERN_RING;
	pattern.a = ft_colour(1, 1, 1); // white
	pattern.b = ft_colour(0, 0, 0); // black
	pattern.transform = create_identity_matrix(4);

	// point at origin
	print_test_number(&i);
	expected = ft_colour(1, 1, 1);
	actual = ring_at(&pattern, ft_tuple(0, 0, 0, POINT),NULL);
	if (equal_colour(actual, expected))
		printf(GR"✔ Passed: (0,0,0) = white\n\n"RES);
	else
		return (printf(AKA"❌ Failed: (0,0,0)\n\n"RES));

	// point on X ring edge
	print_test_number(&i);
	expected = ft_colour(0, 0, 0);
	actual = ring_at(&pattern, ft_tuple(1, 0, 0, POINT), NULL);
	if (equal_colour(actual, expected))
		printf(GR"✔ Passed: (1,0,0) = black\n\n"RES);
	else
		return (printf(AKA"❌ Failed: (1,0,0)\n\n"RES));

	// point just outside first ring
	print_test_number(&i);
	expected = ft_colour(0, 0, 0);
	actual = ring_at(&pattern, ft_tuple(0, 0, 1, POINT), NULL);
	if (equal_colour(actual, expected))
		printf(GR"✔ Passed: (0,0,1) = black\n\n"RES);
	else
		return (printf(AKA"❌ Failed: (0,0,1)\n\n"RES));

	// diagonally at √2 ≈ 1.41 -> floor(1.41) == 1 -> black
	print_test_number(&i);
	expected = ft_colour(0, 0, 0);
	actual = ring_at(&pattern, ft_tuple(0.708, 0, 0.708, POINT), NULL);
	if (equal_colour(actual, expected))
		printf(GR"✔ Passed: diagonal (0.708,0,0.708) = black\n\n"RES);
	else
		return (printf(AKA"❌ Failed: diagonal point\n\n"RES));

	free_matrix(pattern.transform);
	return (0);
}

int	checkers_pattern_test(int run)
{
	if (!run)
		return (0);

	int i = 1;
	t_pattern pattern;
	t_colour expected, actual;

	print_test_banner("Checkers Pattern Should Repeat in 3D");

	pattern.type = PATTERN_CHECKERS;
	pattern.a = ft_colour(1, 1, 1); // white
	pattern.b = ft_colour(0, 0, 0); // black
	pattern.transform = create_identity_matrix(4);

	// x changes
	print_test_number(&i);
	expected = ft_colour(1, 1, 1);
	actual = checkers_at(&pattern, ft_tuple(0, 0, 0, POINT),NULL);
	if (equal_colour(actual, expected))
		printf(GR"✔ Passed: (0,0,0) = white\n\n"RES);
	else
		return (printf(AKA"❌ Failed: (0,0,0)\n\n"RES));

	print_test_number(&i);
	expected = ft_colour(1, 1, 1);
	actual = checkers_at(&pattern, ft_tuple(0.99, 0, 0, POINT), NULL);
	if (equal_colour(actual, expected))
		printf(GR"✔ Passed: (0.99,0,0) = white\n\n"RES);
	else
		return (printf(AKA"❌ Failed: (0.99,0,0)\n\n"RES));

	print_test_number(&i);
	expected = ft_colour(0, 0, 0);
	actual = checkers_at(&pattern, ft_tuple(1.01, 0, 0, POINT), NULL);
	if (equal_colour(actual, expected))
		printf(GR"✔ Passed: (1.01,0,0) = black\n\n"RES);
	else
		return (printf(AKA"❌ Failed: (1.01,0,0)\n\n"RES));

	// y changes
	print_test_number(&i);
	expected = ft_colour(1, 1, 1);
	actual = checkers_at(&pattern, ft_tuple(0, 0.99, 0, POINT), NULL);
	if (equal_colour(actual, expected))
		printf(GR"✔ Passed: (0,0.99,0) = white\n\n"RES);
	else
		return (printf(AKA"❌ Failed: (0,0.99,0)\n\n"RES));

	print_test_number(&i);
	expected = ft_colour(0, 0, 0);
	actual = checkers_at(&pattern, ft_tuple(0, 1.01, 0, POINT), NULL);
	if (equal_colour(actual, expected))
		printf(GR"✔ Passed: (0,1.01,0) = black\n\n"RES);
	else
		return (printf(AKA"❌ Failed: (0,1.01,0)\n\n"RES));

	// z changes
	print_test_number(&i);
	expected = ft_colour(1, 1, 1);
	actual = checkers_at(&pattern, ft_tuple(0, 0, 0.99, POINT), NULL);
	if (equal_colour(actual, expected))
		printf(GR"✔ Passed: (0,0,0.99) = white\n\n"RES);
	else
		return (printf(AKA"❌ Failed: (0,0,0.99)\n\n"RES));

	print_test_number(&i);
	expected = ft_colour(0, 0, 0);
	actual = checkers_at(&pattern, ft_tuple(0, 0, 1.01, POINT), NULL);
	if (equal_colour(actual, expected))
		printf(GR"✔ Passed: (0,0,1.01) = black\n\n"RES);
	else
		return (printf(AKA"❌ Failed: (0,0,1.01)\n\n"RES));

	free_matrix(pattern.transform);
	return (0);
}

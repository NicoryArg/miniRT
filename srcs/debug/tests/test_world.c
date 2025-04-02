/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:32:08 by nryser            #+#    #+#             */
/*   Updated: 2025/04/02 18:32:20 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"
#include "engine.h"

int	world_test(int run)
{
	if (run == 0)
		return (0);
	int			i;
	t_world		*w;

	i = 1;
	// TEST 1: Creating an empty world
	print_test_banner("Creating an empty world");
	print_test_number(&i);
	w = ft_world();
	if (!w)
	{
		printf(AKA"❌ Failed to allocate world\n"RES);
		return (1);
	}
	if (w->objects == NULL && w->object_count == 0)
		printf(GR"✔ No objects in the world\n"RES);
	else
		printf(AKA"❌ World has unexpected objects\n"RES);
	if (w->light == NULL)
		printf(GR"✔ No light in the world\n"RES);
	else
		printf(AKA"❌ World has a light source when it shouldn't\n"RES);
	free_world(w);
	return (0);
}

int	default_world_test(int run)
{
	if (run == 0)
		return (0);
	int			i = 2;
	t_world		*w;
	t_light		*expected_light;
	t_sphere	*s1;
	t_sphere	*s2;
	t_matrix	*expected_scale;

	print_test_banner("Default world contains two spheres and a light");
	print_test_number(&i);
	w = default_world();
	// Check the light
	expected_light = ft_light(ft_tuple(-10, 10, -10, POINT), ft_colour(1, 1, 1));
	printf("Expected Light Position: (%.1f, %.1f, %.1f)\n", expected_light->pos.x, expected_light->pos.y, expected_light->pos.z);
	printf("Actual Light Position:   (%.1f, %.1f, %.1f)\n", w->light->pos.x, w->light->pos.y, w->light->pos.z);
	printf("Expected Light Color: (%.1f, %.1f, %.1f)\n", expected_light->lum.r, expected_light->lum.g, expected_light->lum.b);
	printf("Actual Light Color:   (%.1f, %.1f, %.1f)\n", w->light->lum.r, w->light->lum.g, w->light->lum.b);
	if (equal_tuple(w->light->pos, expected_light->pos) &&
		ft_equal(w->light->lum.r, expected_light->lum.r) &&
		ft_equal(w->light->lum.g, expected_light->lum.g) &&
		ft_equal(w->light->lum.b, expected_light->lum.b))
		printf(G_B"✔ Light is correctly initialized\n"RES);
	else
		printf(AKA"❌ Light does not match expected values\n"RES);
	free(expected_light);
	// Check object count
	printf("World object count: %d\n", w->object_count);
	if (w->object_count == 2)
		printf(G_B"✔ World has 2 objects\n"RES);
	else
		printf(AKA"❌ World object count is incorrect\n"RES);
	// Check first sphere's material
	s1 = w->objects[0];
	printf("First sphere material color: (%.1f, %.1f, %.1f)\n", s1->m->c.r, s1->m->c.g, s1->m->c.b);
	printf("Diffuse: %.1f | Specular: %.1f\n", s1->m->diffuse, s1->m->specular);
	if (ft_equal(s1->m->c.r, 0.8) && ft_equal(s1->m->c.g, 1.0) && ft_equal(s1->m->c.b, 0.6) &&
		ft_equal(s1->m->diffuse, 0.7) && ft_equal(s1->m->specular, 0.2))
		printf(G_B"✔ First sphere material matches expected values\n"RES);
	else
		printf(AKA"❌ First sphere material does not match expected values\n"RES);
	// Check second sphere’s scale (0.5, 0.5, 0.5)
	s2 = w->objects[1];
	expected_scale = scale(0.5, 0.5, 0.5);
	printf("Second sphere transform:\n");
	print_matrix(s2->transf);
	printf("Expected transform:\n");
	print_matrix(expected_scale);
	if (equal_matrix(s2->transf, expected_scale))
		printf(G_B"✔ Second sphere transform is scaled correctly\n"RES);
	else
		printf(AKA"❌ Second sphere transform is incorrect\n"RES);
	free_matrix(expected_scale);
	free_world(w);
	return (0);
}

int	intersect_world_test(int run)
{
	if (run == 0)
		return (0);
	int			i = 3;
	t_world		*w = default_world();
	t_ray		*r = ft_ray(ft_tuple(0, 0, -5, POINT), ft_tuple(0, 0, 1, VECTOR));
	t_inters	*xs = intersect_world(w, r);
	double		expected[] = {4.0, 4.5, 5.5, 6.0};

	print_test_banner("Intersecting a world with a ray");
	print_test_number(&i);
	// Check count
	printf("Intersections count: %d\n", xs->count);
	if (xs->count == 4)
		printf(G_B"✔ xs.count == 4\n"RES);
	else
		printf(AKA"❌ xs.count != 4\n"RES);

	for (int j = 0; j < xs->count; j++)
	{
		printf("xs[%d].t = %.1f (expected %.1f)\n", j, xs->hits[j]->t, expected[j]);
		if (ft_equal(xs->hits[j]->t, expected[j]))
			printf(GR"✔ t%d is correct\n"RES, j);
		else
			printf(AKA"❌ t%d is incorrect\n"RES, j);
	}
	free_ray(r);
	free_hits(xs);
	free_world(w);
	return (0);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cylinders.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 01:32:50 by ameechan          #+#    #+#             */
/*   Updated: 2025/04/19 03:05:25 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"
#include "tests.h"

static int	check_cyl_intersect_result(t_inters *xs, int count, double t0, double t1)
{
	if (xs->count == count)
		printf(GR"✔ ray intersects cylinder\n"RES);
	else
		return (printf(AKA"❌ ray does not intersect cylinder\n"RES));
	if (ft_equal(xs->hits[0]->t, t0))
		printf(GR"✔ xs[0]->t is correct\n"RES);
	else
		return (printf(AKA"❌ xs[0]->t is incorrect\n"RES));
	if (ft_equal(xs->hits[1]->t, t1))
		printf(GR"✔ xs[1]->t is correct\n\n"RES);
	else
		return (printf(AKA"❌ xs[1]->t is incorrect\n"RES));
	return (0);
}

int	test_intersect_cylinder(int run)
{
	if (run == 0)
		return (0);
	t_cylinder	*cyl;
	t_ray		*ray;
	t_tuple		direction;
	t_tuple		origin;
	t_inters	*xs;
	int			i = 1;
//TEST 1
	//print banners
	print_test_banner("Rays miss the cylinder");
	print_sub_header("ray -> origin (1,0,0) direction (0,1,0)", &i);
	//initialise variables
	cyl = ft_cylinder();
	origin = ft_tuple(1, 0, 0, VECTOR);
	direction = ft_tuple(0, 1, 0, VECTOR);
	ray = ft_ray(origin, direction);
	//run test
	xs = intersect(cyl, ray);
	//print output
	printf(B_B"xs.count: %d\n"RES, xs->count);
	printf(G_B"expected: 0\n"RES);
	//check result
	if (xs->count == 0)
		printf(GR"✔ ray does not intersect cylinder\n\n"RES);
	else
		return (printf(AKA"❌ ray intersects cylinder\n"RES));
	//free memory
	free_hits(xs);
	free_ray(ray);

//TEST 2
	//print banners
	print_sub_header("ray -> origin (0,0,0) direction (0,1,0)", &i);
	//redefine variables
	origin = ft_tuple(0, 0, 0, VECTOR);
	direction = ft_tuple(0, 1, 0, VECTOR);
	ray = ft_ray(origin, direction);
	//run test
	xs = intersect(cyl, ray);
	//print output
	printf(B_B"xs.count: %d\n"RES, xs->count);
	printf(G_B"expected: 0\n"RES);
	//check result
	if (xs->count == 0)
		printf(GR"✔ ray does not intersect cylinder\n\n"RES);
	else
		return (printf(AKA"❌ ray intersects cylinder\n"RES));
	//free memory
	free_hits(xs);
	free_ray(ray);

//TEST 3
	//print banners
	print_sub_header("ray -> origin (0,0,-5) direction (1,1,1)", &i);
	//redefine variables
	origin = ft_tuple(0, 0, -5, VECTOR);
	direction = normalise(ft_tuple(1, 1, 1, VECTOR));
	ray = ft_ray(origin, direction);
	//run test
	xs = intersect(cyl, ray);
	//print output
	printf(B_B"xs.count: %d\n"RES, xs->count);
	printf(G_B"expected: 0\n"RES);
	//check result
	if (xs->count == 0)
		printf(GR"✔ ray does not intersect cylinder\n\n"RES);
	else
		return (printf(AKA"❌ ray intersects cylinder\n"RES));
	//free memory
	free_hits(xs);
	free_ray(ray);

//TEST 4
	//print banners
	print_test_banner("Rays intersect the cylinder");
	print_sub_header("ray -> origin (1,0,-5) direction (0,0,1)", &i);
	//redefine variables
	origin = ft_tuple(1, 0, -5, VECTOR);
	direction = normalise(ft_tuple(0, 0, 1, VECTOR));
	ray = ft_ray(origin, direction);
	double t0 = 5;
	double t1 = 5;
	//run test
	xs = intersect(cyl, ray);
	//print output
	printf(B_B"xs.count: %d\t"RES, xs->count);
	printf(G_B"expected: 2\n"RES);
	printf(B_B"xs[0]->t: %.0f\t"RES, xs->hits[0]->t);
	printf(G_B"expected: %.0f\n"RES, t0);
	printf(B_B"xs[1]->t: %.0f\t"RES, xs->hits[1]->t);
	printf(G_B"expected: %.0f\n"RES, t1);
	//check result
	if (check_cyl_intersect_result(xs, 2, t0, t1))
		return (-1);
	//free memory
	free_hits(xs);
	free_ray(ray);

//TEST 5
	//print banners
	print_sub_header("ray -> origin (0,0,-5) direction (0,0,1)", &i);
	//redefine variables
	origin = ft_tuple(0, 0, -5, VECTOR);
	direction = normalise(ft_tuple(0, 0, 1, VECTOR));
	ray = ft_ray(origin, direction);
	t0 = 4;
	t1 = 6;
	//run test
	xs = intersect(cyl, ray);
	//print output
	printf(B_B"xs.count: %d\t"RES, xs->count);
	printf(G_B"expected: 2\n"RES);
	printf(B_B"xs[0]->t: %.0f\t"RES, xs->hits[0]->t);
	printf(G_B"expected: %.0f\n"RES, t0);
	printf(B_B"xs[1]->t: %.0f\t"RES, xs->hits[1]->t);
	printf(G_B"expected: %.0f\n"RES, t1);
	//check result
	if (check_cyl_intersect_result(xs, 2, t0, t1))
		return (-1);
//TEST 6
	//print banners
	print_sub_header("ray -> origin (0.5,0,-5) direction (0.1,1,1)", &i);
	//redefine variables
	origin = ft_tuple(0.5, 0, -5, VECTOR);
	direction = normalise(ft_tuple(0.1, 1, 1, VECTOR));
	ray = ft_ray(origin, direction);
	t0 = 6.80798;
	t1 = 7.08872;
	//run test
	xs = intersect(cyl, ray);
	//print output
	printf(B_B"xs.count: %d\t\t"RES, xs->count);
	printf(G_B"expected: 2\n"RES);
	printf(B_B"xs[0]->t: %.5f\t"RES, xs->hits[0]->t);
	printf(G_B"expected: %.5f\n"RES, t0);
	printf(B_B"xs[1]->t: %.5f\t"RES, xs->hits[1]->t);
	printf(G_B"expected: %.5f\n"RES, t1);
	//check result
	if (check_cyl_intersect_result(xs, 2, t0, t1))
		return (-1);
	//free memory
	free_hits(xs);
	free_ray(ray);
	return (0);
}

int	test_normal_at_cylinder(int run)
{
	if (run == 0)
		return (0);
	t_cylinder	*cyl;
	t_tuple		p;
	t_tuple		n;
	t_tuple		expected_normal;
	int			i = 1;

//TEST 1
	//print banners
	print_test_banner("Normal at cylinder");
	print_sub_header("point -> (1,0,0)", &i);
	//initialise variables
	cyl = ft_cylinder();
	p = ft_tuple(1, 0, 0, POINT);
	expected_normal = ft_tuple(1, 0, 0, VECTOR);
	//run test
	n = local_normal_at(cyl, p);
	//print output
	print_normal(n, expected_normal, CYLINDER);
	//check result
	if (equal_tuple(n, expected_normal))
		printf(GR"✔ normal is correct\n\n"RES);
	else
		return (printf(AKA"❌ normal is incorrect\n"RES));

//TEST 2
	//print banners
	print_sub_header("point -> (0,5,-1)", &i);
	//redefine variables
	p = ft_tuple(0, 5, -1, POINT);
	expected_normal = ft_tuple(0, 0, -1, VECTOR);
	//run test
	n = local_normal_at(cyl, p);
	//print output
	print_normal(n, expected_normal, CYLINDER);
	//check result
	if (equal_tuple(n, expected_normal))
		printf(GR"✔ normal is correct\n\n"RES);
	else
		return (printf(AKA"❌ normal is incorrect\n"RES));

//TEST 3
	//print banners
	print_sub_header("point -> (0,-2,1)", &i);
	//redefine variables
	p = ft_tuple(0, -2, 1, POINT);
	expected_normal = ft_tuple(0, 0, 1, VECTOR);
	//run test
	n = local_normal_at(cyl, p);
	//print output
	print_normal(n, expected_normal, CYLINDER);
	//check result
	if (equal_tuple(n, expected_normal))
		printf(GR"✔ normal is correct\n\n"RES);
	else
		return (printf(AKA"❌ normal is incorrect\n"RES));

//TEST 4
	//print banners
	print_sub_header("point -> (-1,1,0)", &i);
	//redefine variables
	p = ft_tuple(-1, 1, 0, POINT);
	expected_normal = ft_tuple(-1, 0, 0, VECTOR);
	//run test
	n = local_normal_at(cyl, p);
	//print output
	print_normal(n, expected_normal, CYLINDER);
	//check result
	if (equal_tuple(n, expected_normal))
		printf(GR"✔ normal is correct\n\n"RES);
	else
		return (printf(AKA"❌ normal is incorrect\n"RES));
	return (0);
}


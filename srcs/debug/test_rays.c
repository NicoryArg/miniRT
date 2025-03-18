/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:54:04 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/18 18:15:51 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	position_test(int run)
{
	if (run == 0)
		return (0);
	int	i = 1;
	t_ray	*r = ray(make_tuple(2, 3, 4, POINT), make_tuple(1, 0, 0, VECTOR));
	t_tuple	*res;


	print_test_banner("POSITION");
//TEST 1
	print_test_number(&i);
	res = get_point(r, 0);
	print_tuple(res, "(r, 0)");
//TEST 2
	print_test_number(&i);
	res = get_point(r, 1);
	print_tuple(res, "(r, 1)");
//TEST 3
	print_test_number(&i);
	res = get_point(r, -1);
	print_tuple(res, "(r, -1)");
//TEST 4
	print_test_number(&i);
	res = get_point(r, 2.5);
	print_tuple(res, "(r, 2.5)");
	return (0);
}
/**
 * @brief tests that each sphere is properly given a unique ID
 * @param run 1 to run, 0 to skip
 * @param num number of spheres to create
 */
int	sph_unique_id(int run, int num)
{
	if (run == 0)
		return (0);
	int i = 0;
	int	test = 1;

//TEST 1
	print_test_banner("SPHERE UNIQUE ID");
	print_test_number(&test);
	while (i < num)
	{
		t_sphere	*s0 = sphere(1);
		printf("sphere ID: %d\n", s0->id);
		i++;
	}
	return (0);
}

int	sph_ray_intersect(int run)
{
	if (run == 0)
		return (0);
	int		i = 1;
	t_ray	*r = ray(make_tuple(-5, 0, 0, POINT), make_tuple(1, 0, 0, VECTOR));
	t_sphere	*s = sphere(1);
	double	d;
	double	*xs = NULL;
	if (!r || !s)
		return (1);
//TEST 1
	print_test_banner("SPHERE-RAY");
	print_test_banner("two intersections");
	print_test_number(&i);
	d = discriminant(r, diff_tuple(r->origin, s->centre));
	printf(G_B"Discriminant: "RES"%.2f\n", d);
	xs = intersect(s, r, SPHERE);
	printf(G_B"t1: "RES"%f\n", xs[0]);
	printf(G_B"t2: "RES"%f\n", xs[1]);
	free(xs);
	free(r->direction);
	free(r->origin);
	free(r);
//TEST 2
	//redefine ray
	r = ray(make_tuple(-5, 1, 0, POINT), make_tuple(1, 0, 0, VECTOR));
	print_test_banner("tangent");
	print_test_number(&i);
	d = discriminant(r, diff_tuple(r->origin, s->centre));
	printf(G_B"Discriminant: "RES"%.2f\n", d);
	//call function
	xs = intersect(s, r, SPHERE);
	//print output
	printf(G_B"t1: "RES"%f\n", xs[0]);
	printf(G_B"t2: "RES"%f\n", xs[1]);
	//free resources
	free(xs);
	free(r->direction);
	free(r->origin);
	free(r);
//TEST 3
	//redifine ray
	r = ray(make_tuple(-5, 2, 0, POINT), make_tuple(1, 0, 0, VECTOR));
	print_test_banner("no intersection");
	print_test_number(&i);
	d = discriminant(r, diff_tuple(r->origin, s->centre));
	printf(G_B"Discriminant: "RES"%.2f\n", d);
	//call function
	xs = intersect(s, r, SPHERE);
	//print output
	if (xs)
	{
		printf(G_B"t1: "RES"%f\n", xs[0]);
		printf(G_B"t2: "RES"%f\n", xs[1]);
	}
	else
		printf(YEL"xs is NULL\n"RES);
	//free resources
	free(xs);
	free(r->direction);
	free(r->origin);
	free(r);
//TEST 4
	//redefine ray
	r = ray(make_tuple(0, 0, 0, POINT), make_tuple(1, 0, 0, VECTOR));
	print_test_banner("ray originates inside sphere");
	print_test_number(&i);
	d = discriminant(r, diff_tuple(r->origin, s->centre));
	printf(G_B"Discriminant: "RES"%.2f\n", d);
	//call function
	xs = intersect(s, r, SPHERE);
	//print output
	printf(G_B"t1: "RES"%f\n", xs[0]);
	printf(G_B"t2: "RES"%f\n", xs[1]);
	//free resources
	free(xs);
	free(r->direction);
	free(r->origin);
	free(r);
//TEST 5
	//redefine ray
	r = ray(make_tuple(5, 0, 0, POINT), make_tuple(1, 0, 0, VECTOR));
	print_test_banner("sphere is behind ray");
	print_test_number(&i);
	d = discriminant(r, diff_tuple(r->origin, s->centre));
	printf(G_B"Discriminant: "RES"%.2f\n", d);
	//call function
	xs = intersect(s, r, SPHERE);
	//print output
	printf(G_B"t1: "RES"%f\n", xs[0]);
	printf(G_B"t2: "RES"%f\n", xs[1]);
	//free resources
	free(xs);
	free(r->direction);
	free(r->origin);
	free(r);
	return (0);
}

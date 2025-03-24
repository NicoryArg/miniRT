/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:48:11 by nryser            #+#    #+#             */
/*   Updated: 2025/03/24 15:49:10 by nryser           ###   ########.ch       */
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



//#################################################################//
//########################## P59 - P62 #############################//
//#################################################################//

int	sph_ray_intersect(int run)
{
	if (run == 0)
		return (0);
	int		i = 1;
	t_ray	*r = ray(make_tuple(-5, 0, 0, POINT), make_tuple(1, 0, 0, VECTOR));
	t_sphere	*s = sphere(1);
	double		d;
	t_inters	*xs = NULL;
	if (!r || !s)
		return (1);
//TEST 1
	print_test_banner("SPHERE-RAY");
	print_test_banner("two intersections");
	print_test_number(&i);
	d = discriminant(r, diff_tuple(r->origin, s->centre));
	printf(G_B"Discriminant: "RES"%.2f\n", d);
	xs = intersect(s, r, SPHERE);
	printf(G_B"t1: "RES"%f\n", xs->hits[0]->t);
	printf(G_B"t2: "RES"%f\n", xs->hits[1]->t);
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
	printf(G_B"t1: "RES"%f\n", xs->hits[0]->t);
	printf(G_B"t2: "RES"%f\n", xs->hits[1]->t);
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
		printf(G_B"t1: "RES"%f\n", xs->hits[0]->t);
		printf(G_B"t2: "RES"%f\n", xs->hits[1]->t);
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
	printf(G_B"t1: "RES"%f\n", xs->hits[0]->t);
	printf(G_B"t2: "RES"%f\n", xs->hits[1]->t);
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
	printf(G_B"t1: "RES"%f\n", xs->hits[0]->t);
	printf(G_B"t2: "RES"%f\n", xs->hits[1]->t);
	//free resources
	free(xs);
	free(r->direction);
	free(r->origin);
	free(r);
	return (0);
}



//#################################################################//
//########################## P63 - P66 #############################//
//#################################################################//

int	intersection_test(int run)
{
	if (run == 0)
		return (0);
	int			i = 1;
	t_sphere	*s = sphere(1);
	t_ray		*r = ray(make_tuple(-5, 0, 0, POINT), make_tuple(1, 0, 0, VECTOR));
	t_hit		*i1 = NULL;
	t_hit		*i2 = NULL;
	t_hit		*i3 = NULL;
	t_hit		*i4 = NULL;
	double		hit;

//TEST 1
	//print banners
	print_test_banner("Intersection encapsulates t and object");
	print_test_number(&i);
	//call function
	i1 = intersection(3.5, s, SPHERE);
	//print ouput
	printf(BOLD"%15s "GR"%14f\n"RES, "i.t:", i1->t);
	printf(BOLD"%15s "GR"%20p"RES"\n", "i.object:", i1->object);
	printf(BOLD"%15s "LILA"%20p\n"RES"", "Sphere:", s);
	//free variables
	free(i1);
//TEST 2
	//print banners
	print_test_banner("Aggregating intersections");
	print_test_number(&i);
	//redefine variables
	t_sphere	*s2 = sphere(1);
	t_inters	*xs = intersect(s2, r, SPHERE);
	printf(BOLD"%15s "GR"%7d\n"RES, "xs.count:", xs->count);
	printf(BOLD"%15s "GR"%20p\n"RES, "xs[0].object:", xs->hits[0]->object);
	printf(BOLD"%15s "GR"%20p\n"RES, "xs[1].object:", xs->hits[1]->object);
	printf(BOLD"%15s "LILA"%20p\n"RES, "Sphere:", s2);
	//free variables
	free(xs->hits);
	free(xs);
//TEST 3
	//print banners
	print_test_banner("hit when all inters have positive `t`");
	print_test_number(&i);
	printf(BOLD"_________________________________\n\n"RES);
	//redifine variables;
	i1 = intersection(1, s, SPHERE);
	i2 = intersection(2, s, SPHERE);
	t_hit	**intersections = malloc(sizeof(t_hit *) * (2 + 1));
	for (int x = 0; x < 3; x++)
		intersections[x] = malloc(sizeof(t_hit));
	intersections[0] = i1;
	intersections[1] = i2;
	intersections[2] = NULL;
	//run test
	hit = find_hit(intersections, 2);
	//print output
	print_intersections(intersections, 2, 1);
	printf(G_B"%6s "GR"%7.0f\n"RES, "hit:", hit);
	//free variables
	free(i1);
	free(i2);
//TEST 4
	//print banners
	print_test_banner("hit when some inters have nagative `t`");
	print_test_number(&i);
	printf(BOLD"_________________________________\n\n"RES);
	//redefine variables
	i1 = intersection(-1, s, SPHERE);
	i2 = intersection(1, s, SPHERE);
	intersections[0] = i1;
	intersections[1] = i2;
	intersections[2] = NULL;
	//run test
	hit = find_hit(intersections, 2);
	//print output
	print_intersections(intersections, 2, 1);
	printf(G_B"%6s "GR"%7.0f\n"RES, "hit:", hit);
	//free variables
	free(i1);
	free(i2);
//TEST 5
	//print banners
	print_test_banner("hit when all inters have nagative `t`");
	print_test_number(&i);
	printf(BOLD"_________________________________\n\n"RES);
	//redefine variables
	i1 = intersection(-2, s, SPHERE);
	i2 = intersection(-1, s, SPHERE);
	intersections[0] = i1;
	intersections[1] = i2;
	intersections[2] = NULL;
	//run test
	hit = find_hit(intersections, 2);
	//print output
	print_intersections(intersections, 2, 1);
	printf(G_B"%6s "GR"%7.0f\n"RES, "hit:", hit);
	//free variables
	free(i1);
	free(i2);
	free(intersections);
//TEST 6
	//print banners
	print_test_banner("hit when unsorted array of inters");
	print_test_number(&i);
	printf(BOLD"_________________________________\n\n"RES);
	//redefine variables
	i1 = intersection(5, s, SPHERE);
	i2 = intersection(7, s, SPHERE);
	i3 = intersection(-3, s, SPHERE);
	i4 = intersection(2, s, SPHERE);
	intersections = malloc(sizeof(t_hit *) * (4 + 1));
	intersections[0] = i1;
	intersections[1] = i2;
	intersections[2] = i3;
	intersections[3] = i4;
	intersections[4] = NULL;
	print_intersections(intersections, 4, 0);
	//run test
	hit = find_hit(intersections, 4);
	//print output
	print_intersections(intersections, 4, 1);
	printf(G_B"%6s "GR"%7.0f\n"RES, "hit:", hit);
	//free variables
	free(i1);
	free(i2);
	return (0);
}

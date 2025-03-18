/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:54:04 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/18 22:00:11 by ameechan         ###   ########.fr       */
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
	printf(G_B"t1: "RES"%f\n", xs->hits[0].t);
	printf(G_B"t2: "RES"%f\n", xs->hits[1].t);
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
	printf(G_B"t1: "RES"%f\n", xs->hits[0].t);
	printf(G_B"t2: "RES"%f\n", xs->hits[1].t);
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
		printf(G_B"t1: "RES"%f\n", xs->hits[0].t);
		printf(G_B"t2: "RES"%f\n", xs->hits[1].t);
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
	printf(G_B"t1: "RES"%f\n", xs->hits[0].t);
	printf(G_B"t2: "RES"%f\n", xs->hits[1].t);
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
	printf(G_B"t1: "RES"%f\n", xs->hits[0].t);
	printf(G_B"t2: "RES"%f\n", xs->hits[1].t);
	//free resources
	free(xs);
	free(r->direction);
	free(r->origin);
	free(r);
	return (0);
}



//#################################################################//
//########################## P63 - Pxx #############################//
//#################################################################//

int	intersection_test(int run)
{
	if (run == 0)
		return (0);
	int			i = 1;
	t_sphere	*s = sphere(1);
	t_ray		*r = ray(make_tuple(-5, 0, 0, POINT), make_tuple(1, 0, 0, VECTOR));
	t_hit		*i1 = NULL;
	// t_hit		*i2 = NULL;
	// t_hit		*xs = NULL;

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

//TEST 2
	//print banners
	print_test_banner("Aggregating intersections");
	print_test_number(&i);
	//redefine variables
	free(s);
	s = sphere(1);
	t_inters	*xs = intersect(s, r, SPHERE);
	printf(BOLD"%15s "GR"%7d\n"RES, "xs.count:", xs->count);
	printf(BOLD"%15s "GR"%20p\n"RES, "xs[0].object:", xs->hits[0].object);
	printf(BOLD"%15s "GR"%20p\n"RES, "xs[1].object:", xs->hits[1].object);
	printf(BOLD"%15s "LILA"%20p\n"RES, "Sphere:", s);

	return (0);
}

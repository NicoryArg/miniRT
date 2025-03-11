/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:54:04 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/11 19:40:46 by ameechan         ###   ########.fr       */
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
		t_sph	*s0 = sphere(1);
		printf("sphere ID: %d\n", s0->id);
		i++;
	}
	return (0);
}

int	sph_two_intersect(int run)
{
	if (run == 0)
		return (0);
	int		i = 1;
	t_ray	*r = ray(make_tuple(0, 0, -5, POINT), make_tuple(0, 0, 1, VECTOR));
	t_sph	*s = sphere(1);
	// double	**xs = NULL;
	if (!r || !s)
		return (1);

//TEST 1
	print_test_banner("SPHERE-RAY -> two intersections");
	print_test_number(&i);
	// xs = intersect(s, r);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:54:04 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/10 20:53:45 by ameechan         ###   ########.fr       */
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

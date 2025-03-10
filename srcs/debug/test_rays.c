/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:54:04 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/10 20:20:25 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	position_test(int run)
{
	if (run == 0)
		return (0);
	int	i = 1;
	// t_ray	*r = ray(make_tuple(2, 3, 4, POINT), make_tuple(1, 0, 0, VECTOR));
	// t_tuple	*res;
	print_test_banner("POSITION");
	print_test_number(&i);
	print_test_number(&i);
	print_test_number(&i);
	print_test_number(&i);
	return (0);
}

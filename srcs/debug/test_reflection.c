/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_reflection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:32:24 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/25 13:35:08 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	normal_at_test(int run)
{
	if (run == 0)
		return (0);
	t_sphere	*s;
	t_tuple		*world_point;
	t_tuple		*normal;
	int			i = 1;


//TEST 1
	//print banners
	print_test_banner("normal on a translated sphere");
	print_test_number(&i);
	//define variables
	s = sphere(1);
	set_transf(s, translate(0, 1, 0), SPHERE);
	world_point = ft_tuple(0, 1.70711, -0.707111, POINT);
	//run test
	normal = normal_at(s, world_point);
	//print output and free relevant vars
	print_normal(normal, 0, 1.70711, -0.707111);
	free(world_point);
	free(normal);

//TEST 2
	//print banners
	print_test_banner("normal on a transformed sphere");
	print_test_number(&i);
	//redefine variables
	set_transf(s, multiply_matrices(scale(1, 0.5, 1), rotate_z(M_PI/5)), SPHERE);
	world_point = ft_tuple(0, sqrt(2)/2, -(sqrt(2)/2), POINT);
	//run test
	normal = normal_at(s, world_point);
	//print output and free relevant vars
	print_normal(normal, 0, sqrt(2)/2, -(sqrt(2)/2));

	return (0);
}

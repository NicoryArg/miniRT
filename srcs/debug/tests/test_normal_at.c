/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_reflection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:srcs/debug/test_reflection.c
/*   Created: 2025/03/25 19:05:27 by nryser            #+#    #+#             */
/*   Updated: 2025/03/25 19:05:27 by nryser           ###   ########.ch       */
=======
/*   Created: 2025/03/25 12:32:24 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/29 14:46:43 by ameechan         ###   ########.fr       */
>>>>>>> andrew:srcs/debug/tests/test_normal_at.c
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

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
<<<<<<< HEAD:srcs/debug/test_reflection.c
	//define variables
	s = ft_sphere(1, NULL);
=======
	//initiate variables
	s = sphere(1);
>>>>>>> andrew:srcs/debug/tests/test_normal_at.c
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
	//initiate variables
	set_transf(s, multiply_matrices(scale(1, 0.5, 1), rotate_z(M_PI/5)), SPHERE);
	world_point = ft_tuple(0, sqrt(2)/2, -(sqrt(2)/2), POINT);
	//run test
	normal = normal_at(s, world_point);
	//print output and free relevant vars
	print_normal(normal, 0, sqrt(2)/2, -(sqrt(2)/2));
	//free all unused variables hereafter
	free(s->centre);
	free_matrix(s->transf);
	free(s);
	free(world_point);
	free(normal);

//define new variables for reflection tests
	t_tuple	*v;
	t_tuple	*n;
	t_tuple	*r;

//TEST 3
	//print_banners
	print_test_banner("Reflecting a vector approaching at 45°");
	print_test_number(&i);
	//initiate variables
	v = ft_tuple(1, -1, 0, VECTOR);
	n = ft_tuple(0, 1, 0, VECTOR);
	//run test
	r = ft_reflect(v, n);
	//print ouput
	print_tuple(r, "reflected");
	free(v);
	free(n);
	free(r);

//TEST 4
	//print_banners
	print_test_banner("Reflecting a vector off a slanted surface");
	print_test_number(&i);
	//initiate variables
	v = ft_tuple(0, -1, 0, VECTOR);
	n = ft_tuple(sqrt(2)/2, sqrt(2)/2, 0, VECTOR);
	//run test
	r = ft_reflect(v, n);
	//print ouput
	print_tuple(r, "reflected");
	free(v);
	free(n);
	free(r);
	return (0);
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:49:03 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/06 14:03:50 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int	rotate_x_test()
{
	t_matrix	*half_quarter = rotate_x(M_PI / 4);
	t_matrix	*full_quarter = rotate_x(M_PI / 2);
	t_matrix	*inverse = invert_matrix(half_quarter);
	t_tuple		*point = make_tuple(0, 1, 0, POINT);
	t_matrix	*p = tuple_to_matrix(point);
	t_matrix	*result = NULL;

	if (!half_quarter || !full_quarter || !point || !p)
	{
		printf("Error: one or more arguments are NULL\n");
		return (1);
	}
	printf(B_B"##############################################################\n");
	printf("################  [R O T A T I O N  X]  #########################\n");
	printf("##############################################################\n"CYAN);
	printf("##### TEST 1 #####\n"RES);
	printf("Rotating a point half a quarter around the x-axis\n");
	printf(GR"CURRENT TUPPLE MATRIX:\n"RES);
	print_matrix(p);
	result = multiply_matrices(half_quarter, p);
	printf(GR"RESULT:\n"RES);
	print_matrix(result);
	printf(B_B"##############################################################\n"CYAN);
	printf("##### TEST 2 #####\n"RES);
	printf("Rotating a point full quarter around the x-axis\n");
	printf(GR"CURRENT TUPPLE MATRIX:\n"RES);
	print_matrix(p);
	result = multiply_matrices(full_quarter, p);
	printf(GR"RESULT:\n"RES);
	print_matrix(result);
	printf(B_B"##############################################################\n"CYAN);
	printf("##### TEST 3 #####\n"RES);
	printf(R_B"[INVERSE]"RES" Rotating a point half a quarter around the x-axis\n");
	printf(GR"CURRENT TUPPLE MATRIX:\n"RES);
	print_matrix(p);
	result = multiply_matrices(inverse, p);
	printf(GR"RESULT:\n"RES);
	print_matrix(result);
	free_matrix(p);
	free_matrix(result);
	free_matrix(half_quarter);
	free_matrix(full_quarter);
	free_matrix(inverse);
	return (0);
}

static int	rotate_y_test()
{
	t_matrix	*half_quarter = rotate_y(M_PI / 4);
	t_matrix	*full_quarter = rotate_y(M_PI / 2);
	t_tuple		*point = make_tuple(0, 0, 1, POINT);
	t_matrix	*p = tuple_to_matrix(point);
	t_matrix	*result = NULL;

	if (!half_quarter || !full_quarter || !point || !p)
	{
		printf("Error: one or more arguments are NULL\n");
		return (1);
	}
	printf(B_B"##############################################################\n");
	printf("################  [R O T A T I O N  Y]  #########################\n");
	printf("##############################################################\n"CYAN);
	printf("##### TEST 1 #####\n"RES);
	printf("Rotating a point half a quarter around the y-axis\n");
	printf(GR"CURRENT TUPPLE MATRIX:\n"RES);
	print_matrix(p);
	result = multiply_matrices(half_quarter, p);
	printf(GR"RESULT:\n"RES);
	print_matrix(result);
	printf(B_B"##############################################################\n"CYAN);
	printf("##### TEST 2 #####\n"RES);
	printf("Rotating a point full quarter around the y-axis\n");
	printf(GR"CURRENT TUPPLE MATRIX:\n"RES);
	print_matrix(p);
	result = multiply_matrices(full_quarter, p);
	printf(GR"RESULT:\n"RES);
	print_matrix(result);
	return (0);
}

static int	rotate_z_test()
{
	t_matrix	*half_quarter = rotate_z(M_PI / 4);
	t_matrix	*full_quarter = rotate_z(M_PI / 2);
	t_tuple		*point = make_tuple(0, 1, 0, POINT);
	t_matrix	*p = tuple_to_matrix(point);
	t_matrix	*result = NULL;

	if (!half_quarter || !full_quarter || !point || !p)
	{
		printf("Error: one or more arguments are NULL\n");
		return (1);
	}
	printf(B_B"##############################################################\n");
	printf("################  [R O T A T I O N  Z]  #########################\n");
	printf("##############################################################\n"CYAN);
	printf("##### TEST 1 #####\n"RES);
	printf("Rotating a point half a quarter around the z-axis\n");
	printf(GR"CURRENT TUPPLE MATRIX:\n"RES);
	print_matrix(p);
	result = multiply_matrices(half_quarter, p);
	printf(GR"RESULT:\n"RES);
	print_matrix(result);
	printf(B_B"##############################################################\n"CYAN);
	printf("##### TEST 2 #####\n"RES);
	printf("Rotating a point full quarter around the z-axis\n");
	printf(GR"CURRENT TUPPLE MATRIX:\n"RES);
	print_matrix(p);
	result = multiply_matrices(full_quarter, p);
	printf(GR"RESULT:\n"RES);
	print_matrix(result);
	return (0);
}

int	rotate_test(int x, int y, int z)
{
	if (x)
	{
		if (rotate_x_test())
		{
			printf("Error: rotate_x_test failed\n");
			return (1);
		}
	}
	if (y)
	{
		if (rotate_y_test())
		{
			printf("Error: rotate_y_test failed\n");
			return (1);
		}
	}
	if (z)
	{
		if (rotate_z_test())
		{
			printf("Error: rotate_z_test failed\n");
			return (1);
		}
	}
	return (0);
}

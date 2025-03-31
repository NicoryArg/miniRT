/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:49:03 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/26 16:00:23 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static int	rotate_x_test()
{
	int	i = 1;
	t_matrix	*half_quarter = rotate_x(M_PI / 4);
	t_matrix	*full_quarter = rotate_x(M_PI / 2);
	t_matrix	*inverse = invert_matrix(half_quarter);
	t_tuple		*point = ft_tuple(0, 1, 0, POINT);
	t_matrix	*p = tuple_to_matrix(point);
	t_matrix	*result = NULL;

	if (!half_quarter || !full_quarter || !point || !p)
	{
		printf("Error: one or more arguments are NULL\n");
		return (1);
	}
	print_test_banner("X ROTATION");
	print_test_number(&i);
	printf("Rotating a point half a quarter around the x-axis\n");
	printf(GR"CURRENT TUPPLE MATRIX:\n"RES);
	print_matrix(p);
	result = multiply_matrices(half_quarter, p);
	printf(GR"RESULT:\n"RES);
	print_matrix(result);
	print_test_number(&i);
	printf("Rotating a point full quarter around the x-axis\n");
	printf(GR"CURRENT TUPPLE MATRIX:\n"RES);
	print_matrix(p);
	result = multiply_matrices(full_quarter, p);
	printf(GR"RESULT:\n"RES);
	print_matrix(result);
	print_test_number(&i);
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
	int	i = 1;
	t_matrix	*half_quarter = rotate_y(M_PI / 4);
	t_matrix	*full_quarter = rotate_y(M_PI / 2);
	t_tuple		*point = ft_tuple(0, 0, 1, POINT);
	t_matrix	*p = tuple_to_matrix(point);
	t_matrix	*result = NULL;

	if (!half_quarter || !full_quarter || !point || !p)
	{
		printf("Error: one or more arguments are NULL\n");
		return (1);
	}
	print_test_banner("Y ROTATION");
	print_test_number(&i);

	printf("Rotating a point half a quarter around the y-axis\n");
	printf(GR"CURRENT TUPPLE MATRIX:\n"RES);
	print_matrix(p);
	result = multiply_matrices(half_quarter, p);
	printf(GR"RESULT:\n"RES);
	print_matrix(result);

	print_test_number(&i);
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
	int	i = 1;
	t_matrix	*half_quarter = rotate_z(M_PI / 4);
	t_matrix	*full_quarter = rotate_z(M_PI / 2);
	t_tuple		*point = ft_tuple(0, 1, 0, POINT);
	t_matrix	*p = tuple_to_matrix(point);
	t_matrix	*result = NULL;

	if (!half_quarter || !full_quarter || !point || !p)
	{
		printf("Error: one or more arguments are NULL\n");
		return (1);
	}
	print_test_banner("Z ROTATION");
	print_test_number(&i);
	printf("Rotating a point half a quarter around the z-axis\n");
	printf(GR"CURRENT TUPPLE MATRIX:\n"RES);
	print_matrix(p);
	result = multiply_matrices(half_quarter, p);
	printf(GR"RESULT:\n"RES);
	print_matrix(result);
	print_test_number(&i);
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

//############################################################
//############################################################
//################# SCALE & TRANSLATE ########################
//############################################################
//############################################################

//TRANSLATE TEST
int	translate_test(int run)
{
	if (run == 0)
		return (0);
	int	i = 1;
	t_matrix	*transform = translate(5, -3, 2);
	t_matrix	*inverse = invert_matrix(transform);
	t_matrix	*result = NULL;
	t_tuple		*point = ft_tuple(-3, 4, 5, POINT);
	t_tuple		*vector = ft_tuple(-3, 4, 5, VECTOR);
	t_matrix	*p = tuple_to_matrix(point);

	if (!transform || !point || !inverse)
	{
		printf("Error: one or more arguments are NULL\n");
		return (1);
	}
	print_test_banner("TRANSLATION");
	print_test_number(&i);
	printf("Multiplying `p` by translation matrix\n");
	printf(GR"CURRENT TUPPLE MATRIX:\n"RES);
	print_matrix(p);
	result = multiply_matrices(transform, p);
	printf(GR"RESULT:\n"RES);
	print_matrix(result);
	free_matrix(p);
	p = result;
	print_test_number(&i);
	printf(GR"CURRENT TUPPLE MATRIX:\n"RES);
	print_matrix(p);
	printf("multiplying by inverse matrix:\n");
	result = multiply_matrices(inverse, p);
	printf(GR"RESULT:\n"RES);
	print_matrix(result);
	free_matrix(result);
	print_test_number(&i);
	p = tuple_to_matrix(vector);
	printf(GR"CURRENT TUPPLE MATRIX:\n"RES);
	print_matrix(p);
	printf("Multiplying vector by tranlation matrix:\n");
	result = multiply_matrices(transform, p);
	printf(GR"RESULT:\n"RES);
	print_matrix(result);
	free(point);
	free_matrix(transform);
	free_matrix(inverse);
	return (0);
}

//SCALE TEST
int	scale_test(int run)
{
	if (run == 0)
		return (0);
	int	i = 1;
	t_matrix	*transform = scale(2, 3, 4);
	t_matrix	*inverse = invert_matrix(transform);
	t_matrix	*result = NULL;
	t_tuple		*point = ft_tuple(-4, 6, 8, POINT);
	t_tuple		*vector = ft_tuple(-4, 6, 8, VECTOR);
	t_matrix	*p = tuple_to_matrix(point);
	t_matrix	*v = tuple_to_matrix(vector);

	if (!transform || !point || !inverse || !p || !v)
	{
		printf("Error: one or more arguments are NULL\n");
		return (1);
	}
	print_test_banner("SCALE");
	print_test_number(&i);
	printf("Multiplying a POINT by scaling matrix\n");
	printf(GR"CURRENT TUPPLE MATRIX:\n"RES);
	print_matrix(p);
	result = multiply_matrices(transform, p);
	printf(GR"RESULT:\n"RES);
	print_matrix(result);
	print_test_number(&i);
	printf("Multiplying a VECTOR by scaling matrix\n");
	printf(GR"CURRENT TUPPLE MATRIX:\n"RES);
	print_matrix(v);
	result = multiply_matrices(transform, v);
	printf(GR"RESULT:\n"RES);
	print_matrix(result);
	print_test_number(&i);
	printf("Multiplying a VECTOR by inverse scaling matrix\n");
	printf(GR"CURRENT TUPPLE MATRIX:\n"RES);
	print_matrix(v);
	result = multiply_matrices(inverse, v);
	printf(GR"RESULT:\n"RES);
	print_matrix(result);
	print_test_number(&i);
	printf("Reflection is scaling a POINT by a negative value\n");
	printf(GR"CURRENT TUPPLE MATRIX:\n"RES);
	free_matrix(transform);
	free(point);
	//adapt values to match example in book
	point = ft_tuple(2, 3, 4, POINT);
	p = tuple_to_matrix(point);
	print_matrix(p);
	transform = scale(-1, 1, 1);
	result = multiply_matrices(transform, p);
	printf(GR"RESULT:\n"RES);
	print_matrix(result);
	free_matrix(p);
	free_matrix(v);
	free_matrix(transform);
	free_matrix(inverse);
	return (0);
}



//############################################################
//############################################################
//################# CHAINED TRANSFORM ########################
//############################################################
//############################################################


int	chained_test(int run)
{
	if (run == 0)
	return (0);
	int	i = 1;
	t_matrix	*p = tuple_to_matrix(ft_tuple(1, 0, 1, POINT));
	t_matrix	*A = rotate_x(M_PI/2);
	t_matrix	*B = scale(5, 5, 5);
	t_matrix	*C = translate(10, 5, 7);

	print_test_banner("CHAINED");
	print_test_number(&i);
	printf("Applying transformations one by one\n");
	printf(GR"CURRENT TUPPLE MATRIX:\n"RES);
	print_matrix(p);
	printf(GR"rotating..\n"RES);
	t_matrix	*p2 = multiply_matrices(A, p);
	print_matrix(p2);
	printf(GR"scaling..\n"RES);
	t_matrix	*p3 = multiply_matrices(B, p2);
	print_matrix(p3);
	printf(GR"translating..\n"RES);
	t_matrix	*p4 = multiply_matrices(C, p3);
	print_matrix(p4);
	print_test_number(&i);
	printf("Chaining transformations in one\n");
	t_matrix	*T = multiply_matrices(C, B);
	T = multiply_matrices(T, A);
	printf("T Matrix:\n");
	print_matrix(T);
	printf("applying T matrix to p\n");
	p = multiply_matrices(T, p);
	print_matrix(p);
	return (0);
}

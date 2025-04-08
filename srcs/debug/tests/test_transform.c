/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:49:03 by ameechan          #+#    #+#             */
/*   Updated: 2025/04/08 13:13:08 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static int	rotate_x_test()
{
	int	i = 1;
	t_matrix	*half_quarter = rotate_x(M_PI / 4);
	t_matrix	*full_quarter = rotate_x(M_PI / 2);
	t_matrix	*inverse = invert_matrix(half_quarter);
	t_tuple		point = ft_tuple(0, 1, 0, POINT);
	t_matrix	*p = tuple_to_matrix(point);
	t_matrix	*result = NULL;

	if (!half_quarter || !full_quarter || !p)
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
	t_tuple		point = ft_tuple(0, 0, 1, POINT);
	t_matrix	*p = tuple_to_matrix(point);
	t_matrix	*result = NULL;

	if (!half_quarter || !full_quarter || !p)
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
	t_tuple		point = ft_tuple(0, 1, 0, POINT);
	t_matrix	*p = tuple_to_matrix(point);
	t_matrix	*result = NULL;

	if (!half_quarter || !full_quarter || !p)
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
	t_matrix	*inverse;
	t_matrix	*result = NULL;
	t_tuple		point = ft_tuple(-3, 4, 5, POINT);
	t_tuple		vector = ft_tuple(-3, 4, 5, VECTOR);
	t_matrix	*p = tuple_to_matrix(point);
	t_matrix	*expected_p = create_matrix(4, 1, 0);
	t_matrix	*v;
	t_matrix	*expected_v = create_matrix(4, 1, 0);

//TEST 1
	//print banners
	print_test_banner("TRANSLATION");
	print_test_number(&i);
	//initiate variables
	expected_p->values[0][0] = 2;
	expected_p->values[1][0] = 1;
	expected_p->values[2][0] = 7;
	expected_p->values[3][0] = 1;
	//run test
	result = multiply_matrices(transform, p);
	//print output
	printf("Multiplying `p` by translation matrix\n");
	printf(B_B"RESULT:\n"RES);
	print_matrix(result);
	printf(GR"EXPECTED:\n"RES);
	print_matrix(expected_p);
	//check output
	if (equal_matrix(result, expected_p))
		printf(GR"✔ values match\n"RES);
	else
		return(printf(AKA"❌ values don't match\n"RES));
//TEST 2
	//print banner
	print_test_number(&i);
	//redfine variables
	inverse = invert_matrix(transform);
	//run test
	result = multiply_matrices(inverse, result);
	//print output
	printf("multiplying by inverse matrix:\n");
	printf(B_B"RESULT:\n"RES);
	print_matrix(result);
	printf(GR"EXPECTED:\n"RES);
	print_matrix(p);
	//check output
	if (equal_matrix(result, p))
		printf(GR"✔ values match\n"RES);
	else
		return(printf(AKA"❌ values don't match\n"RES));
	//free resources
	free_matrix(result);
	free_matrix(p);
	free_matrix(expected_p);
//TEST 3
	//print banners
	print_test_number(&i);
	//initiate variables
	v = tuple_to_matrix(vector);
	expected_v->values[0][0] = -3;
	expected_v->values[1][0] = 4;
	expected_v->values[2][0] = 5;
	expected_v->values[3][0] = 0;
	//run test
	result = multiply_matrices(transform, v);
	//print ou tput
	printf("Multiplying vector by tranlation matrix:\n");
	printf(B_B"RESULT:\n"RES);
	print_matrix(result);
	printf(GR"EXPECTED:\n"RES);
	print_matrix(expected_v);
	//check output
	if (equal_matrix(result, expected_v))
		printf(GR"✔ values match\n"RES);
	else
		return(printf(AKA"❌ values don't match\n"RES));
	//free resources
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
	t_tuple		point = ft_tuple(-4, 6, 8, POINT);
	t_tuple		vector = ft_tuple(-4, 6, 8, VECTOR);
	t_matrix	*p = tuple_to_matrix(point);
	t_matrix	*v = tuple_to_matrix(vector);

	if (!transform || !inverse || !p || !v)
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

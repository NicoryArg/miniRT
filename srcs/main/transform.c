/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:23:55 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/06 12:44:55 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

//#############################################################################
//#############################################################################
//##########################  TRANSLATION  ####################################
//#############################################################################
//#############################################################################

static int	translate_test()
{
	t_matrix	*transform = translate(5, -3, 2);
	t_matrix	*inverse = invert_matrix(transform);
	t_matrix	*result = NULL;
	t_tuple		*point = make_tuple(-3, 4, 5, POINT);
	t_tuple		*vector = make_tuple(-3, 4, 5, VECTOR);
	t_matrix	*p = tuple_to_matrix(point);

	if (!transform || !point || !inverse)
	{
		printf("Error: one or more arguments are NULL\n");
		return (1);
	}
	printf(B_B"##############################################################\n");
	printf("################  T R A N S L A T I O N  #####################\n");
	printf("##############################################################\n"CYAN);
	printf("##### TEST 1 #####\n"RES);
	printf("Multiplying `p` by translation matrix\n");
	printf(GR"CURRENT TUPPLE MATRIX:\n"RES);
	print_matrix(p);
	result = multiply_matrices(transform, p);
	printf(GR"RESULT:\n"RES);
	print_matrix(result);
	free_matrix(p);
	p = result;
	printf(B_B"##############################################################\n");
	printf(CYAN"##### TEST 2 #####\n"RES);
	printf(GR"CURRENT TUPPLE MATRIX:\n"RES);
	print_matrix(p);
	printf("multiplying by inverse matrix:\n");
	result = multiply_matrices(inverse, p);
	printf(GR"RESULT:\n"RES);
	print_matrix(result);
	free_matrix(result);
	printf(B_B"##############################################################\n");
	printf(CYAN"##### TEST 3 #####\n"RES);
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

static int	scale_test()
{
	t_matrix	*transform = scale(2, 3, 4);
	t_matrix	*inverse = invert_matrix(transform);
	t_matrix	*result = NULL;
	t_tuple		*point = make_tuple(-4, 6, 8, POINT);
	t_tuple		*vector = make_tuple(-4, 6, 8, VECTOR);
	t_matrix	*p = tuple_to_matrix(point);
	t_matrix	*v = tuple_to_matrix(vector);

	if (!transform || !point || !inverse || !p || !v)
	{
		printf("Error: one or more arguments are NULL\n");
		return (1);
	}
	printf(B_B"##############################################################\n");
	printf("################      S C A L I N G      #####################\n");
	printf("##############################################################\n"CYAN);
	printf("##### TEST 1 #####\n"RES);
	printf("Multiplying a POINT by scaling matrix\n");
	printf(GR"CURRENT TUPPLE MATRIX:\n"RES);
	print_matrix(p);
	result = multiply_matrices(transform, p);
	printf(GR"RESULT:\n"RES);
	print_matrix(result);
	printf(B_B"##############################################################\n"CYAN);
	printf("##### TEST 2 #####\n"RES);
	printf("Multiplying a VECTOR by scaling matrix\n");
	printf(GR"CURRENT TUPPLE MATRIX:\n"RES);
	print_matrix(v);
	result = multiply_matrices(transform, v);
	printf(GR"RESULT:\n"RES);
	print_matrix(result);
	printf(B_B"##############################################################\n");
	printf(CYAN"##### TEST 3 #####\n"RES);
	printf("Multiplying a VECTOR by inverse scaling matrix\n");
	printf(GR"CURRENT TUPPLE MATRIX:\n"RES);
	print_matrix(v);
	result = multiply_matrices(inverse, v);
	printf(GR"RESULT:\n"RES);
	print_matrix(result);
	printf(B_B"##############################################################\n"CYAN);
	printf("##### TEST 4 #####\n"RES);
	printf("Reflection is scaling a POINT by a negative value\n");
	printf(GR"CURRENT TUPPLE MATRIX:\n"RES);
	print_matrix(p);
	free_matrix(transform);
	free(point);
	//adapt values to match example in book
	point = make_tuple(2, 3, 4, POINT);
	p = tuple_to_matrix(point);
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
	t_matrix	*half_quarter = rotate_x(M_PI / 4);
	t_matrix	*full_quarter = rotate_x(M_PI / 2);
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

int	main(void)
{
	// if (translate_test())
	// {
	// 	printf("Error: translate_test failed\n");
	// 	return (1);
	// }
	// if (scale_test())
	// {
	// 	printf("Error: scale_test failed\n");
	// 	return (1);
	// }
	if (rotate_x_test())
	{
		printf("Error: rotate_x_test failed\n");
		return (1);
	}
	if (rotate_y_test())
	{
		printf("Error: rotate_y_test failed\n");
		return (1);
	}
	(void)translate_test;
	(void)scale_test;
	(void)rotate_x_test;
	return (0);
}

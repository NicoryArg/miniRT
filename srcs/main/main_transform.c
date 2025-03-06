/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:23:55 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/06 15:13:59 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	translate_test(int run)
{
	if (run == 0)
		return (0);
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

int	scale_test(int run)
{
	if (run == 0)
		return (0);
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
	free_matrix(transform);
	free(point);
	//adapt values to match example in book
	point = make_tuple(2, 3, 4, POINT);
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

// int	main(void)
// {
// 	if (translate_test(0)) //1 to run , 0 to skip
// 		printf("Error: translate_test failed\n");
// 	if (scale_test(0))	//1 to run, 0 to skip
// 		printf("Error: scale_test failed\n");
// 	if (rotate_test(0, 0, 0)) //1 to run, 0 to skip
// 		printf("Error: rotate_test failed\n");
//	printf(R_B"END OF TESTS\n"RES);
// 	return (0);
// }

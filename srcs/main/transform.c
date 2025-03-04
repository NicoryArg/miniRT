/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:23:55 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/04 15:50:00 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

//#############################################################################
//#############################################################################
//##########################  TRANSLATION  ####################################
//#############################################################################
//#############################################################################
int	main(void)
{
	t_matrix	*transform = translate(5, -3, 2);
	t_matrix	*inverse = invert_matrix(transform);
	t_matrix	*p;
	t_matrix	*result;
	t_tuple		*point = make_tuple(-3, 4, 5, POINT);
	t_tuple		*vector = make_tuple(-3, 4, 5, VECTOR);

	if (!transform || !point || !inverse)
	{
		printf("Error: one or more arguments are NULL\n");
		return (1);
	}
	printf("##############################################################\n");
	printf("##### TEST 1 #####\n");
	printf("Multiplying `p` by translation matrix\n");
	p = tuple_to_matrix(point);
	printf("CURRENT TUPPLE MATRIX:\n");
	print_matrix(p);
	result = multiply_matrices(transform, p);
	printf("RESULT:\n");
	print_matrix(result);
	free_matrix(p);
	p = result;
	printf("##############################################################\n");
	printf("##### TEST 2 #####\n");
	printf("CURRENT TUPPLE MATRIX:\n");
	print_matrix(p);
	printf("multiplying by inverse matrix:\n");
	result = multiply_matrices(inverse, p);
	printf("RESULT:\n");
	print_matrix(result);
	free_matrix(result);
	printf("##############################################################\n");
	printf("##### TEST 3 #####\n");
	p = tuple_to_matrix(vector);
	printf("CURRENT TUPPLE MATRIX:\n");
	print_matrix(p);
	printf("Multiplying vector by tranlation matrix:\n");
	result = multiply_matrices(transform, p);
	printf("RESULT:\n");
	print_matrix(result);

	printf("##############################################################\n");
	free(point);
	free_matrix(transform);
	free_matrix(inverse);
	return (0);
}

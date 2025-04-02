/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tuples.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:55:49 by ameechan          #+#    #+#             */
/*   Updated: 2025/04/01 15:13:09 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

int	t_matrix_to_tuple(int run)
{
	if (run == 0)
		return (0);
	t_tuple	a = ft_tuple(1, 2, 3, VECTOR);
	t_tuple	b = ft_tuple(4, 5, 6, POINT);
	t_matrix	*ab = tuple_to_matrix(a);

	if (!ab)
	{
		printf("Error: Malloc Failure (t_matrix_to_tuple)\n");
		return (1);
	}
	print_test_banner("Matrix to Tuple");
	print_tuple(b, "b");
	printf(B_B"converting a to matrix\n"RES);
	print_matrix(ab);
	printf(B_B"Converting matrix back to tupple and overwritting b\n"RES);
	b = matrix_to_tuple(ab);
	print_tuple(b, "b");
	free_matrix(ab);
	return (0);
}

int	t_tuple_to_matrix(int run)
{
	if (run == 0)
		return (0);
	t_tuple 	a = ft_tuple(89, -20, 69, VECTOR);
	t_matrix	*mat = create_matrix(4, 1, 1);

	print_test_banner("Tuple to Matrix");
	print_tuple(a, "a");
	printf(GR"Matrix:\n"RES);
	print_matrix(mat);
	printf(B_B"converting tuple `a` to matrix..\n"RES);
	mat = tuple_to_matrix(a);
	printf(GR"RESULT:\n"RES);
	print_matrix(mat);
	return (0);
}

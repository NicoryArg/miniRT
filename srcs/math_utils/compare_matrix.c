/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:22:52 by nryser            #+#    #+#             */
/*   Updated: 2025/02/24 20:23:04 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	compare_matrices(t_matrix *a, t_matrix *b)
{
	int		i;
	int		j;

	if (a->rows != b->rows || a->cols != b->cols)
	{
		return (0);
	}
	i = 0;
	while (i < a->rows)
	{
		j = 0;
		while (j < a->cols)
		{
			if (!ft_equal(a->values[i][j], b->values[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
// int	main()
// {
// 	t_matrix	*a;
// 	t_matrix	*b;
// 	int			result;

// 	a = create_matrix(3, 3, 0);
// 	b = create_matrix(3, 3, 0);
// 	printf("\nFill matrix A:\n");
// 	fill_matrix(a);
// 	printf("\nFill matrix B:\n");
// 	fill_matrix(b);
// 	printf("\nMatrix A:\n");
// 	print_matrix(a);
// 	printf("\nMatrix B:\n");
// 	print_matrix(b);
// 	result = compare_matrices(a, b);
// 	if (result == 1)
// 		printf("\nMatrices are equal.\n");
// 	else
// 		printf("\nMatrices are NOT equal.\n");
// 	free_matrix(a);
// 	free_matrix(b);
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:05:31 by nryser            #+#    #+#             */
/*   Updated: 2025/02/24 17:05:36 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	compare_matrices(double **a, double **b, int rows, int cols)
{
	int		i;
	int		j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (a[i][j] != b[i][j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

// int	main()
// {
// 	int		rows;
// 	int		cols;
// 	double	**a;
// 	double	**b;
// 	int		result;

// 	printf("Enter number of rows: ");
// 	scanf("%d", &rows);
// 	printf("Enter number of columns: ");
// 	scanf("%d", &cols);
// 	a = allocate_matrix(rows, cols);
// 	b = allocate_matrix(rows, cols);
// 	printf("\nFill matrix A:\n");
// 	fill_matrix(a, rows, cols);
// 	printf("\nFill matrix B:\n");
// 	fill_matrix(b, rows, cols);
// 	printf("\nMatrix A:\n");
// 	print_matrix(a, rows, cols);
// 	printf("\nMatrix B:\n");
// 	print_matrix(b, rows, cols);
// 	result = compare_matrices(a, b, rows, cols);
// 	if (result == 1)
// 		printf("\nMatrices are equal.\n");
// 	else
// 		printf("\nMatrices are NOT equal.\n");
// 	free_matrix(a, rows);
// 	free_matrix(b, rows);
// 	return (0);
// }

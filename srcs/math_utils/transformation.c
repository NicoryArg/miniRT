/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:25:42 by nryser            #+#    #+#             */
/*   Updated: 2025/02/24 17:26:29 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "create_matrix.c"

static void	compute_product_matrix(double **a, double **b, double **result, int sizes[3])
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < sizes[0])
	{
		j = 0;
		while (j < sizes[2])
		{
			result[i][j] = 0;
			k = 0;
			while (k < sizes[1])
			{
				result[i][j] += a[i][k] * b[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
}

double	**multiply_matrices(double **a, double **b, int sizes[3])
{
	double	**result;

	result = allocate_matrix(sizes[0], sizes[2]);
	compute_product_matrix(a, b, result, sizes);
	return (result);
}

// int	main(void)
// {
// 	int		sizes[3];
// 	double	**a;
// 	double	**b;
// 	double	**result;

// 	printf("Enter number of rows for matrix A: ");
// 	scanf("%d", &sizes[0]); // rows_a
// 	printf("Enter number of columns for matrix A (must match rows of B): ");
// 	scanf("%d", &sizes[1]); // cols_a (common dimension)
// 	printf("Enter number of columns for matrix B: ");
// 	scanf("%d", &sizes[2]); // cols_b
// 	a = allocate_matrix(sizes[0], sizes[1]);
// 	b = allocate_matrix(sizes[1], sizes[2]);
// 	printf("\nFill matrix A:\n");
// 	fill_matrix(a, sizes[0], sizes[1]);
// 	printf("\nFill matrix B:\n");
// 	fill_matrix(b, sizes[1], sizes[2]);
// 	printf("\nMatrix A:\n");
// 	print_matrix(a, sizes[0], sizes[1]);
// 	printf("\nMatrix B:\n");
// 	print_matrix(b, sizes[1], sizes[2]);
// 	result = multiply_matrices(a, b, sizes);
// 	printf("\nResult of A * B:\n");
// 	print_matrix(result, sizes[0], sizes[2]);
// 	free_matrix(a, sizes[0]);
// 	free_matrix(b, sizes[1]);
// 	free_matrix(result, sizes[0]);
// 	return (0);
// }

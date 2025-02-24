/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:25:47 by nryser            #+#    #+#             */
/*   Updated: 2025/02/24 18:34:35 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
//#include "create_matrix.c"

static void	compute_product_matrix(t_matrix *a, t_matrix *b, t_matrix *result)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < a->rows)
	{
		j = 0;
		while (j < b->cols)
		{
			result->values[i][j] = 0;
			k = 0;
			while (k < a->cols)
			{
				result->values[i][j] += a->values[i][k] * b->values[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
}

t_matrix	*multiply_matrices(t_matrix *a, t_matrix *b)
{
	t_matrix	*result;

	if (a->cols != b->rows)
	{
		printf("Error: Matrices cannot be multiplied (A columns != B rows)\n");
		return (NULL);
	}
	result = create_matrix(a->rows, b->cols, 0);
	compute_product_matrix(a, b, result);
	return (result);
}

t_matrix	*submatrix(t_matrix *matrix, int remove_row, int remove_col)
{
	t_matrix	*result;

	if (matrix->rows < 2 || matrix->cols < 2)
	{
		printf("Error:not valid matrix smaller than 2x2.\n");
		return (NULL);
	}
	result = create_matrix(matrix->rows - 1, matrix->cols - 1, 0);
	copy_submatrix_values(matrix, result, remove_row, remove_col);
	return (result);
}

// int	main()
// {
// 	//main to test submatrix
// 	t_matrix	*a;
// 	t_matrix	*sub;
// 	int			rows;
// 	int			cols;
// 	int			remove_row;
// 	int			remove_col;

// 	printf("Enter number of rows for matrix A: ");
// 	scanf("%d", &rows);
// 	printf("Enter number of columns for matrix A: ");
// 	scanf("%d", &cols);
// 	a = create_matrix(rows, cols, 0);
// 	printf("\nFill matrix A:\n");
// 	fill_matrix(a);
// 	printf("\nMatrix A:\n");
// 	print_matrix(a);
// 	if (rows < 2 || cols < 2)
// 	{
// 		printf("\nError: Cannot extract a
//			submatrix from a matrix smaller than 2x2.\n");
// 		free_matrix(a);
// 		return (1);
// 	}
// 	printf("\nEnter the row and column to remove: ");
// 	scanf("%d %d", &remove_row, &remove_col);
// 	if (remove_row < 0 || remove_row >= rows
//			|| remove_col < 0 || remove_col >= cols)
// 	{
// 		printf("\nError: Row or column out of bounds.\n");
// 		free_matrix(a);
// 		return (1);
// 	}
// 	sub = submatrix(a, remove_row, remove_col);
// 	if (sub)
// 	{
// 		printf("\nSubmatrix (without row %d and column %d):\n",
//			remove_row, remove_col);
// 		print_matrix(sub);
// 		free_matrix(sub);
// 	}
// 	free_matrix(a);
// 	return (0);
// }

/////////////////////////////////////////////////////
// int	main()
// {
// 	//main to test matrix multiplication
// 	int			rows_a;
// 	int			cols_a;
// 	int			cols_b;
// 	t_matrix	*a;
// 	t_matrix	*b;
// 	t_matrix	*result;

// 	printf("Enter number of rows for matrix A: ");
// 	scanf("%d", &rows_a);
// 	printf("Enter number of columns for matrix A (must match rows of B): ");
// 	scanf("%d", &cols_a);
// 	printf("Enter number of columns for matrix B: ");
// 	scanf("%d", &cols_b);
// 	a = create_matrix(rows_a, cols_a, 0);
// 	b = create_matrix(cols_a, cols_b, 0);
// 	printf("\nFill matrix A:\n");
// 	fill_matrix(a);
// 	printf("\nFill matrix B:\n");
// 	fill_matrix(b);
// 	printf("\nMatrix A:\n");
// 	print_matrix(a);
// 	printf("\nMatrix B:\n");
// 	print_matrix(b);
// 	result = multiply_matrices(a, b);
// 	if (result)
// 	{
// 		printf("\nResult of A * B:\n");
// 		print_matrix(result);
// 		free_matrix(result);
// 	}
// 	free_matrix(a);
// 	free_matrix(b);
// 	return (0);
// }

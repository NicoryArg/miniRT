/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:57:10 by nryser            #+#    #+#             */
/*   Updated: 2025/02/24 16:57:14 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	**allocate_matrix(int rows, int cols)
{
	int		i;
	double	**matrix;

	matrix = (double **)malloc(rows * sizeof(double *));
	if (matrix == NULL)
	{
		printf("Memory allocation failed!\n");
		exit(1);
	}
	i = 0;
	while (i < rows)
	{
		matrix[i] = (double *)malloc(cols * sizeof(double));
		if (matrix[i] == NULL)
		{
			printf("Memory allocation failed!\n");
			exit(1);
		}
		i++;
	}
	return (matrix);
}

void	fill_matrix(double **matrix, int rows, int cols)
{
	int		i;
	int		j;

	printf("Enter %d values for the %dx%d matrix:\n", rows * cols, rows, cols);
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			scanf("%lf", &matrix[i][j]);
			j++;
		}
		i++;
	}
}

void	print_matrix(double **matrix, int rows, int cols)
{
	int		i;
	int		j;

	i = 0;
	while (i < rows)
	{
		printf("|");
		j = 0;
		while (j < cols)
		{
			printf(" %-5.1f |", matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	free_matrix(double **matrix, int rows)
{
	int		i;

	i = 0;
	while (i < rows)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

// int	main(void)
// {
// 	int		rows;
// 	int		cols;
// 	double	**matrix;

// 	printf("Enter number of rows: ");
// 	scanf("%d", &rows);
// 	printf("Enter number of columns: ");
// 	scanf("%d", &cols);
// 	matrix = allocate_matrix(rows, cols);
// 	fill_matrix(matrix, rows, cols);
// 	printf("\nYour matrix:\n");
// 	print_matrix(matrix, rows, cols);
// 	free_matrix(matrix, rows);
// 	return (0);
// }

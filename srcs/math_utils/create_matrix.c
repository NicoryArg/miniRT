/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:22:14 by nryser            #+#    #+#             */
/*   Updated: 2025/02/24 20:22:31 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_matrix	*create_matrix(int rows, int cols, int is_tuple)
{
	t_matrix	*matrix;
	int			i;

	matrix = (t_matrix *)malloc(sizeof(t_matrix));
	if (!matrix)
		exit(1);
	matrix->rows = rows;
	matrix->cols = cols;
	matrix->is_tuple = is_tuple;
	matrix->is_identity = 0;
	matrix->values = (double **)malloc(rows * sizeof(double *));
	if (!matrix->values)
		exit(1);
	i = 0;
	while (i < rows)
	{
		matrix->values[i] = (double *)malloc(cols * sizeof(double));
		if (!matrix->values[i])
			exit(1);
		i++;
	}
	return (matrix);
}

void	fill_matrix(t_matrix *matrix)
{
	int		i;
	int		j;

	printf("Enter %d values for the %dx%d matrix:\n",
		matrix->rows * matrix->cols, matrix->rows, matrix->cols);
	i = 0;
	while (i < matrix->rows)
	{
		j = 0;
		while (j < matrix->cols)
		{
			scanf("%lf", &matrix->values[i][j]);
			j++;
		}
		i++;
	}
}

void	print_matrix(t_matrix *matrix)
{
	int		i;
	int		j;

	i = 0;
	while (i < matrix->rows)
	{
		printf("|");
		j = 0;
		while (j < matrix->cols)
		{
			if (matrix->values[i][j] == (int)matrix->values[i][j])
				printf(" %6.0f |", matrix->values[i][j]);
			else
				printf(" %10.5f |", matrix->values[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	free_matrix(t_matrix *matrix)
{
	int		i;

	i = 0;
	while (i < matrix->rows)
	{
		free(matrix->values[i]);
		i++;
	}
	free(matrix->values);
	free(matrix);
}

void	copy_submatrix_values(t_matrix *matrix, t_matrix *result,
			int remove_row, int remove_col)
{
	int	i;
	int	j;
	int	new_i;
	int	new_j;

	new_i = 0;
	i = 0;
	while (i < matrix->rows)
	{
		if (i == remove_row)
		{
			i++;
			continue ;
		}
		new_j = 0;
		j = 0;
		while (j < matrix->cols)
		{
			if (j != remove_col)
				result->values[new_i][new_j++] = matrix->values[i][j];
			j++;
		}
		new_i++;
		i++;
	}
}

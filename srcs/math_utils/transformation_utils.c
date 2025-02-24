/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:02:59 by nryser            #+#    #+#             */
/*   Updated: 2025/02/24 18:06:26 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "transformation.c"
#include "compare_matrix.c"

t_matrix	*create_identity_matrix(int size)
{
	int			i;
	int			j;
	t_matrix	*identity;

	identity = create_matrix(size, size, 0);
	identity->is_identity = 1;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i == j)
				identity->values[i][j] = 1.0;
			else
				identity->values[i][j] = 0.0;
			j++;
		}
		i++;
	}
	return (identity);
}

t_matrix	*multiply_by_identity(t_matrix *input)
{
	int			i;
	t_matrix	*result;
	t_matrix	*identity;

	if (input->is_tuple == 1)
	{
		result = create_matrix(1, input->cols, 1);
		i = 0;
		while (i < input->cols)
		{
			result->values[0][i] = input->values[0][i];
			i++;
		}
		return (result);
	}
	identity = create_identity_matrix(input->rows);
	result = multiply_matrices(input, identity);
	free_matrix(identity);
	return (result);
}

t_matrix	*transpose_matrix(t_matrix *input)
{
	int			i;
	int			j;
	t_matrix	*transposed;

	transposed = create_matrix(input->cols, input->rows, input->is_tuple);
	i = 0;
	while (i < input->rows)
	{
		j = 0;
		while (j < input->cols)
		{
			transposed->values[j][i] = input->values[i][j];
			j++;
		}
		i++;
	}
	return (transposed);
}

// int	main()
// {
// 	t_matrix	*a;
// 	t_matrix	*transposed;
// 	t_matrix	*identity;
// 	t_matrix	*identity_transposed;
// 	int			size;

// 	// Example for normal matrix
// 	printf("Enter the size of the square matrix: ");
// 	scanf("%d", &size);
// 	a = create_matrix(size, size, 0);
// 	printf("\nFill matrix A:\n");
// 	fill_matrix(a);
// 	printf("\nMatrix A:\n");
// 	print_matrix(a);
// 	transposed = transpose_matrix(a);
// 	printf("\nTransposed Matrix A:\n");
// 	print_matrix(transposed);

// 	// Example for identity matrix
// 	identity = create_identity_matrix(size);
// 	identity_transposed = transpose_matrix(identity);
// 	printf("\nIdentity Matrix:\n");
// 	print_matrix(identity);
// 	printf("\nTransposed Identity Matrix:\n");
// 	print_matrix(identity_transposed);

// 	// Check if transposing an identity matrix returns itself
// 	if (compare_matrices(identity, identity_transposed))
// 		printf("\nTranspose of identity matrix is still the identity matrix ✅\n");
// 	else
// 		printf("\nTranspose of identity matrix failed ❌\n");

// 	// Free memory
// 	free_matrix(a);
// 	free_matrix(transposed);
// 	free_matrix(identity);
// 	free_matrix(identity_transposed);
// 	return (0);
// }

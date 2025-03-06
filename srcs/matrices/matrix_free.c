/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:24:11 by nryser            #+#    #+#             */
/*   Updated: 2025/02/24 20:24:19 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

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
// 	if (equal_matrix(identity, identity_transposed))
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

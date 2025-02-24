/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:29:01 by nryser            #+#    #+#             */
/*   Updated: 2025/02/24 17:33:21 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "transformation.c"

double	**multiply_by_identity(double **input, int size, int is_tuple)
{
	int		i;
	int		j;
	double	**result;

	if (is_tuple == 1)
	{
		result = allocate_matrix(1, size);
		i = 0;
		while (i < size)
		{
			result[0][i] = input[0][i]; // Identity multiplication keeps tuple unchanged
			i++;
		}
	}
	else
	{
		result = allocate_matrix(size, size);
		i = 0;
		while (i < size)
		{
			j = 0;
			while (j < size)
			{
				if (i == j)
					result[i][j] = 1.0;
				else
					result[i][j] = 0.0;
				j++;
			}
			i++;
		}
		result = multiply_matrices(input, result, (int[]){size, size, size});
	}
	return (result);
}


int	main()
{
	int		size;
	double	**a;
	double	**identity;
	double	**result;

	printf("Enter the size of the square matrix: ");
	scanf("%d", &size);
	a = allocate_matrix(size, size);
	printf("\nFill matrix A:\n");
	fill_matrix(a, size, size);
	identity = create_identity_matrix(size);
	printf("\nMatrix A:\n");
	print_matrix(a, size, size);
	printf("\nIdentity Matrix:\n");
	print_matrix(identity, size, size);
	result = multiply_matrices(a, identity, (int[]){size, size, size});
	printf("\nA * Identity Matrix:\n");
	print_matrix(result, size, size);
	free_matrix(a, size);
	free_matrix(identity, size);
	free_matrix(result, size);
	return (0);
}

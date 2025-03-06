/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:53:12 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/06 15:08:52 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	print_tuple(t_tuple *tuple, char *name)
{
	if (is_vector(tuple))
		printf(GR"tuple `%s` is VECTOR:\n"RES, name);
	else if (is_point(tuple))
		printf(GR"tuple `%s` is POINT:\n"RES, name);
	else
		printf(R_B"ERROR:"RES" tuple type undefined\n");
	printf("w: %d\n", tuple->w);
	printf("x: %.5f\n", tuple->x);
	printf("y: %.5f\n", tuple->y);
	printf("z: %.5f\n", tuple->z);
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

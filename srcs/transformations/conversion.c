/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:52:31 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/06 14:49:25 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_matrix	*tuple_to_matrix(t_tuple *tup)
{
	t_matrix	*matrix;

	matrix = create_matrix(4, 1, 1);
	matrix->values[0][0] = tup->x;
	matrix->values[1][0] = tup->y;
	matrix->values[2][0] = tup->z;
	matrix->values[3][0] = tup->w;
	return(matrix);
}

t_tuple	*matrix_to_tuple(t_matrix *matrix)
{
	t_tuple	*tuple;
	double	x;
	double	y;
	double	z;

	x = matrix->values[0][0];
	y = matrix->values[1][0];
	z = matrix->values[2][0];
	tuple = make_tuple(x, y, z, matrix->values[3][0]);
	if (!tuple)
		return (NULL);
	return (tuple);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:20:47 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/24 15:55:06 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_matrix	*translate(double x, double y, double z)
{
	t_matrix	*matrix;

	matrix = create_identity_matrix(4);
	matrix->values[0][3] = x;
	matrix->values[1][3] = y;
	matrix->values[2][3] = z;
	return (matrix);
}

t_matrix	*scale(double x, double y, double z)
{
	t_matrix	*matrix;

	matrix = create_identity_matrix(4);
	matrix->values[0][0] = x;
	matrix->values[1][1] = y;
	matrix->values[2][2] = z;
	return (matrix);
}

t_matrix	*rotate_x(double rad)
{
	t_matrix	*matrix;

	matrix = create_identity_matrix(4);
	matrix->values[1][1] = cos(rad);
	matrix->values[1][2] = -sin(rad);
	matrix->values[2][1] = sin(rad);
	matrix->values[2][2] = cos(rad);
	return (matrix);
}

t_matrix	*rotate_y(double rad)
{
	t_matrix	*matrix;

	matrix = create_identity_matrix(4);
	matrix->values[0][0] = cos(rad);
	matrix->values[0][2] = sin(rad);
	matrix->values[2][0] = -sin(rad);
	matrix->values[2][2] = cos(rad);
	return (matrix);
}

t_matrix	*rotate_z(double rad)
{
	t_matrix	*matrix;

	matrix = create_identity_matrix(4);
	matrix->values[0][0] = cos(rad);
	matrix->values[0][1] = -sin(rad);
	matrix->values[1][0] = sin(rad);
	matrix->values[1][1] = cos(rad);
	return (matrix);
}

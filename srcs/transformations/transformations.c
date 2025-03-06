/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:20:47 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/06 11:45:44 by ameechan         ###   ########.fr       */
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

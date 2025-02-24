/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:51:06 by ameechan          #+#    #+#             */
/*   Updated: 2025/02/24 18:16:39 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	is_point(t_tuple *tuple)
{
	return (tuple->w == POINT);
}

bool	is_vector(t_tuple *tuple)
{
	return (tuple->w == VECTOR);
}

/**
 * @brief Compares if x, y, z coordinates of two tuples are equal
 * @return true if equal, false otherwise
 */
bool	equal_tuple(t_tuple *t1, t_tuple *t2)
{
	if (!t1 || !t2)
	{
		printf("[DEBUG] `equal_tuple` -> Empty tuple in comparison\n"); // debugging
		return (false);
	}
	if (ft_equal(t1->x, t2->x) && ft_equal(t1->y, t2->y) && ft_equal(t1->z, t2->z))
		return (true);
	return (false);
}

/**
 * @brief compares two values and returns true if the absolute
 * value of their difference is within EPSILON margin of error
 * @param EPSILON 0.00001
 */
bool	ft_equal(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (true);
	return (false);
}

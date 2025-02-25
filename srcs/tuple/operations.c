/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:47:13 by ameechan          #+#    #+#             */
/*   Updated: 2025/02/25 10:43:49 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/**
 * @brief adds coordinates of two tuples
 * @return a new tuple created from the addition of t1 & t2
 */
t_tuple	*add_tuple(t_tuple *t1, t_tuple *t2)
{
	t_tuple	*res;

	if (t1->w == POINT && t2->w == POINT)//						debugging
	{
		printf("[DEBUG] `add_tuple` -> can't add two points\n");
		exit(1);
	}
	res = new_tuple();
	if (!res)
		return (NULL);
	res->w = t1->w + t2->w;
	res->x = t1->x + t2->x;
	res->y = t1->y + t2->y;
	res->z = t1->z + t2->z;
	print_tuple(res, "res");//		debugging
	return (res);
}

/**
 * @brief substracts two tuples, returns an error if trying to substract
 * a point from a vector
 * @param points if both points, then the vector returned points
 * from t2 to t1
 * @param vectors if both vectors, then the vector returned
 * points from the tip of t2 to the tip of t1, in other words
 * it tells us the displacement needed to move from t2 to t1
 * @param other if (v-p) returns error, else if (p-v) returns another
 * point which has moved from t1 in the opposite direction of t2 (-v)
 *
 */
t_tuple	*diff_tuple(t_tuple *t1, t_tuple *t2)
{
	t_tuple *res;

	if (!t1 || !t2)
	{
		printf("[DEBUG] `diff_tuple` -> NULL tuple detected\n");//	debugging
		exit(1);
	}
	if (t1->w == VECTOR && t2->w == POINT)
	{
		printf("[DEBUG] `diff_tuple` -> Trying to substract point from vector\n");
		exit(1);
	}
	res = new_tuple();
	if (!res)
	{
		printf("[DEBUG] `diff_tuple` -> malloc failure\n");//		debugging
		return (NULL);
	}
	res->w = t1->w - t2->w;
	res->x = t1->x - t2->x;
	res->y = t1->y - t2->y;
	res->z = t1->z - t2->z;
	print_tuple(res, "res");//		debugging
	return (res);
}

/**
 * @brief Takes a vector and multiplies it by `t` ->
 * vectors multiplied or divided, increase or decrease in length by
 * a factor of `t` while maintaining their direction
 * @note can be used for division by setting t as `1/t`
 */
t_tuple	*ft_multiply(t_tuple *vector, double t)
{
	t_tuple	*res;

	if (!vector)
	{
		printf("[DEBUG] `ft_multiply` -> NULL tuple detected\n");//	debugging
		exit (1);
	}
	if (vector->w == POINT)
	{
		printf("[DEBUG] `ft_multiply` -> multiplying POINT\n");//	debugging
		exit (1);
	}
	res = new_tuple();
	if (!res)
	{
		printf("[DEBUG] `ft_multiply` -> malloc failure\n");//	debugging
		return (NULL);
	}
	res->w = vector->w;
	res->x = vector->x * t;
	res->y = vector->y * t;
	res->z = vector->z * t;
	return (res);
}

/**
 * @brief inverts the direction of a vector
 * @param tup expected to be a vector!
 */
void	ft_negate(t_tuple *tup)
{
	if (tup->w == POINT)
	{
		printf("[DEBUG] `negate_tuple` -> trying to negate POINT\n");//debugging
		exit (1);
	}
	tup->x = 0 - tup->x;
	tup->y = 0 - tup->y;
	tup->z = 0 - tup->z;
}

double	square(double x)
{
	return (x*x);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:28:17 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/22 16:59:31 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_ray	*ray(t_tuple *origin, t_tuple *direction)
{
	t_ray	*ray;

	ray = (t_ray *)malloc(sizeof(t_ray));
	if (!ray)
		malloc_err("ray");//	debugging
	ray->origin = origin;
	ray->direction = direction;
	return (ray);
}
/**
 * @brief Finds the point at the given distance `t` along `ray`
 */
t_tuple	*get_point(t_ray *ray, double t)
{
	t_tuple	*point;

	point = add_tuple(ray->origin, mult_tuple(ray->direction, t));
	return (point);
}

t_ray	*transform(t_ray *r, t_matrix *inverse)
{
	t_ray		*new;
	t_matrix	*temp;
	t_matrix	*ray_mtx;

	new = malloc(sizeof(t_ray));
	if (!new)
		malloc_err("transform");//	debugging
	temp = tuple_to_matrix(r->direction);
	ray_mtx = multiply_matrices(inverse, temp);
	new->direction = matrix_to_tuple(ray_mtx);
	free_matrix(temp);
	free_matrix(ray_mtx);
	temp = tuple_to_matrix(r->origin);
	ray_mtx = multiply_matrices(inverse, temp);
	new->origin = matrix_to_tuple(ray_mtx);
	free_matrix(temp);
	free_matrix(ray_mtx);
	free_matrix(inverse);
	return (new);
}

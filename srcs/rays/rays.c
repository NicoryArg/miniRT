/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:28:17 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/10 19:48:03 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_ray	*ray(t_tuple *origin, t_tuple *direction)
{
	t_ray	*ray;

	ray = (t_ray *)malloc(sizeof(t_ray));
	if (!ray)
	{
		printf(R_B"Error:"RES" failed to allocate memory for ray.\n");
		exit(1);
	}
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

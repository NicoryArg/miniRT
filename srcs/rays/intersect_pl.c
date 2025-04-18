/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_pl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:13:26 by ameechan          #+#    #+#             */
/*   Updated: 2025/04/18 14:38:30 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_inters	*intersect_pl(t_plane *pl, t_ray *ray, t_inters *xs)
{
	double	t;

	if (fabs(ray->direction.y) < 0.0001)
		return (xs);
	t = -ray->origin.y / ray->direction.y;
	xs->count = 1;
	xs->hits[0] = intersection(t, pl);
	return (xs);
}

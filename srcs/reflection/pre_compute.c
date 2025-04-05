/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_compute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:26:53 by ameechan          #+#    #+#             */
/*   Updated: 2025/04/05 12:40:05 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_computations	pre_compute(t_hit	*hit, t_ray *ray)
{
	t_computations	comps;

	comps.t = hit->t;
	comps.s = hit->object;
	comps.point = get_point(ray, comps.t);
	comps.eyev = ft_negate(ray->direction);
	comps.normalv = normal_at(comps.s, comps.point);
	if (dot(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = true;
		comps.normalv = ft_negate(comps.normalv);
	}
	else
		comps.inside = false;
	return (comps);
}

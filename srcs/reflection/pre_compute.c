/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_compute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:26:53 by ameechan          #+#    #+#             */
/*   Updated: 2025/04/06 01:03:03 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_computations	pre_compute(t_hit	*hit, t_ray *ray)
{
	t_computations	comps;

	comps.t = hit->t;
	comps.obj = hit->object;
	comps.point = get_point(ray, comps.t);
	comps.eyev = ft_negate(ray->direction);
	comps.normalv = normal_at(comps.obj, comps.point);
	print_tuple(comps.eyev, "eyev");
	print_tuple(comps.normalv, "normalv");
	if (dot(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = true;
		comps.normalv = ft_negate(comps.normalv);
	}
	else
		comps.inside = false;
	return (comps);
}

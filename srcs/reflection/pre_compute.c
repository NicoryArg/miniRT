/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_compute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:22:23 by nryser            #+#    #+#             */
/*   Updated: 2025/04/09 16:22:23 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_computations	pre_compute(t_hit	*hit, t_ray *ray)
{
	t_computations	comps;

	comps.t = hit->t;
	comps.obj = hit->obj;
	comps.point = get_point(ray, comps.t);
	comps.eyev = ft_negate(ray->direction);
	comps.normalv = normal_at(comps.obj, comps.point);
	if (dot(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = true;
		comps.normalv = ft_negate(comps.normalv);
	}
	else
		comps.inside = false;
	return (comps);
}

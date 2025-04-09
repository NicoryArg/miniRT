/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_compute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:45:34 by nryser            #+#    #+#             */
/*   Updated: 2025/04/09 17:45:34 by nryser           ###   ########.ch       */
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

t_colour	shade_hit(t_world *w, t_computations comps)
{
	t_shading	light_args;

	light_args.m = ((t_object *)comps.obj)->m;
	light_args.l = w->light;
	light_args.point = comps.point;
	light_args.eyev = comps.eyev;
	light_args.normalv = comps.normalv;
	return (ft_shading(light_args));
}

t_colour	color_at(t_world *world, t_ray *ray)
{
	t_inters		*xs;
	t_hit			*hit;
	t_computations	comps;
	t_colour		color;

	xs = intersect_world(world, ray);
	hit = find_visible_hit(xs->hits, xs->count);
	if (!hit)
		color = ft_colour(0, 0, 0);
	else
	{
		comps = pre_compute(hit, ray);
		color = shade_hit(world, comps);
	}
	free_hits(xs);
	return (color);
}

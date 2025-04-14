/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_compute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:40:53 by nryser            #+#    #+#             */
/*   Updated: 2025/04/09 18:41:00 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/**
 * @brief Prepares the data needed to shade an intersection.
 *
 * Computes the intersection point, eye vector, and normal vector.
 * Also determines if the hit occurred inside the object (i.e.,
 * if the normal vector needs to be flipped).
 *
 * @param hit The hit (intersection) information.
 * @param ray The ray that produced the intersection.
 * @return A t_computations struct containing precomputed data for shading.
 */
t_computations	pre_compute(t_hit	*hit, t_ray *ray)
{
	t_computations	comps;
	t_tuple			offset;

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
	offset = mult_tuple(comps.normalv, EPSILON);
	comps.over_point = add_tuple(comps.point, offset);
	return (comps);
}

/**
 * @brief Computes the color at the point of intersection.
 *
 * Uses the Phong reflection model (ambient, diffuse, specular)
 * to calculate the visible color at the intersection point
 * based on lighting, surface material, eye vector, and normal.
 *
 * @param world Pointer to the scene (objects + light).
 * @param comps Precomputed intersection information (position, normal, etc).
 * @return The final color at the intersection.
 */
t_colour	shade_hit(t_world *w, t_computations comps)
{
	t_shading	light_args;
	bool		in_shadow;

	light_args.m = ((t_object *)comps.obj)->m;
	light_args.l = w->light;
	light_args.point = comps.over_point;
	light_args.eyev = comps.eyev;
	light_args.normalv = comps.normalv;
	in_shadow = is_shadowed(w, comps.over_point);
	return (ft_shading(light_args, in_shadow));
}

/**
 * @brief Determines the color seen by a given ray in the world.
 *
 * Intersects the ray with the scene, finds the closest visible
 * intersection, and returns the color at that point using shading.
 * Returns black if no object is hit.
 *
 * @param world Pointer to the scene (objects + light).
 * @param ray The ray to trace from the camera/viewpoint.
 * @return The resulting color seen along the ray.
 */
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

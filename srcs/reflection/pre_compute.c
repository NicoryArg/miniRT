/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_compute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 03:55:49 by nryser            #+#    #+#             */
/*   Updated: 2025/04/28 04:01:00 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"

void	add_light_to_world(t_world *world, t_light *light)
{
	t_light	**new_lights;
	int		i;

	new_lights = malloc(sizeof(t_light *) * (world->light_count + 1));
	if (!new_lights)
		malloc_err("add_light_to_world");
	i = 0;
	while (i < world->light_count)
	{
		new_lights[i] = world->lights[i];
		i++;
	}
	new_lights[i] = light;
	if (world->lights)
		free(world->lights);
	world->lights = new_lights;
	world->light_count++;
}

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
t_computations	pre_compute(t_hit *hit, t_ray *ray)
{
	t_computations	comps;
	t_tuple			offset;
	bool			inside;

	comps.t = hit->t;
	comps.obj = hit->obj;
	comps.point = get_point(ray, hit->t);
	comps.eyev = ft_negate(ray->direction);
	comps.normalv = normal_at(hit->obj, comps.point);
	inside = (dot(comps.normalv, comps.eyev) < 0);
	comps.inside = inside;
	if (inside)
		comps.normalv = ft_negate(comps.normalv);
	offset = mult_tuple(comps.normalv, EPSILON);
	comps.over_point = add_tuple(comps.point, offset);
	return (comps);
}

static bool	check_shadow_hit(t_world *w, t_ray *r, double ligth_distance)
{
	t_hitlist	**xs;
	t_hit		*hit;
	bool		shadowed;

	xs = new_hitlist();
	intersect_world(w, r, xs);
	hit = find_visible_hit(xs);
	if (hit && hit->t < ligth_distance)
		shadowed = true;
	else
		shadowed = false;
	free_ray(r);
	free_hitlist(xs);
	return (shadowed);
}

bool	is_shadowed(t_world *w, t_tuple point, t_light *light)
{
	t_tuple		lightv;
	t_tuple		direction;
	t_ray		*r;
	double		light_distance;

	lightv = diff_tuple(light->pos, point);
	light_distance = magnitude(lightv);
	direction = normalize(lightv);
	r = ft_ray(add_tuple(point, mult_tuple(direction, EPSILON)), direction);
	return (check_shadow_hit(w, r, light_distance));
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
t_colour	shade_hit(t_world *w, t_computations comps, bool ignore_shadows)
{
	t_colour	final_color;
	t_shading	light_args;
	bool		in_shadow;
	int			i;

	final_color = ft_colour(0, 0, 0);
	i = 0;
	while (i < w->light_count)
	{
		light_args.m = ((t_object *)comps.obj)->m;
		light_args.l = w->lights[i];
		light_args.point = comps.over_point;
		light_args.eyev = comps.eyev;
		light_args.normalv = comps.normalv;
		light_args.obj = comps.obj;
		if (ignore_shadows)
			in_shadow = false;
		else
			in_shadow = is_shadowed(w, light_args.point, w->lights[i]);
		final_color = add_colours(final_color, ft_shading(light_args, in_shadow));
		i++;
	}
	final_color = mult_colour(final_color, 1.0 / w->light_count);
	final_color = clamp_colour(final_color);
	return (final_color);
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
t_colour	color_at(t_world *world, t_ray *ray, bool ignore_shadows)
{
	t_hitlist		**xs;
	t_hit			*hit;
	t_computations	comps;
	t_colour		color;

	xs = new_hitlist();
	// printf("intersect_world\n");
	intersect_world(world, ray, xs);
	// printf("find hit\n");
	hit = find_visible_hit(xs);
	if (!hit)
		color = ft_colour(0, 0, 0);
	else
	{
		// printf("pre comp\n");
		comps = pre_compute(hit, ray);
		// printf("shade hit\n");
		color = shade_hit(world, comps, ignore_shadows);
	}
	// printf("free hits\n");
	free_hitlist(xs);
	// printf("return color\n");
	return (color);
}

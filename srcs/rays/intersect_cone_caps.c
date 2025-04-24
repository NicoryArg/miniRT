/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone_caps.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:43:14 by nryser            #+#    #+#             */
/*   Updated: 2025/04/24 16:44:04 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"

#define CAP_EPSILON 1e-4

/**
 * @brief Determines whether a ray intersects a cone’s cap.
 *
 * This function calculates whether the point on the ray at distance `t`
 * lies within the radius of the cone's circular cap at the specified
 * y-level. This is used for validating cap intersections.
 *
 * @param ray The ray being tested for intersection.
 * @param t The distance along the ray to test.
 * @param y The y-coordinate of the cap being tested.
 * @return true if the point lies within the cap radius, false otherwise.
 */
bool	check_cone_cap(t_ray *ray, double t, double y)
{
	double	x;
	double	z;
	double	radius;
	double	dist2;
	double	limit;

	x = ray->origin.x + t * ray->direction.x;
	z = ray->origin.z + t * ray->direction.z;
	dist2 = x * x + z * z;
	radius = fabs(y);
	limit = radius * radius + CAP_EPSILON;
	return (dist2 <= limit);
}

/**
 * @brief Computes ray intersections with a closed cone’s end caps.
 *
 * This function tests whether a ray intersects the top or bottom circular
 * caps of a cone (if the cone is closed). It computes the intersection
 * point along the ray at each cap’s y-level and verifies if the point
 * lies within the valid radius.
 *
 * Valid intersections are added to the hit list.
 *
 * @param xs The list where valid intersections will be added.
 * @param cone The cone object being tested.
 * @param ray The ray in the cone’s local/object space.
 */
void	intersect_cone_caps(t_hitlist **xs, t_cone *cone, t_ray *ray)
{
	double	t;

	if (!cone->closed || fabs(ray->direction.y) < EPSILON)
		return ;
	t = (cone->min - ray->origin.y) / ray->direction.y;
	if (t >= 0 && check_cone_cap(ray, t, cone->min))
		add_hit(xs, intersection(t, cone));
	t = (cone->max - ray->origin.y) / ray->direction.y;
	if (t >= 0 && check_cone_cap(ray, t, cone->max))
		add_hit(xs, intersection(t, cone));
}

/**
 * @brief Computes the normal vector on the side surface of a cone.
 *
 * This helper function takes a point in object/local space and
 * calculates the normal vector for a cone's curved surface at that point.
 * The y-component is derived from the slope of the cone.
 *
 * @param lp The local-space point on the cone’s side.
 * @return A normalized normal vector for the side surface.
 */
// static t_tuple	cone_side_normal(t_tuple lp)
// {
// 	t_tuple	normal;
// 	double	y;

// 	y = sqrt(lp.x * lp.x + lp.z * lp.z);
// 	if (lp.y > 0)
// 		y = -y;
// 	normal = ft_tuple(lp.x, y, lp.z, VECTOR);
// 	return (normalize(normal));
// }

/**
 * @brief Computes the normal vector at a point on a cone.
 *
 * This function handles surface normals for both the side and caps
 * of a cone, accounting for transformations. The world-space point
 * is transformed to object space, and normals are computed accordingly:
 * - Returns (0, ±1, 0) if the point is on a cap.
 * - Returns (0, 0, 0) if the point is at the tip.
 * - Otherwise, delegates to `cone_side_normal` for the side surface.
 *
 * @param obj The cone object whose normal is being computed.
 * @param world_point The point in world space.
 * @return The normal vector at the given point on the cone.
 */
t_tuple normal_at_cone(t_object *obj, t_tuple world_point)
{
	t_cone		*cone;
	t_tuple		local_p;
	t_matrix	*inv;
	double		dist;
	double		y;

	cone = (t_cone *)obj;
	inv = invert_matrix(obj->transf);
	local_p = transform_world_to_object(world_point, inv);
	free_matrix(inv);

	dist = local_p.x * local_p.x + local_p.z * local_p.z;

	// Check if on the caps
	if (cone->closed)
	{
		if (fabs(local_p.y - cone->max) < EPSILON && dist <= fabs(cone->max) * fabs(cone->max))
			return (ft_tuple(0, 1, 0, VECTOR));
		if (fabs(local_p.y - cone->min) < EPSILON && dist <= fabs(cone->min) * fabs(cone->min))
			return (ft_tuple(0, -1, 0, VECTOR));
	}

	// Side normal
	y = sqrt(local_p.x * local_p.x + local_p.z * local_p.z);
	if (local_p.y > 0)
		y = -y;
	return (ft_tuple(local_p.x, y, local_p.z, VECTOR));
}


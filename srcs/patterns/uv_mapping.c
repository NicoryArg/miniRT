/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_mapping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:40:44 by nryser            #+#    #+#             */
/*   Updated: 2025/04/20 15:40:44 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"

/**
 * @brief Maps a point on a sphere to UV coordinates.
 *
 * The UV coordinates wrap around like a world globe:
 * - U goes from 0 to 1 horizontally (longitude)
 * - V goes from 0 to 1 vertically (latitude)
 *
 * @param point A point on the surface of a sphere (in object space).
 * @return A t_uv struct with u and v in [0,1] (longitude, latitude).
 */
t_uv	uv_spherical(t_tuple point)
{
	double	theta;
	double	radius;
	double	phi;
	t_uv	uv;

	theta = atan2(point.x, point.z);
	radius = sqrt(point.x * point.x + point.y * point.y + point.z * point.z);
	phi = acos(point.y / radius);
	uv.u = 1.0 - (theta + M_PI) / (2 * M_PI);
	uv.v = 1.0 - phi / M_PI;
	return (uv);
}

/**
 * @brief Maps a point on a plane (typically on Y=0) to UV coordinates.
 *
 * The X and Z coordinates wrap around to [0,1] using modulo logic.
 */
t_uv	uv_planar(t_tuple point)
{
	t_uv	uv;

	uv.u = point.x - floor(point.x);
	uv.v = point.z - floor(point.z);
	return (uv);
}

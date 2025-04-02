/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:43:14 by nryser            #+#    #+#             */
/*   Updated: 2025/03/25 18:43:14 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	discriminant(t_ray *ray, t_tuple sph_to_ray)
{
	double	a;
	double	b;
	double	c;
	double	discriminant;

	a = dot(ray->direction, ray->direction);
	b = 2 * dot(ray->direction, sph_to_ray);
	c = dot(sph_to_ray, sph_to_ray) - 1;
	discriminant = ft_sqr(b) - (4 * a * c);
	return (discriminant);
}

t_inters	*intersect_sph(t_sphere *sph, t_ray *ray, t_inters *xs)
{
	double	d;
	double	a;
	double	b;
	t_tuple	oc;
	int 	i;

	i = xs->count;
	oc = diff_tuple(ray->origin, sph->centre);
	d = discriminant(ray, oc);
	if (d < 0)
		return (xs);
	a = dot(ray->direction, ray->direction);
	b = 2 * dot(ray->direction, oc);
	xs->hits[i] = intersection(((-b - sqrt(d)) / (2 * a)), sph, SPHERE);
	xs->hits[i + 1] = intersection(((-b + sqrt(d)) / (2 * a)), sph, SPHERE);
	xs->count += 2;
	return (xs);
}

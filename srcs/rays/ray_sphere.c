/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:46:09 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/22 15:47:52 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	discriminant(t_ray *ray, t_tuple *sph_to_ray)
{
	double	a;
	double	b;
	double	c;
	double	discriminant;

	a = dot(ray->direction, ray->direction);
	b = 2 * dot(ray->direction, sph_to_ray);
	c = dot(sph_to_ray, sph_to_ray) - 1;
	discriminant = ft_sqr(b) - (4 * a * c);
	// printf(G_B"Discriminant: "RES"%.2f\n", discriminant);
	// printf(G_B"t1: "RES"%f\n", ((-b - sqrt(discriminant)) / (2 * a)));
	// printf(G_B"t2: "RES"%f\n", ((-b + sqrt(discriminant)) / (2 * a)));
	return (discriminant);
}

t_inters	*intersect_sph(t_sphere *sph, t_ray *ray, t_inters *xs)
{
	double	d;
	double	a;
	double	b;

	d = discriminant(ray, diff_tuple(ray->origin, sph->centre));
	if (d < 0)
		return (NULL);
	a = dot(ray->direction, ray->direction);
	b = 2 * dot(ray->direction, diff_tuple(ray->origin, sph->centre));
	xs->hits[0] = *intersection(((-b - sqrt(d)) / (2 * a)), sph, SPHERE);
	xs->hits[1] = *intersection(((-b + sqrt(d)) / (2 * a)), sph, SPHERE);
	xs->count += 2;
	return (xs);
}

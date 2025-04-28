/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:55:49 by nryser            #+#    #+#             */
/*   Updated: 2025/04/18 19:55:49 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"

double	discriminant_sph(t_ray *ray, t_tuple sph_to_ray)
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
/**
 * @brief prepend a new node that stores hit to hitlist
 */
void	add_hit(t_hitlist **xs, t_hit *hit)
{
	t_hitlist *new;

	new = malloc(sizeof(t_hitlist));
	if (!new)
		malloc_err("add_hit");
	new->hit = hit;
	new->next = *xs;
	*xs = new;
}

void	intersect_sph(t_sphere *sph, t_ray *ray, t_hitlist **xs)
{
	double	d;
	double	a;
	double	b;
	t_tuple	origin_centre;
	t_hit 	*t0;
	t_hit	*t1;

	origin_centre = diff_tuple(ray->origin, sph->centre);
	d = discriminant_sph(ray, origin_centre);
	if (d < 0)
		return ;
	a = dot(ray->direction, ray->direction);
	b = 2 * dot(ray->direction, origin_centre);
	t0 = intersection(((-b - sqrt(d)) / (2 * a)), sph);
	t1 = intersection(((-b + sqrt(d)) / (2 * a)), sph);
	add_hit(xs, t0);
	add_hit(xs, t1);
}

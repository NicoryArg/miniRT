/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cyl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:30:29 by ameechan          #+#    #+#             */
/*   Updated: 2025/04/19 15:18:47 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	ft_swap_t_cyl(t_cyl_vals *data)
{
	data->t0 = data->temp;
	data->t0 = data->t1;
	data->t1 = data->temp;
}

static void	validate(t_inters *xs, t_cylinder *cyl, t_ray *ray, t_cyl_vals d)
{
	double	y0;
	double	y1;

	if (d.t0 > d.t1)
		ft_swap_t_cyl(&d);
	xs->count = 0;
	y0 = ray->origin.y + d.t0 * ray->direction.y;
	if (cyl->min < y0 && y0 < cyl->max)
	{
		xs->hits[0] = intersection(d.t0, cyl);
		xs->count++;
	}
	y1 = ray->origin.y + d.t1 * ray->direction.y;
	if (cyl->min < y1 && y1 < cyl->max)
	{
		xs->hits[1] = intersection(d.t1, cyl);
		xs->count++;
	}
}

t_inters	*intersect_cyl(t_cylinder *cyl, t_ray *ray, t_inters *xs)
{
	double 		disc;
	double 		a;
	double 		b;
	double 		c;
	t_cyl_vals	data;

	a = ft_sqr(ray->direction.x) + ft_sqr(ray->direction.z);
	if (ft_equal(a, 0)) // ray is paralel to y axis
		return (xs);
	b = (2 * ray->origin.x * ray->direction.x)
		+ (2 * ray->origin.z * ray->direction.z);
	c = ft_sqr(ray->origin.x) + ft_sqr(ray->origin.z) - 1;
	disc = ft_sqr(b) - 4 * a * c;
	if (disc < 0) // ray does not intersect cylinder
		return (xs);
	data.t0 = -b - sqrt(disc) / (2*a);
	data.t1 = -b + sqrt(disc) / (2*a);
	// xs->hits[0] = intersection((-b - sqrt(disc)) / (2*a), cyl);
	// xs->hits[1] = intersection((-b + sqrt(disc)) / (2*a), cyl);
	validate(xs, cyl, ray, data);
	return (xs);
}

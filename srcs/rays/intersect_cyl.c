/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cyl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:30:29 by ameechan          #+#    #+#             */
/*   Updated: 2025/04/19 02:20:17 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_inters	*intersect_cyl(t_cyl *cyl, t_ray *ray, t_inters *xs)
{
	double disc;
	double a;
	double b;
	double c;

	a = ft_sqr(ray->direction.x) + ft_sqr(ray->direction.z);
	if (ft_equal(a, 0)) // ray is paralel to y axis
		return (xs);
	b = (2 * ray->origin.x * ray->direction.x)
		+ (2 * ray->origin.z * ray->direction.z);
	c = ft_sqr(ray->origin.x) + ft_sqr(ray->origin.z) - 1;
	disc = ft_sqr(b) - 4 * a * c;
	if (disc < 0) // ray does not intersect cylinder
		return (xs);
	xs->hits[0] = intersection((-b - sqrt(disc)) / (2*a), cyl);
	xs->hits[1] = intersection((-b + sqrt(disc)) / (2*a), cyl);
	xs->count = 2;
	return (xs);
}

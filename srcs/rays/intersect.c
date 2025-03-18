/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:23:44 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/12 13:23:08 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	*intersect(void *obj, t_ray *ray, t_obj type)
{
	if (type == SPHERE)
		return (intersect_sph((t_sphere *)obj, ray));
	// else if (type == CYLINDER)
	// 	return (intersect_cyl((t_cyl *)obj, ray));
	// else if (type == PLANE)
	// 	return (intersect_pl((t_pl *)obj, ray));
	return (NULL);
}

void	find_d(t_sphere *sph, t_ray *ray, t_ray_sphere *rs)
{
	double	temp_d;

	rs->l = diff_tuple(sph->centre, ray->origin);
	rs->l_len = magnitude(rs->l);
	rs->tc = dot(rs->l, ray->direction);
	temp_d = ft_sqr(rs->tc) - ft_sqr(rs->l_len);
	rs->d = sqrt(fabs(temp_d));
	if (rs->d < sph->radius)
		rs->x_count = 2;
	else if (rs->d == sph->radius)
		rs->x_count = 1;
	else
		rs->x_count = 0;
	printf(B_B"%d intersections\n"RES, rs->x_count);
}

double	*intersect_sph(t_sphere *sph, t_ray *ray)
{
	double			*t = malloc(sizeof(double) * 2);
	t_ray_sphere	*rs;
	double			temp_offset;

	rs = malloc(sizeof(t_ray_sphere));
	if (!rs)
	malloc_err("intersect_sph");//	debugging
	find_d(sph, ray, rs);
	temp_offset = (ft_sqr(sph->radius) - ft_sqr(rs->d));
	if (temp_offset < 0)
		return (NULL);
	rs->offset = sqrt(temp_offset);
	print_rs(rs);
	t[0] = rs->tc - rs->offset;
	t[1] = rs->tc + rs->offset;
	free(rs->l);
	free(rs);
	return (t);
}

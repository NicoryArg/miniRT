/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:42:31 by nryser            #+#    #+#             */
/*   Updated: 2025/03/25 18:43:08 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_inters	*init_intersections(int initial_capacity)
{
	t_inters	*xs;

	xs = malloc(sizeof(t_inters));
	if (!xs)
		return (NULL);
	xs->count = 0;
	xs->capacity = initial_capacity;
	xs->hits = malloc(sizeof(t_hit *) * initial_capacity);
	if (!xs->hits)
	{
		free(xs);
		return (NULL);
	}
	return (xs);
}

t_inters	*intersect(void *obj, t_ray *ray, t_obj type)
{
	t_inters	*xs;
	t_ray		*r2;
	t_matrix	*inv;
	t_inters	*result;

	xs = init_intersections(256);
	if (!xs)
		return (NULL);
	if (type == SPHERE)
	{
		inv = invert_matrix(((t_sphere *)obj)->transf);
		r2 = transform(ray, inv);
		free_matrix(inv);
		result = intersect_sph((t_sphere *)obj, r2, xs);
		free_ray(r2);
		return (result);
	}
	// else if (type == CYLINDER)
	// 	return (intersect_cyl((t_cyl *)obj, ray));
	// else if (type == PLANE)
	// 	return (intersect_pl((t_pl *)obj, ray));
	return (NULL);
}

t_hit	*intersection(double t, void *object, t_obj type)
{
	t_hit	*hit;

	hit = malloc(sizeof(t_hit));
	if (!hit)
		malloc_err("intersection");
	hit->object = object;
	hit->t = t;
	hit->type = type;
	return (hit);
}

// void	find_d(t_sphere *sph, t_ray *ray, t_ray_sphere *rs)
// {
// 	double	temp_d;

// 	rs->l = diff_tuple(sph->centre, ray->origin);
// 	rs->l_len = magnitude(rs->l);
// 	rs->tc = dot(rs->l, ray->direction);
// 	temp_d = ft_sqr(rs->tc) - ft_sqr(rs->l_len);
// 	rs->d = sqrt(fabs(temp_d));
// 	if (rs->d < sph->radius)
// 		rs->x_count = 2;
// 	else if (rs->d == sph->radius)
// 		rs->x_count = 1;
// 	else
// 		rs->x_count = 0;
// 	printf(B_B"%d intersections\n"RES, rs->x_count);
// }


// double	*intersect_sph(t_sphere *sph, t_ray *ray)
// {
// 	double			*t = malloc(sizeof(double) * 2);
// 	t_ray_sphere	*rs;
// 	double			temp_offset;

// 	rs = malloc(sizeof(t_ray_sphere));
// 	if (!rs)
// 	malloc_err("intersect_sph");//	debugging
// 	find_d(sph, ray, rs);
// 	temp_offset = (ft_sqr(sph->radius) - ft_sqr(rs->d));
// 	if (temp_offset < 0)
// 		return (NULL);
// 	rs->offset = sqrt(temp_offset);
// 	print_rs(rs);
// 	t[0] = rs->tc - rs->offset;
// 	t[1] = rs->tc + rs->offset;
// 	free(rs->l);
// 	free(rs);
// 	return (t);
// }

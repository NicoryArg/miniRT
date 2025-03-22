/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:23:44 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/19 11:27:34 by ameechan         ###   ########.fr       */
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
	xs->hits = malloc(sizeof(t_hit) * initial_capacity);
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

	xs = init_intersections(256);
	if (type == SPHERE)
		return (intersect_sph((t_sphere *)obj, ray, xs));
	// else if (type == CYLINDER)
	// 	return (intersect_cyl((t_cyl *)obj, ray));
	// else if (type == PLANE)
	// 	return (intersect_pl((t_pl *)obj, ray));
	return (NULL);
}

t_hit	*intersection(double t, void *object, t_obj type)
{
	t_hit	*intersection;

	intersection = malloc(sizeof(t_hit));
	if (!intersection)
		malloc_err("intersection");//	debugging
	if (type == SPHERE)
		object = (t_sphere *)object;
	intersection->object = object;
	intersection->t = t;
	intersection->type = SPHERE;
	return (intersection);
}

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

void	ft_swap(t_hit **a, t_hit **b)
{
	t_hit	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort_intersections(t_hit	**xs, int count)
{
	int		i;
	int		j;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (xs[i]->t > xs[j]->t)
				ft_swap(&xs[i], &xs[j]);
			j++;
		}
		i++;
	}
}

double	find_hit(t_hit	**intersections, int count)
{
	double	hit;

	// printf("xs[0]: %f\n", intersections[0]->t);
	// printf("xs[1]: %f\n", intersections[1]->t);
	sort_intersections(intersections, count);
	hit = intersections[0]->t;
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

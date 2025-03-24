/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:12:28 by nryser            #+#    #+#             */
/*   Updated: 2025/03/24 20:15:18 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"

#include "../../includes/minirt.h"
#include "engine.h"

static t_tuple	*compute_wall_point(int x, int y, double px_size, double half)
{
	double	world_x;
	double	world_y;

	world_x= -half + px_size * x;
	world_y = half - px_size * y;
	return (make_tuple(world_x, world_y, WALL_Z, POINT));
}

static t_ray	*create_ray_to_point(t_tuple *origin, t_tuple *target)
{
	t_tuple	*direction;
	t_ray	*ray;

	direction = normalise(diff_tuple(target, origin));
	ray = ft_ray(origin, direction);
	return (ray);
}

static int	compute_pixel_color(t_sphere *sphere, t_ray *ray)
{
	t_inters	*xs;
	double		t;
	int			color;
	int	i;

	xs = intersect(sphere, ray, SPHERE);
	t = find_visible_hit(xs->hits, xs->count);
	if (t >= 0)
		color = RED;
	else
		color = COLOR_X;
	i = 0;
	while (i < xs->count)
		free(xs->hits[i++]);
	return (color);
}

void	draw_silhouette(t_engine *engine)
{
	t_tuple		*ray_origin;
	t_sphere	*sph;
	int			x;
	int			y;
	double		pixel_size;
	double		half;

	ray_origin = make_tuple(0, 0, -5, POINT);
	sph = sphere(1);
	pixel_size = WALL_SIZE / (double)CANVAS_SIZE;
	sph->centre->z = 10.0;
	half = WALL_SIZE / 2.0;
	sph->transf = create_identity_matrix(4);
	y = 0;
	while (y < CANVAS_SIZE)
	{
		x = 0;
		while (x < CANVAS_SIZE)
		{
			t_tuple	*wall_point = compute_wall_point(x, y, pixel_size, half);
			t_ray	*ray = create_ray_to_point(ray_origin, wall_point);
			int		color = compute_pixel_color(sph, ray);
			put_pixel(&engine->image, x, y, color);
			x++;
		}
		y++;
	}
}

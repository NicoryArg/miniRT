/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:19:54 by nryser            #+#    #+#             */
/*   Updated: 2025/03/24 20:20:20 by nryser           ###   ########.ch       */
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
	return (ft_tuple(world_x, world_y, WALL_Z, POINT));
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
		color = WHITE;
	i = 0;
	while (i < xs->count)
		free(xs->hits[i++]);
	return (color);
}

static void	render_loop(t_render_ctx *ctx, t_image *img)
{
	int		x;
	int		y;
	t_tuple	*wall_point;
	t_ray	*ray;
	int		color;

	y = 0;
	while (y < CANVAS_SIZE)
	{
		x = 0;
		while (x < CANVAS_SIZE)
		{
			wall_point = compute_wall_point(x, y, ctx->pixel_size, ctx->half);
			ray = create_ray_to_point(ctx->ray_origin, wall_point);
			color = compute_pixel_color(ctx->sph, ray);
			put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_silhouette(t_engine *engine)
{
	t_render_ctx	ctx;

	ctx.ray_origin = ft_tuple(0, 0, -5, POINT);
	ctx.sph = sphere(1.0);
	ctx.sph->centre->z = 10;
	ctx.sph->transf = scale(5, 5, 5);
	ctx.pixel_size = WALL_SIZE / (double)CANVAS_SIZE;
	ctx.half = WALL_SIZE / 2.0;

	render_loop(&ctx, &engine->image);
}

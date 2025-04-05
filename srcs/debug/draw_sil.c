/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:44:02 by nryser            #+#    #+#             */
/*   Updated: 2025/04/02 12:52:34 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"

t_tuple	compute_wall_point(int x, int y, double px_size, double half)
{
	double	world_x;
	double	world_y;

	world_x= -half + px_size * x;
	world_y = half - px_size * y;
	return (ft_tuple(world_x, world_y, WALL_Z, POINT));
}

t_ray	*create_ray_to_point(t_tuple origin, t_tuple target)
{
	t_tuple	direction;
	t_tuple	origin_copy;
	t_ray	*ray;
	t_tuple	diff;

	diff = diff_tuple(target, origin);
	direction = normalise(diff);
	origin_copy = ft_tuple(origin.x, origin.y, origin.z, origin.w);
	ray = ft_ray(origin_copy, direction);
	return (ray);
}

static int	compute_pixel_color(t_sphere *sphere, t_ray *ray)
{
	t_inters	*xs;
	double		t;
	int			color;
	int			i;

	xs = intersect(sphere, ray);
	t = find_visible_hit(xs->hits, xs->count);
	if (t >= 0)
		color = RED;
	else
		color = BLACK;
	i = 0;
	while (i < xs->count)
		free(xs->hits[i++]);
	free(xs->hits);
	free(xs);
	return (color);
}

static void	render_loop(t_render_ctx *ctx, t_image *img)
{
	int		x;
	int		y;
	t_tuple	wall_point;
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
			free_ray(ray);
			x++;
		}
		y++;
	}
}

void	draw_silhouette(t_engine *engine)
{
	t_render_ctx	ctx;

	ctx.ray_origin = ft_tuple(0, 0, -5, POINT);
	ctx.sph = ft_sphere(1.0);
	ctx.sph->centre.z = 10;
	set_transf(ctx.sph, scale(5, 5, 5), SPHERE);
	ctx.pixel_size = WALL_SIZE / (double)CANVAS_SIZE;
	ctx.half = WALL_SIZE / 2.0;
	render_loop(&ctx, &engine->image);
	free_sphere(ctx.sph);
}

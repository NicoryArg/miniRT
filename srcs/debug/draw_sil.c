/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:30:08 by nryser            #+#    #+#             */
/*   Updated: 2025/03/22 16:30:08 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"

#define WALL_SIZE 7.0
#define WALL_Z 10.0
#define CANVAS_SIZE 100

typedef struct s_render_ctx
{
	t_image		*img;
	t_tuple		*ray_origin;
	t_sphere	*sphere;
}	t_render_ctx;

double	find_visible_hit(t_hit **xs, int count)
{
	int	i = 0;

	sort_intersections(xs, count);
	while (i < count && xs[i]->t < 0)
		i++;
	if (i < count)
		return (xs[i]->t);
	return (-1);
}

static t_tuple	*compute_pixel_position(int x, int y, double px_size, double half)
{
	double	wx = -half + px_size * x;
	double	wy = half - px_size * y;
	return (make_tuple(wx, wy, WALL_Z, POINT));
}

static void	render_pixel(t_render_ctx *ctx, t_tuple *pos, int x, int y)
{
	t_tuple		*dir = normalise(diff_tuple(pos, ctx->ray_origin));
	t_ray		*r = ray(ctx->ray_origin, dir);
	t_inters	*xs = intersect(ctx->sphere, r, SPHERE);
	int			color = (find_visible_hit(xs->hits, xs->count) >= 0) ? RED : BLACK;

	put_pixel(ctx->img, x, y, color);
	free(dir);
	free(r->origin);
	free(r->direction);
	free(r);
	free(xs->hits);
	free(xs);
}

static void	setup_render_context(t_render_ctx *ctx, t_engine *engine)
{
	ctx->img = &engine->image;
	ctx->ray_origin = make_tuple(0, 0, -5, POINT);
	ctx->sphere = sphere(1.0);
}

static void	render_row(t_render_ctx *ctx, double pixel_size, double half, int y)
{
	int		x = 0;
	t_tuple	*pos;

	while (x < CANVAS_SIZE)
	{
		pos = compute_pixel_position(x, y, pixel_size, half);
		render_pixel(ctx, pos, x, y);
		free(pos);
		x++;
	}
}

void	draw_silhouette(t_engine *engine)
{
	t_render_ctx	ctx;
	double			pixel_size = WALL_SIZE / CANVAS_SIZE;
	double			half = WALL_SIZE / 2.0;
	int				y = 0;

	setup_render_context(&ctx, engine);
	while (y < CANVAS_SIZE)
	{
		render_row(&ctx, pixel_size, half, y);
		y++;
	}
	free(ctx.ray_origin);
	free(ctx.sphere->centre);
	free(ctx.sphere);
}

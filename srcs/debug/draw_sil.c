/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:49:23 by nryser            #+#    #+#             */
/*   Updated: 2025/03/24 17:56:36 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"


static t_tuple	*compute_wall_point(int x, int y, double px_size, double half)
{
	double	world_x;
	double	world_y;

	world_x = -half + px_size * x;//Convert pixel x to world space x
	world_y = half - px_size * y;// Convert pixel y to world space y (flip Y)
	return (make_tuple(world_x, world_y, WALL_Z, POINT));//3d point
}

static t_ray	*shoot_ray_to_point(t_tuple *origin, t_tuple *target)
{
	t_tuple	*dir;
	t_ray	*ray;
	//diff_tuple gives the direction, normalise converts to
	//lenght 1 So the ray moves at constant speed and t is in real world units
	dir = normalise(diff_tuple(target, origin));
	ray = ft_ray(origin, dir);
	return (ray);
}

static int	get_color_for_pixel(t_render_ctx *ctx, t_ray *ray)
{
	t_inters	*xs;
	double		t;
	int			color;
	int			i;

	xs = intersect(ctx->sphere, ray, SPHERE);
	t = find_visible_hit(xs->hits, xs->count);
	if (t >= 0)
	{
		printf("HIT at t = %.2f\n", t);
		color = RED;
	}
	else
		color = COLOR_X;
	i = 0;
	while (i < xs->count)
	{
		free(xs->hits[i]);
		i++;
	}
	free(xs->hits);
	free(xs);
	return (color);
}

static t_ray	*prepare_ray_for_pixel(t_render_ctx *ctx, int x, int y,
				t_projection *proj)
{
	t_ray	*ray;//broken norminette xD
	t_tuple	*pos;// 3D point on the wall that this pixel maps to
	pos = compute_wall_point(x, y, proj->pixel_size, proj->half);
	ray = shoot_ray_to_point(ctx->ray_origin, pos);
	free(pos);
	return (ray);
}

void	draw_scaled_pixel(t_image *img, int x, int y, int scale, int color)
{
	int	i = 0;
	int	j;

	while (i < scale)
	{
		j = 0;
		while (j < scale)
		{
			put_pixel(img, x * scale + i, y * scale + j, color);
			j++;
		}
		i++;
	}
}

static void	render_pixel(t_render_ctx *ctx, int x, int y, t_projection *proj)
{
	t_ray	*ray;
	int		color;

	ray = prepare_ray_for_pixel(ctx, x, y, proj);
	color = get_color_for_pixel(ctx, ray);
	draw_scaled_pixel(ctx->img, x, y, 1, color); // try scale = 5

	//put_pixel(ctx->img, x, y, color);
	free(ray->origin);
	free(ray->direction);
	free(ray);
}

void	draw_silhouette(t_engine *engine)
{
	t_render_ctx	ctx;
	t_projection	proj;
	int				x;
	int				y;

	proj.pixel_size = WALL_SIZE / (double)CANVAS_SIZE;
	proj.half = WALL_SIZE / 2.0;
	ctx.img = &engine->image;
	ctx.ray_origin = make_tuple(0, 0, -5, POINT);
	ctx.sphere = sphere(1.0);
	y = 0;
	while (y < CANVAS_SIZE)//loop rows
	{
		x = 0;
		while (x < CANVAS_SIZE)//loop columns
		{
			render_pixel(&ctx, x, y, &proj);
			x++;
		}
		y++;
	}
}

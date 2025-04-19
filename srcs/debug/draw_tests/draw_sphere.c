/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:38:45 by nryser            #+#    #+#             */
/*   Updated: 2025/04/18 21:39:08 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"
#include "engine.h"
#include "tests.h"

static int	compute_color(void *sph, t_ray *ray, t_light *l)
{
	t_inters	*xs;
	t_hit		*hit;
	t_tuple		pt;
	t_colour	c;
	t_shading	shad;

	xs = intersect(sph, ray);
	hit = find_visible_hit(xs->hits, xs->count);
	if (hit && hit->t >= 0)
	{
		pt = get_point(ray, hit->t);
		shad.m = ((t_object *)sph)->m;
		shad.l = l;
		shad.point = pt;
		shad.eyev = ft_negate(ray->direction);
		shad.normalv = normal_at(sph, pt);
		c = ft_shading(shad, false);
	}
	else
		c = ft_colour(0, 0, 0);
	free_hits(xs);
	return (convert_colour_to_int(c));
}

static void	render_sphere_loop(t_render_ctx *ctx, t_image *img, t_light *light)
{
	int		x;
	int		y;
	t_tuple	wall_point;
	t_ray	*ray;
	int		color;

	y = 0;
	while (y < CANVAS_SIZE)
	{
		print_progress_bar(y, CANVAS_SIZE - 1);
		x = 0;
		while (x < CANVAS_SIZE)
		{
			wall_point = compute_wall_point(x, y, ctx->pixel_size, ctx->half);
			ray = create_ray_to_point(ctx->ray_origin, wall_point);
			color = compute_color(ctx->sph, ray, light);
			put_pixel(img, x, y, color);
			free_ray(ray);
			x++;
		}
		y++;
	}
}

void	draw_sphere(t_engine *engine)
{
	t_render_ctx	ctx;
	t_light			*light;

	ctx.ray_origin = ft_tuple(0, 0, -5, POINT);
	ctx.sph = ft_sphere(1.0);
	ctx.sph->centre = ft_tuple(0, 0, 0, POINT);
	ctx.sph->base.m = ft_material();
	ctx.sph->base.m.c = ft_colour(1, 0.2, 1);
	ctx.sph->base.m.ambient = 0.1;
	ctx.sph->base.m.diffuse = 0.9;
	ctx.sph->base.m.specular = 0.9;
	ctx.sph->base.m.shininess = 200.0;
	ctx.pixel_size = WALL_SIZE / (double)CANVAS_SIZE;
	ctx.half = WALL_SIZE / 2.0;

	light = ft_light(ft_tuple(-10, 10, -10, POINT), ft_colour(1, 1, 1));
	render_sphere_loop(&ctx, &engine->image, light);
	free_sphere(ctx.sph);
	free(light);
}




// static int	compute_color(t_world *w, t_ray *ray)
// {
// 	t_colour c = color_at(w, ray);
// 	return (convert_colour_to_int(c));
// }

// static void	render_loop(t_render_ctx *ctx, t_image *img)
// {
// 	int		x, y, color;
// 	t_tuple	wall_point;
// 	t_ray	*ray;

// 	y = 0;
// 	while (y < CANVAS_SIZE)
// 	{
// 		x = 0;
// 		while (x < CANVAS_SIZE)
// 		{
// 			wall_point = compute_wall_point(x, y, ctx->pixel_size, ctx->half);
// 			ray = create_ray_to_point(ctx->ray_origin, wall_point);
// 			color = compute_color(ctx->world, ray);
// 			put_pixel(img, x, y, color);
// 			free_ray(ray);
// 			x++;
// 		}
// 		y++;
// 	}
// }
// t_world	*default_scene(void)
// {
// 	t_world		*w;
// 	t_sphere	*s1;
// 	t_sphere	*s2;
// 	t_sphere	*s3;
// 	t_sphere	*floor;
// 	t_sphere	*left_wall;
// 	t_sphere	*right_wall;
// 	t_matrix	*transform;

// 	w = ft_world();
// 	w->light = ft_light(ft_tuple(-10, 10, -10, POINT), ft_colour(1, 1, 1));
// 	s1 = ft_sphere(1);
// 	s1->base.m.c = ft_colour(0.1, 1, 0.5);
// 	s1->base.m.diffuse = 0.7;
// 	s1->base.m.specular = 0.3;
// 	transform = multiply_matrices(scale(0.9, 0.9, 0.9), translate(-0.5, -0.5, 0.5));
// 	set_transf(s1, transform);
// 	s2 = ft_sphere(1);
// 	s2->base.m.c = ft_colour(0.5, 1, 0.1);
// 	s2->base.m.diffuse = 0.7;
// 	s2->base.m.specular = 0.3;
// 	transform = multiply_matrices(scale(0.5, 0.5, 0.5), translate(3, -2, 0.5));
// 	set_transf(s2, transform);
// 	s3 = ft_sphere(1);
// 	s3->base.m.c = ft_colour(1, 0.8, 1);
// 	s3->base.m.diffuse = 0.7;
// 	s3->base.m.specular = 0.3;
// 	transform = multiply_matrices(scale(0.33, 0.33, 0.33), translate(-5, -3.5, 0.7));
// 	set_transf(s3, transform);
// 	//floor
// 	floor = ft_sphere(1);
// 	floor->base.m.c = ft_colour(0.8, 0.8, 0.8);
// 	floor->base.m.specular = 0;
// 	transform = multiply_matrices(translate(0, -1.5, -1), scale(10, 0.01, 10));
// 	set_transf(floor, transform);
// 	left_wall = ft_sphere(1);
// 	left_wall->base.m.c = ft_colour(0.8, 0.8, 0.8);
// 	left_wall->base.m.specular = 0;
// 	transform = multiply_matrices(translate(0, 0, 5),
// 		multiply_matrices( rotate_y(-M_PI / 4),
// 			multiply_matrices(rotate_x(M_PI / 2),scale(10, 0.01, 10))));
// 	set_transf(left_wall, transform);
// 	right_wall = ft_sphere(1);
// 	right_wall->base.m.c = ft_colour(0.8, 0.8, 0.8);
// 	right_wall->base.m.specular = 0;
// 	transform = multiply_matrices(translate(0, 0, 5),
// 		multiply_matrices(
// 			multiply_matrices( rotate_y(M_PI / 4),rotate_x(M_PI / 2)),scale(10, 0.01, 10)));
// 	set_transf(right_wall, transform);
// 	w->objects = malloc(sizeof(t_object *) * 6);
// 	if (!w->objects)
// 		return (NULL);
// 	w->objects[0] = s1;
// 	w->objects[1] = s2;
// 	w->objects[2] = s3;
// 	w->objects[3] = floor;
// 	w->objects[4] = left_wall;
// 	w->objects[5] = right_wall;
// 	w->object_count = 6;
// 	return (w);
// }

// void	draw_sphere(t_engine *engine)
// {
// 	t_render_ctx	ctx;

// 	ctx.world = default_scene();
// 	ctx.ray_origin = ft_tuple(0, 0, -7, POINT);
// 	ctx.pixel_size = WALL_SIZE / (double)CANVAS_SIZE;
// 	ctx.half = WALL_SIZE / 2.0;

// 	render_loop(&ctx, &engine->image);
// 	mlx_put_image_to_window(engine->mlx, engine->window,
// 		engine->image.img_ptr, 0, 0);
// 	free_world(ctx.world);
// }
//////////////// //////////////

// static int	compute_color(void *sph, t_ray *ray, t_light *l)
// {
// 	t_inters	*xs;
// 	t_hit		*hit;
// 	t_tuple		pt;
// 	t_colour	c;
// 	t_shading	shad;

// 	xs = intersect(sph, ray);
// 	hit = find_visible_hit(xs->hits, xs->count);
// 	if (hit->t >= 0)
// 	{
// 		pt = get_point(ray, hit->t);
// 		shad.m = ((t_object *)sph)->m;
// 		shad.l = l;
// 		shad.point = pt;
// 		shad.eyev = ft_negate(ray->direction);
// 		shad.normalv = normal_at(sph, pt);
// 		c = ft_shading(shad);
// 	}
// 	else
// 		c = ft_colour(0, 0, 0);
// 	free_hits(xs);
// 	return (convert_colour_to_int(c));
// }

// static void	render_loop(t_render_ctx *ctx, t_image *img, t_light *light)
// {
// 	int		x;
// 	int		y;
// 	t_tuple	wall_point;
// 	t_ray	*ray;
// 	int		color;

// 	y = 0;
// 	while (y < CANVAS_SIZE)
// 	{
// 		x = 0;
// 		while (x < CANVAS_SIZE)
// 		{
// 			wall_point = compute_wall_point(x, y, ctx->pixel_size, ctx->half);
// 			ray = create_ray_to_point(ctx->ray_origin, wall_point);
// 			color = compute_color(ctx->sph, ray, light);
// 			put_pixel(img, x, y, color);
// 			free_ray(ray);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	draw_sphere(t_engine *engine)
// {
// 	t_render_ctx	ctx;
// 	t_light			*light;

// 	ctx.ray_origin = ft_tuple(0, 0, -5, POINT);
// 	ctx.sph = ft_sphere(1.0);
// 	ctx.sph->centre = ft_tuple(0, 0, 0, POINT); // Centered at origin
// 	ctx.sph->base.m = ft_material();
// 	ctx.sph->base.m.c = ft_colour(1, 0.2, 1);
// 	ctx.sph->base.m.ambient = 0.1;
// 	ctx.sph->base.m.diffuse = 0.9;
// 	ctx.sph->base.m.specular = 0.9;
// 	ctx.sph->base.m.shininess = 200.0;
// 	ctx.pixel_size = WALL_SIZE / (double)CANVAS_SIZE;
// 	ctx.half = WALL_SIZE / 2.0;
// 	//light on the left and above
// 	light = ft_light(ft_tuple(-10, 10, -10, POINT), ft_colour(1, 1, 1));
// 	render_loop(&ctx, &engine->image, light);
// 	free_sphere(ctx.sph);
// 	free(light);
// }

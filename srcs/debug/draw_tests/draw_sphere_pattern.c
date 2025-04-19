/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sphere_pattern.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:39:26 by nryser            #+#    #+#             */
/*   Updated: 2025/04/19 15:55:30 by nryser           ###   ########.ch       */
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

	shad.obj = sph;
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

void	draw_sphere_pattern(t_engine *engine)
{
	t_render_ctx	ctx;
	t_light			*light;
	t_pattern		*pattern;
	t_matrix		*rot;
	t_matrix		*scale_mat;
	t_matrix		*transform;
	t_matrix		*translate_mat;
	t_matrix		*final_transform;

	ctx.ray_origin = ft_tuple(0, 0, -5, POINT);
	ctx.sph = ft_sphere(1.0);
	ctx.sph->centre = ft_tuple(0, 0, 0, POINT);
	ctx.sph->base.m = ft_material();

	// 🎨 Choose the pattern type and colors
	pattern = malloc(sizeof(t_pattern));
	pattern->type = PATTERN_RING; // Options: PATTERN_RING, PATTERN_GRADIENT, PATTERN_CHECKERS
	pattern->a = ft_colour(1, 0.2, 1);
	pattern->b = ft_colour(1, 1, 0);
	pattern->transform = scale(0.2, 0.2, 0.2); // Controls pattern frequency
	ctx.sph->base.m.pattern = pattern;

	// 💎 Material properties
	ctx.sph->base.m.ambient = 0.1;
	ctx.sph->base.m.diffuse = 0.9;
	ctx.sph->base.m.specular = 0.9;
	ctx.sph->base.m.shininess = 200.0;

	// 🔄 Apply sphere transformation: scale → rotate → translate
	scale_mat = scale(1.0, 1.0, 1.0); // no squashing
	rot = multiply_matrices(rotate_y(M_PI / 6), rotate_x(M_PI / 8));
	transform = multiply_matrices(rot, scale_mat);
	translate_mat = translate(0, 0, 0); // center it in world
	final_transform = multiply_matrices(translate_mat, transform);

	set_transf(ctx.sph, final_transform);

	// 📷 Camera setup
	ctx.pixel_size = WALL_SIZE / (double)CANVAS_SIZE;
	ctx.half = WALL_SIZE / 2.0;

	light = ft_light(ft_tuple(-10, 10, -10, POINT), ft_colour(1, 1, 1));
	render_sphere_loop(&ctx, &engine->image, light);

	free_sphere(ctx.sph); // handles internal matrix and pattern
	free(light);
}

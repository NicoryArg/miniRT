
#include "../../includes/minirt.h"
#include "engine.h"

static int	compute_color(t_world *w, t_ray *ray)
{
	t_colour c = color_at(w, ray);
	return (convert_colour_to_int(c));
}

static void	render_pattern_loop(t_render_ctx *ctx, t_image *img)
{
	int		x, y, color;
	t_tuple	wall_point;
	t_ray	*ray;

	y = 0;
	while (y < CANVAS_SIZE)
	{
		x = 0;
		while (x < CANVAS_SIZE)
		{
			wall_point = compute_wall_point(x, y, ctx->pixel_size, ctx->half);
			ray = create_ray_to_point(ctx->ray_origin, wall_point);
			color = compute_color(ctx->world, ray);
			put_pixel(img, x, y, color);
			free_ray(ray);
			x++;
		}
		y++;
	}
}

static t_world	*pattern_scene(void)
{
	t_world		*w;
	t_sphere	*floor;
	t_matrix	*transform;

	w = ft_world();
	w->light = ft_light(ft_tuple(-10, 10, -10, POINT), ft_colour(1, 1, 1));

	// Floor with stripe pattern
	floor = ft_sphere(1);
	floor->base.m.c = ft_colour(0.8, 0.8, 0.8);
	floor->base.m.specular = 0;

	t_pattern *stripe = malloc(sizeof(t_pattern));
	if (!stripe)
	{
		printf(AKA"❌ ERROR: failed to allocate stripe pattern\n"RES);
		exit(1);
	}
	stripe->type = PATTERN_STRIPE;
	stripe->a = ft_colour(1, 1, 1);
	stripe->b = ft_colour(0, 0, 0);
	stripe->transform = scale(0.2, 0.2, 0.2);
	floor->base.m.pattern = stripe;

	transform = multiply_matrices(translate(0, -1.5, -1), scale(10, 0.01, 10));
	set_transf(floor, transform);

	// Allocate object list
	w->objects = malloc(sizeof(t_object *) * 1);
	if (!w->objects)
		return (NULL);
	w->objects[0] = floor;
	w->object_count = 1;

	return (w);
}

void	draw_scene_with_patterns(t_engine *engine)
{
	t_render_ctx	ctx;

	ctx.world = pattern_scene();
	ctx.ray_origin = ft_tuple(0, 0, -7, POINT);
	ctx.pixel_size = WALL_SIZE / (double)CANVAS_SIZE;
	ctx.half = WALL_SIZE / 2.0;

	render_pattern_loop(&ctx, &engine->image);
	mlx_put_image_to_window(engine->mlx, engine->window,
		engine->image.img_ptr, 0, 0);
	free_world(ctx.world);
}

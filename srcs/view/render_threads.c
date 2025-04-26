/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 06:10:40 by nryser            #+#    #+#             */
/*   Updated: 2025/04/26 06:10:40 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"

/**
 * @brief Attempts to acquire the next available block of rows to render.
 *
 * This function locks the progress mutex to safely update and fetch the
 * next starting and ending rows for rendering.
 *
 * @param ctx The thread context containing shared rendering progress.
 * @param y_start Pointer to store the starting y-coordinate.
 * @param y_end Pointer to store the ending y-coordinate.
 * @param block_size The number of rows to acquire at once.
 * @return 1 if a block was successfully acquired, 0 if rendering is complete.
 */
int	grab_next_block(t_render_thread *ctx, int *y_start,
					int *y_end, int block_size)
{
	pthread_mutex_lock(&ctx->progress->mutex);
	if (ctx->progress->current_y >= ctx->cam.vsize)
	{
		pthread_mutex_unlock(&ctx->progress->mutex);
		return (0);
	}
	*y_start = ctx->progress->current_y;
	*y_end = *y_start + block_size;
	ctx->progress->current_y += block_size;
	pthread_mutex_unlock(&ctx->progress->mutex);
	return (1);
}

/**
 * @brief Renders a single row of pixels in the image.
 *
 * For each pixel in the specified row, this function shoots a ray,
 * computes its color, and writes the result into the output image.
 * Also updates the rendering progress safely.
 *
 * @param ctx The thread context containing camera, world, and image pointers.
 * @param y The y-coordinate (row) to render.
 */
void	render_line(t_render_thread *ctx, int y)
{
	int			x;
	t_ray		*ray;
	t_colour	c;

	x = 0;
	while (x < ctx->cam.hsize)
	{
		ray = ray_for_pixel(ctx->cam, x, y);
		c = color_at(ctx->world, ray, false);
		put_pixel(ctx->image, x, y, convert_colour_to_int(c));
		free(ray);
		x++;
	}
	pthread_mutex_lock(&ctx->progress->mutex);
	ctx->progress->lines_rendered++;
	print_progress_bar(ctx->progress->lines_rendered,
		ctx->progress->total_lines);
	pthread_mutex_unlock(&ctx->progress->mutex);
}

/**
 * @brief Main thread worker function for rendering a section of the image.
 *
 * Each thread executes this function, dynamically acquiring blocks of rows
 * and rendering them until the entire image is completed.
 *
 * @param arg A pointer to a t_render_thread structure containing thread context.
 * @return NULL upon completion (required by pthreads).
 */
void	*render_section(void *arg)
{
	t_render_thread	*ctx;
	int				y_start;
	int				y_end;
	int				y;
	int				block_size;

	ctx = (t_render_thread *)arg;
	block_size = auto_block_size(ctx->cam.vsize);
	while (grab_next_block(ctx, &y_start, &y_end, block_size))
	{
		y = y_start;
		while (y < y_end && y < ctx->cam.vsize)
		{
			render_line(ctx, y);
			y++;
		}
	}
	return (NULL);
}

/**
 * @brief Renders the entire scene using multithreading.
 *
 * This function initializes the rendering context, dynamically determines
 * the number of threads to use, distributes the workload, and collects
 * the results into the final image.
 *
 * @param cam The camera from which rays are cast.
 * @param world The scene containing objects and lights.
 * @param img The image buffer to write the final render into.
 * @return A pointer to the completed image buffer.
 */
t_image	*render(t_camera cam, t_world *world, t_image *img)
{
	pthread_t		threads[64];
	t_render_thread	args[64];
	t_progress		progress;
	t_render_launch	ctx;
	int				thread_count;

	thread_count = get_cpu_count();
	if (thread_count > 64)
		thread_count = 64;
	progress.lines_rendered = 0;
	progress.current_y = 0;
	progress.total_lines = cam.vsize;
	pthread_mutex_init(&progress.mutex, NULL);
	ctx.cam = cam;
	ctx.world = world;
	ctx.img = img;
	ctx.progress = &progress;
	ctx.thread_count = thread_count;
	create_threads(threads, args, &ctx);
	join_threads(threads, thread_count);
	pthread_mutex_destroy(&progress.mutex);
	return (img);
}

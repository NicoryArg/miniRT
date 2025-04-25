/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 23:05:45 by nryser            #+#    #+#             */
/*   Updated: 2025/04/25 23:06:29 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"
#include "tests.h"

/**
 * @brief Retrieves the number of available CPU cores.
 *
 * This function queries the operating system to determine how many
 * logical processors are available for multithreading.
 *
 * @return The number of CPU cores detected.
 */
int	get_cpu_count(void)
{
	return (int)sysconf(_SC_NPROCESSORS_ONLN);
}

/**
 * @brief Determines an optimal block size based on the image height.
 *
 * This function returns a suitable block size for dynamic workload
 * distribution, balancing between fine-grained and coarse-grained
 * thread scheduling.
 *
 * @param image_height The vertical resolution of the rendered image.
 * @return The chosen block size (in number of rows).
 */
int	auto_block_size(int image_height)
{
	if (image_height <= 500)
		return (1);
	if (image_height <= 1000)
		return (2);
	return (4);
}

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
int	grab_next_block(t_render_thread *ctx, int *y_start, int *y_end, int block_size)
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
	print_progress_bar(ctx->progress->lines_rendered, ctx->progress->total_lines);
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
 * @brief Initializes and starts all rendering threads.
 *
 * This function sets up the thread contexts and creates each thread,
 * assigning them the rendering workload through the render_section function.
 *
 * @param threads An array to store thread identifiers.
 * @param args An array of thread argument structures.
 * @param ctx A pointer to the render launch context containing shared data.
 */
static void	create_threads(pthread_t *threads, t_render_thread *args, t_render_launch *ctx)
{
	int	i;

	i = 0;
	while (i < ctx->thread_count)
	{
		args[i].cam = ctx->cam;
		args[i].world = ctx->world;
		args[i].image = ctx->img;
		args[i].progress = ctx->progress;
		pthread_create(&threads[i], NULL, render_section, &args[i]);
		i++;
	}
}

/**
 * @brief Waits for all rendering threads to complete.
 *
 * This function calls pthread_join() on each rendering thread to ensure
 * that the main thread does not proceed until all work is finished.
 *
 * @param threads An array containing the thread identifiers.
 * @param thread_count The total number of threads launched.
 */
static void	join_threads(pthread_t *threads, int thread_count)
{
	int	i;

	i = 0;
	while (i < thread_count)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
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

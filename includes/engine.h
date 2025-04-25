/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:21:59 by nryser            #+#    #+#             */
/*   Updated: 2025/04/25 21:21:59 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

typedef struct s_tuple t_tuple;
# include "minirt.h"
# include "pthread.h"

typedef struct s_image
{
	void	*img_ptr;
	char	*addr_ptr;
	int		pixel_bits;
	int		line_len;
	int		endian;
}	t_image;


//#############################################
//################# ENGINE ####################
//#############################################
// Struct representing the engine with the window and fractal properties
typedef struct s_engine
{
	void		*mlx;
	void		*window;
	t_image		image;
}	t_engine;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


typedef struct	s_progress
{
	int					lines_rendered;
	int					current_y;
	int					total_lines;
	pthread_mutex_t		mutex;
}	t_progress;

typedef struct	s_render_thread
{
	t_camera		cam;
	t_world			*world;
	t_image			*image;
	int				start_y;
	int				end_y;
	t_progress		*progress;
}	t_render_thread;

typedef struct s_render_launch
{
	t_camera		cam;
	t_world			*world;
	t_image			*img;
	t_progress		*progress;
	int				thread_count;
}	t_render_launch;


//#############################################
//################# DRAW ######################
//#############################################
typedef struct	s_projectile
{
	t_tuple		position;
	t_tuple		velocity;
}	t_projectile;

typedef struct	s_environment
{
	t_tuple		gravity;
	t_tuple		wind;
}	t_environment;

//#############################################
//############## MAKE_ENGINE ##################
//#############################################
//clean_engine.c
void	error_message(char *text, int mode);
int		on_destroy_event(t_engine *engine);
void	cleanup(t_engine *engine);
void	display_help_message(t_engine *engine);


//draw_pixel.c
void	put_pixel(t_image *img, int x, int y, int color);
void	draw_marker(t_image *img, int x, int y, int color, int marker_size);

//make_engine.c
int		on_key_hook_event(int key, t_engine *engine);
void	init_engine(t_engine *engine);

//main.c
//main.c
int			ft_main_render(int run);
int			run_render_with(void (*render_func)(t_engine *));
int			ft_main_engine(int run);
//#############################################
//############## DRAW_TEST ####################
//#############################################
//draw_circle.c
void	draw_circle_scene(t_engine *engine);
int		draw_circle(int run);

//draw_clock.c
void	draw_clock_scene(t_engine *engine);
int		draw_hour_markers(int run);

//draw_projectile.c
void	draw_trajectory_scene(t_engine *engine);
int		draw_trajectory(int run);

//draw_silhouette.c
void	draw_silhouette(t_engine *engine);

//draw_sphere.c
void	draw_sphere(t_engine *engine);

//draw_world_shadows.c
void	draw_world_with_shadows(t_engine *engine);

//draw_world.c
void	draw_world(t_engine *engine);


//#############################################
//################## UTILS ####################
//#############################################
//messages.c
void	put_help_text(t_engine *engine, int *y, char *text);
void	display_help_message(t_engine *engine);
void	malloc_err(char *func_name);

t_image		*render(t_camera cam, t_world *world, t_image *img);

#define WALL_Z 5
#define WALL_SIZE 7
#define CANVAS_SIZE 300

#endif

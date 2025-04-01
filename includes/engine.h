/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:10:57 by nryser            #+#    #+#             */
/*   Updated: 2025/03/24 20:10:57 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "minirt.h"

typedef struct s_image
{
	void	*img_ptr;
	char	*addr_ptr;
	int		pixel_bits;
	int		line_len;
	int		endian;
}	t_image;


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


void	error_message(char *text, int mode);
void	init_engine(t_engine *engine);
int		on_destroy_event(t_engine *engine);
void	cleanup(t_engine *engine);
int		on_key_hook_event(int key, t_engine *engine);
void	display_help_message(t_engine *engine);


void	put_pixel(t_image *img, int x, int y, int color);
void	draw_circle(t_image *img, int center_x, int center_y, int radius, int color);
void	draw_trajectory(t_image *img);
void	draw_marker(t_image *img, int x, int y, int color, int marker_size);
void	draw_hour_markers(t_image *img);

void	draw_silhouette(t_engine *engine);

#define WALL_Z 10
#define WALL_SIZE 7
#define CANVAS_SIZE 500

#endif

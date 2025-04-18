/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:52:57 by nryser            #+#    #+#             */
/*   Updated: 2025/04/18 19:52:57 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <string.h>
# include "minirt.h"
# include "engine.h"

typedef struct s_tuple t_tuple;
typedef struct s_matrix t_matrix;
typedef struct s_ray_sphere t_ray_sphere;
typedef struct s_hit t_hit;
typedef struct s_light t_light;
typedef struct s_material t_material;
typedef struct s_colour t_colour;
typedef struct s_camera t_camera;

//#############################################
//################# DEBUG #####################
//#############################################
//print.c

void		print_tuple(t_tuple tuple, char *name);
void		print_normal(t_tuple tuple, t_tuple expected);
void		print_reflected(t_tuple tuple, t_tuple expected);
void		print_light(t_light *l, char *name);
void		print_material(t_material m);
int			equal_material(t_material m, t_material expected);
int			equal_colour(t_colour c1, t_colour c2);
int			printable_material(t_material m);
void		print_matrix(t_matrix *matrix);
void		print_test_banner(const char *word);
void		print_test_number(int *i);
void		print_intersections(t_hit **xs, int count, int sorted);
// void		print_rs(t_ray_sphere *rs);//	obsolete


//#############################################
//############### DRAW TESTS ##################
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

//draw_world_shadow.c
void	draw_world_with_shadows(t_engine *engine);

//draw_world.c
void	draw_world(t_engine *engine);

//#############################################
//################## TESTS ####################
//#############################################

//test_normal_at.c
int		normal_at_test(int run);

//test_phong.c
int		light_test(int run);
int		material_test(int run);
int		shading_test(int run);

//test_ray_for_pixel.c
int		ray_for_pixel_test(int run);


//test_rays.c
/**
 * @brief runs tests for position (p.58)
 * @note tests for `get_point(t_ray *ray, double t)`
 */
int		position_test(int run);
int		sph_unique_id(int run, int num);
int		sph_ray_intersect(int run);
int		intersection_test(int run);
int		ray_transform_test(int run);
int		ray_transform_test2(int run);


//test_transform.c
/**
 * @brief runs all tests for translation, scaling and rotation
 * @param x 1 to run x rotation tests, 0 to skip
 * @param y 1 to run y rotation tests, 0 to skip
 * @param z 1 to run z rotation tests, 0 to skip
 * @return 0 if all tests pass, 1 if any test fails
 */
int		rotate_test(int x, int y, int z);
int		scale_test(int run);
int		translate_test(int run);
int		chained_test(int run);


//test_tuples.c

int		t_matrix_to_tuple(int run);
int		t_tuple_to_matrix(int run);

//test_world.c
int		world_test(int run);
int		default_world_test(int run);
int		intersect_world_test(int run);
int		ft_pre_compute_test(int run);
int		shade_hit_test(int run);
int		color_at_test(int run);

//view_transform_test.c
int		view_transform_test(int run);
int		camera_test(int run);

//#############################################
//################## MAIN #####################
//#############################################
//main_phong.c
int		ft_main_phong(int run);

//main_rays.c
int		ft_main_rays(int run);

//main_renders.c
int		ft_main_draw_2d(int run);
int		ft_main_draw_silhouette(int run);
int		ft_main_draw_sphere(int run);
int		ft_main_draw_world(int run);
int		ft_main_draw_world_shadows(int run);
int		ft_main_draw_world_shadows(int run);

//main_transform.c
int		ft_main_transform(int run);

//main_tuples.c
int		ft_main_tuples(int run);

//main_view.c
int		ft_main_view(int run);

//main_world.c
int		ft_main_world(int run);


#endif

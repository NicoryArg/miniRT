/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:53:49 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/26 16:51:39 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <string.h>
# include "minirt.h"

typedef struct s_tuple t_tuple;
typedef struct s_matrix t_matrix;
typedef struct s_ray_sphere t_ray_sphere;
typedef struct s_hit t_hit;
typedef struct s_light t_light;
typedef struct s_material t_material;

//#############################################
//####################DEBUG####################
//#############################################
//print.c

void		print_tuple(t_tuple *tuple, char *name);
void		print_normal(t_tuple *tuple, double x, double y, double z);
void		print_light(t_light *l, char *name);
void		print_material(t_material *m);
void		print_matrix(t_matrix *matrix);
void		print_test_banner(const char *word);
void		print_test_number(int *i);
void		print_intersections(t_hit **xs, int count, int sorted);
void		malloc_err(char *func_name);
// void		print_rs(t_ray_sphere *rs);//	obsolete

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

//test_reflection.c
int		normal_at_test(int run);
int		light_test(int run);
int		material_test(int run);

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


#endif

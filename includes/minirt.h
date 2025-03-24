/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:04:23 by nryser            #+#    #+#             */
/*   Updated: 2025/03/18 20:04:23 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "tests.h"
# include "../mlx_linux/mlx.h"
# include "keys.h"
# include "engine.h"

//#############################################
//################ OBJECTS ####################
//#############################################
typedef enum e_obj_shape
{
	SPHERE,
	CYLINDER,
	PLANE,
}	t_obj;

typedef struct s_sphere
{
	t_tuple		*centre;
	double		radius;
	int			id;
	t_matrix	*transf;
}	t_sphere;

//#############################################
//############ TUPLES & MATRICES ##############
//#############################################

typedef enum tuple_type
{
	VECTOR,
	POINT,
}	t_tpl;

typedef struct s_tuple
{
	t_tpl		w;
	double		x;
	double		y;
	double		z;
}	t_tuple;

typedef struct s_matrix
{
	int			rows;
	int			cols;
	int			is_tuple;
	int			is_identity;
	int			is_invertible;
	double		det;
	double		**values;
}	t_matrix;

//#############################################
//########## RAYS & INTERSECTIONS #############
//#############################################

typedef struct s_ray
{
	t_tuple		*origin;
	t_tuple		*direction;
}	t_ray;

typedef struct s_hit
{
	double	t;
	t_sphere	*object;
	t_obj	type;
}	t_hit;

typedef struct s_intersection
{
	int		count;
	int		capacity;
	t_hit	*hits;
}	t_inters;


//#############################################
//#################MATRICES####################
//#############################################
//determinant.c
double		minor(t_matrix *matrix, int row, int col);
double		cofactor(t_matrix *matrix, int row, int col);
double		determinant_base_case(t_matrix *matrix);
double		determinant(t_matrix *matrix);

//matrix_create.c
t_matrix	*create_matrix(int rows, int cols, int is_tuple);
void		fill_matrix(t_matrix *matrix);
t_matrix	*submatrix(t_matrix *matrix, int remove_row, int remove_col);
void		fill_submatrix(t_matrix *matrix, t_matrix *sub,
				int ignore_row, int ignore_col);
t_matrix	*create_identity_matrix(int size);

//matrix_invert.c
t_matrix	*compute_cofactor_matrix(t_matrix *matrix);
void		scale_matrix(t_matrix *matrix, double scalar);
bool		invertable(t_matrix *matrix);
t_matrix	*invert_matrix(t_matrix *matrix);

//matrix_utils.c
int			equal_matrix(t_matrix *a, t_matrix *b);
void		compute_product_matrix(t_matrix *a, t_matrix *b, t_matrix *result);
t_matrix	*multiply_matrices(t_matrix *a, t_matrix *b);
t_matrix	*multiply_by_identity(t_matrix *input);
t_matrix	*transpose_matrix(t_matrix *input);

//matrix_free.c
void		free_matrix(t_matrix *matrix);

//#############################################
//##################RAYS#######################
//#############################################
//hits.c
void		ft_swap(t_hit **a, t_hit **b);
void		sort_intersections(t_hit	**xs, int count);
double		find_hit(t_hit	**intersections, int count);

//intersect.c
t_inters	*init_intersections(int initial_capacity);
t_inters	*intersect(void *obj, t_ray *ray, t_obj type);
t_hit		*intersection(double t, void *object, t_obj type);

//ray_sphere.c
double		discriminant(t_ray *ray, t_tuple *sph_to_ray);
t_inters	*intersect_sph(t_sphere *sphere, t_ray *ray, t_inters *xs);

//rays.c
/**
 * @brief creates a ray with an origin and direction
 * @param origin the starting point of the ray
 * @param direction the direction the ray is pointing
 * @return a pointer to the newly created ray
 */
t_ray		*ray(t_tuple *origin, t_tuple *direction);
t_tuple		*get_point(t_ray *ray, double t);

//transform.c
void		set_transf(void *obj, t_matrix *trans, t_obj type);
t_ray		*transform(t_ray *r, t_matrix *mtx);


//#############################################
//############### SCENE #######################
//#############################################
//objects.c
/**
 * @brief creates and returns a sphere with a unique ID
 * @param radius the radius of the sphere
 */
t_sphere	*sphere(double	radius);

//#############################################
//#############TRANSFORMATIONS#################
//#############################################
//transformations.c
/**
 * @brief creates and returns a translation matrix
 */
t_matrix	*translate(double x, double y, double z);
t_matrix	*scale(double x, double y, double z);
t_matrix	*rotate_x(double rad);
t_matrix	*rotate_y(double rad);
t_matrix	*rotate_z(double rad);

//conversion.c
/**
 * @brief grabs values from a tuple and adds them to
 * a 1x4 matrix
 */
t_matrix	*tuple_to_matrix(t_tuple *tup);
t_tuple		*matrix_to_tuple(t_matrix *matrix);


//#############################################
//##################TUPLE######################
//#############################################
//operations.c
/**
 * @brief adds coordinates of two tuples
 * @return a new tuple created from the addition of t1 & t2
 */
t_tuple		*add_tuple(t_tuple *t1, t_tuple *t2);
t_tuple		*diff_tuple(t_tuple *t1, t_tuple *t2);
t_tuple		*mult_tuple(t_tuple *vector, double t);
double		ft_sqr(double x);
double		magnitude(t_tuple *v);

//product.c
/**
 * @brief Calculates the dot product of two vectors
 * @note a dot of 1 means vectors are identical,
 * while a dot of -1 means they point in opposite directions.
 */
double		dot(t_tuple *a, t_tuple *b);
t_tuple		*cross(t_tuple *a, t_tuple *b);

//tuples.c
/**
 * @brief Fills a tuple with provided data
 */
t_tuple		*make_tuple(double x, double y, double z, t_tpl type);
t_tuple		*new_tuple(void);
t_tuple		*normalise(t_tuple *v);

//tuple_utils.c
bool		is_point(t_tuple *tuple);
bool		is_vector(t_tuple *tuple);
bool		equal_tuple(t_tuple *t1, t_tuple *t2);
bool		ft_equal(double a, double b);
void		ft_negate(t_tuple *tup);

//#############################################
//##################UTILS######################
//#############################################
//message.c
//void	display_help_message(t_engine *engine);


# ifndef M_PI
#  define M_PI 3.1415926535897932384626433
# endif
# define EPSILON 0.00001

// Define window and view parameters
# define WIN_SIZE 2000
# define VIEW_CHANGE_SIZE 60
# define MIN_ITERATIONS 256
# define MAX_ITERATIONS 256
# define DEFAULT_COLOR 265

#define WIDTH 1920
#define HEIGHT 1080

// Define circle parameters
# define SCALE 25
# define FIXED_RADIUS 1
# define MINIMUM_RADIUS 0.5
# define RADIUS 400
# define MARKER_SIZE 15

// Colors (Hex format: 0xRRGGBB)
# define COLOR_X 0x0000FF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define BLACK 0x000000

// Define Colors
# define B_B "\033[1;34m"
# define LILA "\033[0;34m"
# define R_B "\033[1;31m"
# define AKA "\033[0;31m"
# define G_B "\033[1;32m"
# define YEL "\e[0;33m"
# define CYAN "\033[0;36m"
# define GR "\033[0;32m"
# define BOLD "\033[1m"
# define RES "\033[0m"


#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:52:59 by ameechan          #+#    #+#             */
/*   Updated: 2025/02/25 16:16:25 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdbool.h>

# define EPSILON 0.00001

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
	int		rows;
	int		cols;
	int		is_tuple;
	int		is_identity;
	int		is_invertible;
	double	det;
	double	**values;
}	t_matrix;

//#############################################
//####################DEBUG####################
//#############################################
//print.c

void		print_tuple(t_tuple *tuple, char *name);
void		print_matrix(t_matrix *matrix);

//#############################################
//###################MATRICES##################
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
//#############TRANSFORMATIONS#################
//#############################################
//transformations.c
/**
 * @brief creates and returns a translation matrix
 */
t_matrix	*translate(double x, double y, double z);

//conversion.c
/**
 * @brief grabs values from a tuple and adds them to
 * a 1x4 matrix
 */
t_matrix	*tuple_to_matrix(t_tuple *tup);


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
t_tuple		*ft_multiply(t_tuple *vector, double t);
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

//utils.c
bool		is_point(t_tuple *tuple);
bool		is_vector(t_tuple *tuple);
bool		equal_tuple(t_tuple *t1, t_tuple *t2);
bool		ft_equal(double a, double b);
void		ft_negate(t_tuple *tup);

#endif

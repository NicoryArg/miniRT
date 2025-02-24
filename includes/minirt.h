/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:29:34 by nryser            #+#    #+#             */
/*   Updated: 2025/02/24 20:29:34 by nryser           ###   ########.ch       */
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

typedef enum	tuple_type
{
	VECTOR,
	POINT,
}	tpl_type;

typedef struct	s_tuple
{
	tpl_type	w;
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
	double	**values;
}	t_matrix;

//#############################################
//##################DEBUG######################
//#############################################
//print.c

void		print_tuple(t_tuple *tuple, char *name);

//#############################################
//##################MATH_UTILS#################
//#############################################
//compare_matrix.c
int			compare_matrices(t_matrix *a, t_matrix *b);

//create_matrix.c
t_matrix	*create_matrix(int rows, int cols, int is_tuple);
void		fill_matrix(t_matrix *matrix);
void		print_matrix(t_matrix *matrix);
void		free_matrix(t_matrix *matrix);
void		copy_submatrix_values(t_matrix *matrix, t_matrix *result,
				int remove_row, int remove_col);

//invert_matrix.c
t_matrix	*invert_matrix(t_matrix *matrix);

//transformation_utils.c
t_matrix	*create_identity_matrix(int size);
t_matrix	*multiply_by_identity(t_matrix *input);
t_matrix	*transpose_matrix(t_matrix *input);

//transformation.c
t_matrix	*multiply_matrices(t_matrix *a, t_matrix *b);
t_matrix	*submatrix(t_matrix *matrix, int remove_row, int remove_col);
double		minor(t_matrix *matrix, int row, int col);
double		cofactor(t_matrix *matrix, int row, int col);
double		determinant(t_matrix *matrix);
void		check_invertibility(t_matrix *matrix);

//#############################################
//##################TUPLE######################
//#############################################
//tuples.c

bool		ft_equal(double a, double b);
t_tuple 	*make_tuple(double x, double y, double z, tpl_type type);
bool		is_point(t_tuple *tuple);
bool		is_vector(t_tuple *tuple);
#endif

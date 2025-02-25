/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:52:59 by ameechan          #+#    #+#             */
/*   Updated: 2025/02/25 15:46:47 by ameechan         ###   ########.fr       */
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

//#############################################
//##################DEBUG######################
//#############################################
//print.c

void		print_tuple(t_tuple *tuple, char *name);

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

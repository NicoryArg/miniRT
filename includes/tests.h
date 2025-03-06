/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:53:49 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/06 14:59:31 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include "minirt.h"

typedef struct s_tuple t_tuple;
typedef struct s_matrix t_matrix;

//#############################################
//####################DEBUG####################
//#############################################
//print.c

void		print_tuple(t_tuple *tuple, char *name);
void		print_matrix(t_matrix *matrix);

//test_rotate.c
/**
 * @brief runs all tests for translation, scaling and rotation
 * @param x 1 to run x rotation tests, 0 to skip
 * @param y 1 to run y rotation tests, 0 to skip
 * @param z 1 to run z rotation tests, 0 to skip
 * @return 0 if all tests pass, 1 if any test fails
 */
int			rotate_test(int x, int y, int z);
//test_tuples.c

int	t_matrix_to_tuple(int run);
int	t_tuple_to_matrix(int run);


#endif

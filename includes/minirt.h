/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:52:59 by ameechan          #+#    #+#             */
/*   Updated: 2025/02/21 15:53:53 by ameechan         ###   ########.fr       */
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

#endif

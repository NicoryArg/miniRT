/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:50:52 by ameechan          #+#    #+#             */
/*   Updated: 2025/02/25 16:18:53 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_tuple *make_tuple(double x, double y, double z, t_tpl type)
{
	t_tuple	*tuple;

	tuple = malloc(sizeof(t_tuple));
	if (!tuple)
		return (NULL);
	tuple->x = x;
	tuple->y = y;
	tuple->z = z;
	tuple->w = type;
	return (tuple);
}

/**
 * @brief Allocates memory for a new tuple
 */
t_tuple	*new_tuple(void)
{
	t_tuple	*new;

	new = malloc(sizeof(t_tuple));
	if (!new)
	{
		printf("[DEBUG] `new_tuple` -> malloc failure\n");//	debugging
		return (NULL);
	}
	return(new);
}

t_tuple	*normalise(t_tuple *v)
{
	double	len;
	t_tuple	*normal;

	len = magnitude(v);
	normal = new_tuple();
	if (!normal)
	{
		printf("[DEBUG] `normalise` -> malloc failure\n");//	debugging
		return (NULL);
	}
	normal->w = VECTOR;
	normal->x = v->x/len;
	normal->y = v->y/len;
	normal->z = v->z/len;
	return (normal);
}

int	main(void)
{
	t_tuple	*a;
	t_tuple	*b;
	// double	x = 29.987654321;
	// double	y = 29.987669999;

	a = make_tuple(1, 2, 3, VECTOR);
	b = make_tuple(2, 3, 4, VECTOR);
	if (!b || !a)
	{
		printf("Error: Malloc Failure\n");
		return (1);
	}
	print_tuple(a, "a");
	print_tuple(b, "b");
	print_tuple(cross(a, b), "a->b");
	print_tuple(cross(b, a), "b->a");
	// printf("sqrt: %.2f\n", sqrt(14));
	free(a);
	free(b);
	return (0);
}

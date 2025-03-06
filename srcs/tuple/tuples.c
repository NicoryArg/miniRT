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

	tuple = new_tuple();
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

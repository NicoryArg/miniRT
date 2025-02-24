/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:50:52 by ameechan          #+#    #+#             */
/*   Updated: 2025/02/24 18:26:04 by ameechan         ###   ########.fr       */
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

t_tuple	*new_tuple(void)
{
	t_tuple	*new;

	new = malloc(sizeof(t_tuple));
	if (!new)
	{
		printf("[DEBUG] `new_tuple` -> malloc failure\n");
		return (NULL);
	}
	return(new);
}
int	main(void)
{
	t_tuple	*a;
	t_tuple	*b;
	// double	x = 29.987654321;
	// double	y = 29.987669999;

	a = make_tuple(-3, 2, 1, POINT);
	b = make_tuple(5, -66, 7, VECTOR);
	if (!b || !a)
	{
		printf("Error: Malloc Failure\n");
		return (1);
	}
	print_tuple(a, "a");
	print_tuple(b, "b");
	printf("negating a & b\n");
	negate_tuple(a);
	negate_tuple(b);
	print_tuple(a, "a");
	print_tuple(b, "b");
	free(a);
	free(b);
	return (0);
}

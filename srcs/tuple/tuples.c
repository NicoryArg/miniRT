/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:50:52 by ameechan          #+#    #+#             */
/*   Updated: 2025/02/24 16:03:19 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	ft_equal(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (true);
	return (false);
}

t_tuple *make_tuple(double x, double y, double z, tpl_type type)
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

bool	is_point(t_tuple *tuple)
{
	return (tuple->w == POINT);
}

bool	is_vector(t_tuple *tuple)
{
	return (tuple->w == VECTOR);
}

int	main(void)
{
	t_tuple	*a;
	t_tuple	*b;
	double	x = 29.987654321;
	double	y = 29.987669999;

	a = make_tuple(25.07, -19.60, 21.09, POINT);
	b = make_tuple(11.08, -19.95, 28.05, VECTOR);
	if (!b || !a)
	{
		printf("Error: Malloc Failure\n");
		return (1);
	}
	print_tuple(a, "a");
	print_tuple(b, "b");
	free(a);
	free(b);
	if (ft_equal(x, y))
		printf("equal! (diff: %.5f)\n", fabs(x-y));
	else
		printf("not EQUAL!!!! (diff %.5f)\n", fabs(x-y));
	return (0);
}

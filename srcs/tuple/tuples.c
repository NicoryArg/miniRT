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

t_tuple ft_tuple(double x, double y, double z, t_tpl type)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = type;
	return (tuple);
}

t_tuple	normalise(t_tuple v)
{
	double	len;
	t_tuple	normal;

	len = magnitude(v);
	normal.w = VECTOR;
	normal.x = v.x/len;
	normal.y = v.y/len;
	normal.z = v.z/len;
	return (normal);
}

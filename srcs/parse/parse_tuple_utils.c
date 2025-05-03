/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tuple_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 06:38:09 by nryser            #+#    #+#             */
/*   Updated: 2025/05/03 06:38:09 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"


t_tuple	parse_tuple(char *str, int type)
{
	char	**split;
	double	x;
	double	y;
	double	z;
	t_tuple	tup;

	split = ft_split(str, ',');
	if (!split)
		write(1, "Failed to split tuple string", 28);
	x = ft_atof(split[0]);
	y = ft_atof(split[1]);
	z = ft_atof(split[2]);
	tup = ft_tuple(x, y, z, type);
	free_split(split);
	return (tup);
}
t_tuple	ft_point(double x, double y, double z)
{
	return ft_tuple(x, y, z, POINT);
}

t_tuple	ft_vector(double x, double y, double z)
{
	return ft_tuple(x, y, z, VECTOR);
}

t_point3d	parse_point(char *str)
{
	char		**split;
	double		x;
	double		y;
	double		z;
	t_point3d	point;

	split = ft_split(str, ',');
	if (!split)
		return (ft_point(0, 0, 0));
	x = ft_atof(split[0]);
	y = ft_atof(split[1]);
	z = ft_atof(split[2]);
	point = ft_point(x, y, z);
	free_split(split);
	return (point);
}

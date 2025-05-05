/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:17:11 by nryser            #+#    #+#             */
/*   Updated: 2025/05/05 18:17:21 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

t_colour	parse_color(char *str)
{
	char		**split;
	double		r;
	double		g;
	double		b;
	t_colour	color;

	if (!str)
		return (ft_colour(0, 0, 0));
	split = ft_split(str, ',');
	if (!split || count_split(split) != 3
		|| !split[0] || !split[1] || !split[2])
	{
		write(2, "❌ parse_color: invalid input\n", 30);
		free_split(split);
		return (ft_colour(0, 0, 0));
	}
	r = ft_atof(split[0]) / 255.0;
	g = ft_atof(split[1]) / 255.0;
	b = ft_atof(split[2]) / 255.0;
	color = ft_colour(r, g, b);
	free_split(split);
	return (color);
}

int	is_color(const char *str)
{
	char	**parts;
	int		r;
	int		g;
	int		b;

	parts = ft_split(str, ',');
	if (!parts || count_split(parts) != 3)
	{
		printf("❌ is_color failed on '%s'\n", str);
		free_split(parts);
		return (0);
	}
	r = ft_atoi(parts[0]);
	g = ft_atoi(parts[1]);
	b = ft_atoi(parts[2]);
	free_split(parts);
	return (r >= 0 && r <= 255
		&& g >= 0 && g <= 255
		&& b >= 0 && b <= 255);
}

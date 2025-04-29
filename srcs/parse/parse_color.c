/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:31:15 by nryser            #+#    #+#             */
/*   Updated: 2025/04/29 20:31:58 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"
#include "../../includes/engine.h"

t_colour	parse_color(char *str)
{
	char		**split;
	double		r;
	double		g;
	double		b;
	t_colour	color;

	split = ft_split(str, ',');
	if (!split)
		write(1,"Failed to split color string", 28);
	r = ft_atof(split[0]) / 255.0;
	g = ft_atof(split[1]) / 255.0;
	b = ft_atof(split[2]) / 255.0;
	color = ft_colour(r, g, b);
	free_split(split);
	return (color);
}

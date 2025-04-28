/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:17:57 by nryser            #+#    #+#             */
/*   Updated: 2025/04/28 19:17:57 by nryser           ###   ########.ch       */
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
		error_message("Failed to split color string", 1);
	r = ft_atof(split[0]) / 255.0;
	g = ft_atof(split[1]) / 255.0;
	b = ft_atof(split[2]) / 255.0;
	color = ft_colour(r, g, b);
	free_split(split);
	return (color);
}

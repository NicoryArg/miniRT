/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_add_ambient.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:21:54 by nryser            #+#    #+#             */
/*   Updated: 2025/05/05 09:21:54 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

int	valid_ambient(char **tokens)
{
	double	ratio;

	if (count_split(tokens) != 3)
		return (0);
	if (!is_float(tokens[1]))
		return (0);
	ratio = ft_atof(tokens[1]);
	if (ratio < 0.0 || ratio > 1.0)
		return (0);
	if (!is_color(tokens[2]))
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 07:43:57 by nryser            #+#    #+#             */
/*   Updated: 2025/05/03 07:43:57 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

int	valid_light(char **tokens)
{
	if (count_split(tokens) != 3)
		return (0);
	if (!is_vec3(tokens[1])) // position
		return (0);
	if (!is_color(tokens[2])) // color
		return (0);
	return (1);
}

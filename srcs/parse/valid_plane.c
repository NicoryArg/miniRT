/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 08:09:40 by nryser            #+#    #+#             */
/*   Updated: 2025/05/03 08:09:40 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

int	valid_plane(char **tokens)
{
	if (count_split(tokens) != 4)
		return (0);
	if (!is_vec3(tokens[1]))
		return (0); // origin
	if (!is_vec3(tokens[2]))
		return (0); // normal
	if (!is_color(tokens[3]))
		return (0); // color
	return (1);
}

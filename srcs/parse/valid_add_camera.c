/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_add_camera.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:21:49 by nryser            #+#    #+#             */
/*   Updated: 2025/05/05 09:21:49 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

int	valid_camera(char **tokens)
{
	double	fov;

	if (count_split(tokens) != 4)
		return (0);
	if (!is_vec3(tokens[1]))
		return (0);
	if (!is_vec3(tokens[2]))
		return (0);
	if (!is_float(tokens[3]))
		return (0);
	fov = ft_atof(tokens[3]);
	if (fov < 0.0 || fov > 180.0)
		return (0);
	return (1);
}

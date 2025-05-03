/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 06:48:49 by nryser            #+#    #+#             */
/*   Updated: 2025/05/03 06:50:05 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

int	valid_sphere(char **sp)
{
	if (count_split(sp) != 4)
		return (0);
	if (!is_vec3(sp[1]))
		return (0);
	if (!is_float(sp[2]))
		return (0);
	if (!is_color(sp[3]))
		return (0);
	printf("✅ valid_sphere passed\n");
	return (1);
}

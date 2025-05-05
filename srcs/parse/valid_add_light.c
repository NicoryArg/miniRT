/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_add_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:00:31 by nryser            #+#    #+#             */
/*   Updated: 2025/05/05 10:00:31 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

int	valid_light(char **tokens)
{
	if (count_split(tokens) != 3)
		return (0);
	if (!is_vec3(tokens[1]))
		return (0);
	if (!is_color(tokens[2]))
		return (0);
	return (1);
}

void	add_lights(t_world *w, t_parsed_scene *scene)
{
	int	i;

	i = 0;
	while (i < scene->light_count)
	{
		add_light_to_world(w,
			ft_light(scene->light_positions[i], scene->light_colours[i]));
		i++;
	}
}

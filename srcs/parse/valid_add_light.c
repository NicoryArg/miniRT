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

static int print_token_line(char **tokens, int count, bool bonus)
{
	int	i;

	i = 0;
	if (!bonus && count > 3)
		printf(""X"Too many arguments in line: `");
	else if (bonus && count > 4)
		printf(""X"Too many arguments in line: `");
	else
		printf(""X"Too few arguments in line: `");
	while (i < count - 1)
		printf(AKA"%s    ", tokens[i++]);
	printf("%s"RES"`\n", tokens[i]);
	return (0);
}

int	valid_light(char **tokens, bool bonus)
{
	int	count;

	count = count_split(tokens);
	if (count != 3 && !bonus)
		return (print_token_line(tokens, count, bonus));
	else if (count != 4 && bonus == true)
		return (print_token_line(tokens, count, bonus));
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

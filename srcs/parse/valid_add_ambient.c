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

int	valid_ambient(char **tokens, bool bonus)
{
	int	count;

	count = count_split(tokens);
	if (count != 3)
		return (print_token_line(tokens, count, bonus));
	if (!is_float(tokens[1]) || !valid_light_ratio(tokens[1]))
		return (0);
	if (!is_color(tokens[2]))
		return (0);
	return (1);
}

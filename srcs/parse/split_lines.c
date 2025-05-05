/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:59:37 by nryser            #+#    #+#             */
/*   Updated: 2025/05/05 09:59:42 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

static int	copy_str(char *str, int *i, char **lines, int j)
{
	int	k;
	int	space_added;

	k = 0;
	space_added = 0;
	while (str[*i] && str[*i] != '\n' && k < MAX_LINE_LEN)
	{
		if (str[*i] != ' ' || space_added == 0)
		{
			if (str[*i] == ' ')
				space_added = 1;
			else
				space_added = 0;
			lines[j][k++] = str[*i];
		}
		(*i)++;
	}
	if (k >= MAX_LINE_LEN)
	{
		printf(AKA"❌ One or more lines are too long! "RES"(max 50)\n");
		return (1);
	}
	return (0);
}

int	split_lines(char *str, char **lines)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == '\n')
			i++;
		if (str[i])
		{
			if (copy_str(str, &i, lines, j))
				return (-1);
		}
		j++;
	}
	return (0);
}

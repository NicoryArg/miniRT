/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_vec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 06:32:35 by nryser            #+#    #+#             */
/*   Updated: 2025/05/03 06:32:35 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

int	count_split(char **arr)
{
	int	count = 0;

	if (!arr)
		return (0);
	while (arr[count])
		count++;
	return (count);
}

int	is_float(const char *s)
{
	int	i;
	int	has_digit;
	int	has_dot;

	if (!s || *s == '\0')
		return (0);

	i = 0;
	has_digit = 0;
	has_dot = 0;

	if (s[i] == '-' || s[i] == '+') // optional sign
		i++;

	while (s[i])
	{
		if (ft_isdigit(s[i]))
			has_digit = 1;
		else if (s[i] == '.')
		{
			if (has_dot) // multiple dots
				return (0);
			has_dot = 1;
		}
		else
			return (0);
		i++;
	}
	return (has_digit);
}


int	is_vec3(const char *str)
{
	char	**parts;
	int		valid;

	parts = ft_split(str, ',');
	if (!parts)
		return (0);
	if (count_split(parts) != 3)
	{
		printf("❌ is_vec3 failed on '%s'\n", str);
		free_split(parts);
		return (0);
	}
	for (int i = 0; i < 3; i++)
	{
		if (!is_float(parts[i]))
		{
			printf("❌ is_vec3: component '%s' is not a float\n", parts[i]);
			free_split(parts);
			return (0);
		}
	}
	valid = is_float(parts[0]) && is_float(parts[1]) && is_float(parts[2]);
	free_split(parts);
	return (valid);
}

int	is_color(const char *str)
{
	char	**parts;
	int		r, g, b;

	parts = ft_split(str, ',');
	if (!parts || count_split(parts) != 3)
	{
		printf("❌ is_color failed on '%s'\n", str);
		free_split(parts);
		return (0);
	}
	r = ft_atoi(parts[0]);
	g = ft_atoi(parts[1]);
	b = ft_atoi(parts[2]);
	free_split(parts);
	return (
		r >= 0 && r <= 255 &&
		g >= 0 && g <= 255 &&
		b >= 0 && b <= 255
	);
}

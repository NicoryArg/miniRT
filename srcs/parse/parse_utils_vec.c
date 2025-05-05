/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_vec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:43:44 by nryser            #+#    #+#             */
/*   Updated: 2025/05/05 09:43:44 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

static int	is_valid_float_chars(const char *s, int *has_digit)
{
	int	i;
	int	has_dot;

	i = 0;
	*has_digit = 0;
	has_dot = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]))
			*has_digit = 1;
		else if (s[i] == '.')
		{
			if (has_dot)
				return (0);
			has_dot = 1;
		}
		else
			return (0);
		i++;
	}
	return (1);
}

int	is_float(const char *s)
{
	int	i;
	int	has_digit;

	if (!s || *s == '\0')
		return (0);
	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	return (is_valid_float_chars(s + i, &has_digit) && has_digit);
}

static int	is_valid_vec3_parts(char **parts)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!is_float(parts[i]))
		{
			printf("❌ is_vec3: component '%s' is not a float\n", parts[i]);
			return (0);
		}
		i++;
	}
	return (1);
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
	valid = is_valid_vec3_parts(parts);
	free_split(parts);
	return (valid);
}

bool	is_normalized_vector(t_tuple v)
{
	return (fabs(magnitude(v) - 1.0) < EPSILON);
}

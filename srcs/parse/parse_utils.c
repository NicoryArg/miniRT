/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:33:27 by nryser            #+#    #+#             */
/*   Updated: 2025/04/29 20:33:45 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/parse.h"
#include "../../includes/engine.h"

int	skip_spaces_and_sign(const char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			*sign = -1;
	return (i);
}

double	ft_atof(const char *str)
{
	double	result;
	double	fraction;
	int		sign;
	int		i;

	result = 0.0;
	fraction = 1.0;
	sign = 1;
	i = skip_spaces_and_sign(str, &sign);
	while (ft_isdigit(str[i]))
		result = result * 10.0 + (str[i++] - '0');
	if (str[i] == '.')
	{
		i++;
		while (ft_isdigit(str[i]))
		{
			fraction *= 0.1;
			result += (str[i++] - '0') * fraction;
		}
	}
	return (result * sign);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

t_tuple	parse_tuple(char *str, int type)
{
	char	**split;
	double	x;
	double	y;
	double	z;
	t_tuple	tup;

	split = ft_split(str, ',');
	if (!split)
		write(1, "Failed to split tuple string", 28);
	x = ft_atof(split[0]);
	y = ft_atof(split[1]);
	z = ft_atof(split[2]);
	tup = ft_tuple(x, y, z, type);
	free_split(split);
	return (tup);
}

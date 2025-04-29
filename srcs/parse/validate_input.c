/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:48:10 by ameechan          #+#    #+#             */
/*   Updated: 2025/04/29 21:26:35 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static e_identifier	unique_id(char *s)
{
	if (*s == 'A')
		return (A);
	else if (*s == 'C')
		return (C);
	else if (*s == 'L')
		return (L);
	printf(AKA""INVALID_ID"", s);
	return (UFO);
}

static e_identifier	shape_id(char *s)
{
	if (s[0] == 's' &&s[1] == 'p')
		return (SP);
	else if (s[0] == 'p' &&s[1] == 'l')
		return (PL);
	else if (s[0] == 'c' &&s[1] == 'y')
		return (CY);
	else if (s[0] == 'c' &&s[1] == 'o')
		return (CO);
	printf(AKA""INVALID_ID"", s);
	return (UFO);
}

static e_identifier	get_identifier(char *s)
{
	int	i;

	i = 0;
	if (!s || !*s)
		return(UFO);
	while (s[i])
		i++;
	if (i == 1)
		return (unique_id(s));
	else if (i == 2)
		return (shape_id(s));
	printf(AKA""INVALID_ID"", s);
	return (UFO);
}

static int	valid_tokens(char **tok)
{
	e_identifier	type;
	if (!tok || !(*tok) || !(**tok))
		return (-1);
	type = get_identifier(*tok);
	if (type == UFO)
		return (-1);
	// else if (type == A)
	// 	return (valid_ambient(tok));
	// else if (type == C)
	// 	return (valid_camera(tok));
	// else if (type == L)
	// 	return (valid_light(tok));
	else if (type == SP)
		return (valid_sphere(tok));
	// else if (type == PL)
	// 	return (valid_plane(tok));
	// else if (type == CY)
	// 	return (valid_cylinder(tok));
	// else if (type == CO)
	// 	return (valid_cone(tok));
	return (0);
}

int	validate_input(char **lines)
{
	int	i;
	char *str;
	char **tokens;

	i = 0;
	while (lines[i])
	{
		str = lines[i];
		tokens = ft_split(str, ' ');
		if (valid_tokens(tokens))
		{
			free_array(tokens);
			free_array(lines);
			return(-1);
		}
		free_array(tokens);
		i++;
	}
	return (0);
}

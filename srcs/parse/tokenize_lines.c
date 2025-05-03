/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 06:50:14 by nryser            #+#    #+#             */
/*   Updated: 2025/05/03 06:50:14 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

static e_identifier	unique_id(char *s)
{
	if (*s == 'A')
		return (A);
	else if (*s == 'C')
		return (C);
	else if (*s == 'L')
		return (L);
	printf(AKA"Invalid unique identifier: %s\n"RES, s);
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
	printf(AKA"Invalid shape identifier: %s\n"RES, s);
	return (UFO);
}

e_identifier	get_identifier(char *s)
{
	int	len;

	if (!s || !*s)
		return (UFO);
	len = ft_strlen(s);
	if (len == 1)
		return (unique_id(s));
	if (len == 2)
		return (shape_id(s));
	printf(AKA"Invalid identifier length: %s\n"RES, s);
	return (UFO);
}

t_tokens	*parse_input(char **lines)
{
	int			i;
	char		**tokens;
	t_tokens	*head;
	t_tokens	*new_node;

	head = NULL;
	i = 0;
	while (lines[i])
	{
		tokens = ft_split(lines[i], ' ');
		if (!tokens)
		{
			printf(AKA"Error: Failed to split line: %s\n"RES, lines[i]);
			free_array(lines);
			return (NULL);
		}
		if (!valid_tokens(tokens))
		{
			printf(AKA"Invalid token line: %s\n"RES, lines[i]);
			free_array(tokens);
			free_array(lines);
			return (NULL);
		}
		new_node = create_token_node(tokens, get_identifier(tokens[0]));
		append_token_node(&head, new_node);
		i++;
		// print_node(new_node);
	}
	printf(G_B"✔ "GR"Finished parsing tokens\n"RES);
	return (head);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:41:19 by ameechan          #+#    #+#             */
/*   Updated: 2025/05/01 12:11:20 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int	count_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
		i++;
	return (i);
}

t_tokens	*create_token_node(char **tokens, e_identifier type)
{
	t_tokens *node;

	node = malloc(sizeof(t_tokens));
	if (!node)
		return NULL;
	node->tokens = tokens;
	node->count = count_tokens(tokens);
	node->type = type;
	node->next = NULL;
	return node;
}

void	append_token_node(t_tokens **head, t_tokens *new_node)
{
	t_tokens	*current;

	if (!*head)
	{
		*head = new_node;
		return;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = new_node;
}


void print_node(t_tokens *node)
{
	int i;

	if (!node)
		return;

	printf(B_B "identifier: " RES "%d\n", node->type);
	printf(B_B "token_count: " RES "%d\n", node->count);
	printf(B_B "tokens:\n" RES);
	i = 0;
	while (i < node->count && node->tokens[i])
	{
		printf("  %s\n", node->tokens[i]);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 06:36:50 by nryser            #+#    #+#             */
/*   Updated: 2025/05/03 06:36:50 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
void	free_split(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
void	free_token_node(t_tokens *node)
{
	if (!node)
		return ;
	free_array(node->tokens);
	free(node);
}

t_tokens	*free_tokens_list(t_tokens *head)
{
	t_tokens *temp;

	while (head)
	{
		temp = head->next;
		free_token_node(head);
		head = temp;
	}
	return (NULL);
}

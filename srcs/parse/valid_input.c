/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:50:48 by ameechan          #+#    #+#             */
/*   Updated: 2025/05/06 15:51:29 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

void	print_count(t_id_count count)
{
	printf("A: %d\n", count.a);
	printf("C: %d\n", count.c);
	printf("L: %d\n", count.l);
	printf("SP: %d\n", count.sp);
	printf("PL: %d\n", count.pl);
	printf("CY: %d\n", count.cy);
	printf("CO: %d\n", count.co);
	printf("Total shapes: %d\n", count.total);
}

static int	valid_tokens(t_tokens *node, e_id type, bool bonus)
{
	if (type == A)
		return (valid_ambient(node->tokens));
	else if (type == C)
		return (valid_camera(node->tokens));
	else if (type == L)
		return (valid_light(node->tokens, bonus));
	else if (type == SP)
		return (valid_sphere(node->tokens));
	else if (type == PL)
		return (valid_plane(node->tokens));
	else if (type == CY)
		return (valid_cylinder(node->tokens));
	else if (type == CO)
		return (valid_cone(node->tokens));
	return (0);
}

int	valid_input(t_input *data, bool bonus)
{
	t_tokens	*current;

	if (expected_identifiers(data, data->list, bonus))
		return (-1);
	// print_count(data->count); //DEBUG
	current = data->list;
	while (current)
	{
		if (!valid_tokens(current, current->type, bonus))
			return (-1);
		current = current->next;
	}
	return (0);
}

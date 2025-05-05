/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:50:48 by ameechan          #+#    #+#             */
/*   Updated: 2025/05/05 20:22:19 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

static void	print_count(t_id_count count)
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

static int	valid_identifiers(t_tokens *list, bool bonus)
{
	return (0);
}

int	valid_input(t_input *data, bool bonus)
{
	t_tokens	*current;

	if (expected_identifiers(data, data->list, bonus))
		return (-1);
	print_count(data->count);
	current = data->list;
	while (current)
	{
		if (valid_identifiers(current, bonus))
			return (-1);
		current = current->next;
	}
	return (0);
}

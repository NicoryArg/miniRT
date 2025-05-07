/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expected_identifiers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:14:57 by nryser            #+#    #+#             */
/*   Updated: 2025/05/06 19:15:05 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

static t_id_count init_count(void)
{
	t_id_count	count;

	count.a = 0;
	count.c = 0;
	count.l = 0;
	count.sp = 0;
	count.pl = 0;
	count.cy = 0;
	count.co = 0;
	count.total = 0;
	return (count);
}

static void	count_identifiers(t_tokens *list, t_id_count *count)
{
	t_tokens	*current;

	current = list;
	while (current)
	{
		if (current->type == A)
			count->a++;
		else if (current->type == C)
			count->c++;
		else if (current->type == L)
			count->l++;
		else if (current->type == SP)
			count->sp++;
		else if (current->type == PL)
			count->pl++;
		else if (current->type == CY)
			count->cy++;
		else if (current->type == CO)
			count->co++;
		current = current->next;
	}
	count->total = count->sp + count->pl + count->cy + count->co;
}

static int	expected_count(t_id_count count, bool bonus)
{
	if (count.a != 1)
		return(printf(R_B""X""RES"Too many ambient (max 1)\n"RES));
	if (count.c != 1)
		return(printf(R_B""X""RES"Too many cameras (max 1)\n"RES));
	if (count.l != 1 && bonus == false)
		return(printf(R_B""X""RES"Too many lights (max 1)\n"RES));
	else if (count.l > MAX_LIGHTS)
		return(printf(R_B""X""RES"Too many lights (max 4)\n"RES));
	if (count.sp > MAX_SPHERES)
		return(printf(R_B""X""RES"Too many spheres (max 30)\n"RES));
	if (count.cy > MAX_CYLINDERS)
		return(printf(R_B""X""RES"Too many cylinders (max 4)\n"RES));
	if (count.pl > MAX_PLANES)
		return(printf(R_B""X""RES"Too many planes (max 4)\n"RES));
	if (count.co > MAX_CONES)
		return(printf(R_B""X""RES"Too many cones (max 4)\n"RES));
	return (0);
}

int	expected_identifiers(t_input *data, t_tokens *list, bool bonus)
{
	t_id_count	count;

	count = init_count();
	count_identifiers(list, &count);
	if (expected_count(count, bonus))
		return (-1);
	data->shapes = count.total;
	data->count = count;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nested_patterns.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:12:46 by nryser            #+#    #+#             */
/*   Updated: 2025/04/23 17:12:46 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"

t_pattern	*solid_pattern(t_colour c)
{
	t_pattern	*p;

	p = malloc(sizeof(t_pattern));
	if (!p)
		return (NULL);
	p->type = PATTERN_STRIPE;
	p->a = c;
	p->b = c;
	p->a_pattern = NULL;
	p->b_pattern = NULL;
	p->transform = create_identity_matrix(4);
	p->frequency = 0;
	p->width = 0;
	p->height = 0;
	return (p);
}

t_pattern	*make_diagonal_stripe(t_colour a, t_colour b, double angle)
{
	t_pattern	*stripe;

	stripe = malloc(sizeof(t_pattern));
	stripe->type = PATTERN_UV_STRIPE;
	stripe->a = a;
	stripe->b = b;
	stripe->width = 16;
	stripe->height = 1;
	stripe->a_pattern = NULL;
	stripe->b_pattern = NULL;
	stripe->transform = rotate_z(angle);
	return (stripe);
}

// t_pattern	*make_diagonal_stripe(t_colour a, t_colour b, double angle)
// {
// 	t_pattern	*stripe = malloc(sizeof(t_pattern));
// 	stripe->type = PATTERN_UV_STRIPE;
// 	stripe->a = a;
// 	stripe->b = b;
// 	stripe->width = 20;
// 	stripe->height = 1;
// 	stripe->transform = rotate_z(angle);
// 	return (stripe);
// }

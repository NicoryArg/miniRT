/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_uv_patterns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:36:55 by nryser            #+#    #+#             */
/*   Updated: 2025/04/23 20:36:55 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"

t_pattern	uv_stripe_pattern(t_colour a, t_colour b, int width, int height)
{
	t_pattern	p;

	p.type = PATTERN_UV_STRIPE;
	p.a = a;
	p.b = b;
	p.a_pattern = NULL;
	p.b_pattern = NULL;
	p.transform = create_identity_matrix(4);
	p.width = width;
	p.height = height * 0 + 1;
	p.frequency = 0.0;
	return (p);
}

t_pattern	uv_gradient_pattern(t_colour a, t_colour b, int width, int height)
{
	t_pattern	p;

	p.type = PATTERN_UV_GRADIENT;
	p.a = a;
	p.b = b;
	p.a_pattern = NULL;
	p.b_pattern = NULL;
	p.transform = create_identity_matrix(4);
	p.width = width * 0;
	p.height = height * 0;
	p.frequency = 0.0;
	return (p);
}

t_pattern	uv_checkers_pattern(t_colour a, t_colour b, int width, int height)
{
	t_pattern	p;

	p.type = PATTERN_UV_CHECKERS;
	p.a = a;
	p.b = b;
	p.a_pattern = NULL;
	p.b_pattern = NULL;
	p.transform = create_identity_matrix(4);
	p.width = width;
	p.height = height;
	p.frequency = 0.0;
	return (p);
}

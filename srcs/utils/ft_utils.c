/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 17:39:26 by nryser            #+#    #+#             */
/*   Updated: 2025/04/20 17:39:26 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"

void	ft_swap(t_hit **a, t_hit **b)
{
	t_hit	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

double	ft_max(double a, double b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

double	ft_min(double a, double b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

t_tuple	uv_to_tuple(t_uv uv)
{
	return (ft_tuple(uv.u, uv.v, 0, POINT));
}

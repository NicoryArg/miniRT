/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:10:57 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/31 19:17:21 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_colour	*ft_colour(double r, double g, double b)
{
	t_colour	*c;

	c = malloc(sizeof(t_colour));
	if (!c)
		malloc_err("ft_colour");//	debugging
	c->r = r;
	c->g = g;
	c->b = b;
	return (c);
}

t_colour	add_colours(t_colour	a, t_colour b)
{
	t_colour	new;

	new.r = a.r + b.r;
	new.g = a.g + b.g;
	new.b = a.b + b.b;
	return (new);
}

t_colour	mult_colour(t_colour c, double num)
{
	t_colour	new;
	new.r = c.r * num;
	new.g = c.g * num;
	new.b = c.b * num;
	return (new);
}
t_colour	mult_colours(t_colour c1, t_colour c2)
{
	t_colour	new;

	new.r = c1.r * c2.r;
	new.g = c1.g * c2.g;
	new.b = c1.b * c2.b;
	return (new);
}

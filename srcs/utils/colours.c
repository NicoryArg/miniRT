/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:10:57 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/25 17:17:07 by ameechan         ###   ########.fr       */
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

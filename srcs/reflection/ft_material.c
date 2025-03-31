/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_material.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:22:34 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/26 16:32:58 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_material	*ft_material(void)
{
	t_material	*m;

	m = malloc(sizeof(t_material));
	if (!m)
		malloc_err("ft_material");
	m->c = ft_colour(1, 1, 1);
	m->ambient = 0.1;
	m->diffuse = 0.9;
	m->specular = 0.9;
	m->shininess = 200;
	return (m);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_material.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:02:19 by nryser            #+#    #+#             */
/*   Updated: 2025/05/06 19:03:48 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"

t_material	ft_material(void)
{
	t_material	m;

	m.c = ft_colour(1, 1, 1);
	m.ambient = 0.1;
	m.diffuse = 0.9;
	m.specular = 1.0;
	m.shininess = 100;
	m.pattern = NULL;
	return (m);
}

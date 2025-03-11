/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:24:46 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/11 18:50:15 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_sph	*sphere(double	radius)
{
	t_sph		*sphere;
	static int	id;

if (id == 0)
		id = 0;
	sphere = (t_sph *)malloc(sizeof(t_sph));
	if (!sphere)
	{
		printf(R_B"Error:"RES" failed to allocate memory for sphere.\n");
		exit(1);	//debugging
	}
	sphere->id = id;
	sphere->origin = make_tuple(0, 0, 0, POINT);
	sphere->radius = radius;
	id++;
	return (sphere);
}

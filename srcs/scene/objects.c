/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:56:16 by nryser            #+#    #+#             */
/*   Updated: 2025/04/18 19:56:16 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"

t_sphere	*ft_sphere(double radius)
{
	t_sphere	*sphere;
	static int	id;

	if (id == 0)
		id++;
	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sphere)
	{
		printf(R_B"Error:"RES" failed to allocate memory for sphere.\n");
		exit(1);
	}
	sphere->id = id++;
	sphere->centre = ft_tuple(0, 0, 0, POINT);
	sphere->radius = radius;
	sphere->base.type = SPHERE;
	sphere->base.transf = create_identity_matrix(4);
	sphere->base.m = ft_material();
	return (sphere);
}


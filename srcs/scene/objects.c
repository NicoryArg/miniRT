/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:24:46 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/24 16:31:29 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_sphere	*sphere(double	radius)
{
	t_sphere		*sphere;
	static int	id;

if (id == 0)
		id = 0;
	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sphere)
	{
		printf(R_B"Error:"RES" failed to allocate memory for sphere.\n");
		exit(1);	//debugging
	}
	sphere->id = id;
	sphere->centre = make_tuple(0, 0, 0, POINT);
	sphere->radius = radius;
	sphere->transf = create_identity_matrix(4);
	id++;
	return (sphere);
}

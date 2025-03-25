/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_reflection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:07:21 by nryser            #+#    #+#             */
/*   Updated: 2025/03/25 19:07:21 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_sphere	*ft_sphere(double radius, t_matrix *transform)
{
	t_sphere	*sphere;
	static int	id;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sphere)
	{
		printf(R_B"Error:"RES" failed to allocate memory for sphere.\n");
		exit(1);
	}
	sphere->id = id++;
	sphere->centre = ft_tuple(0, 0, 0, POINT);
	sphere->radius = radius;
	if (transform)
		sphere->transf = transform;
	else
		sphere->transf = create_identity_matrix(4);
	return (sphere);
}


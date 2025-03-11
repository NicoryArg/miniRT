/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:23:44 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/11 19:31:40 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	**intersect(void *obj, t_ray *ray, t_obj type)
{
	if (type == SPHERE)
		return (intersect_sph((t_sph *)obj, ray));
	// else if (type == CYLINDER)
	// 	return (intersect_cyl((t_cyl *)obj, ray));
	// else if (type == PLANE)
	// 	return (intersect_pl((t_pl *)obj, ray));
}

double	**intersect_sph(t_sph *sphere, t_ray *ray)
{
	double	*xs[2] = {12, 1};
	return (xs);
}

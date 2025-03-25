/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:09:24 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/25 13:14:45 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_tuple	*ft_world_normal(t_matrix *inverse, t_tuple *obj_normal)
{
	t_matrix	*transposed_inverse;
	t_matrix	*obj_normal_mtx;
	t_matrix	*world_normal_mtx;
	t_tuple		*world_normal;

	obj_normal_mtx = tuple_to_matrix(obj_normal);
	transposed_inverse = transpose_matrix(inverse);
	world_normal_mtx = multiply_matrices(transposed_inverse, obj_normal_mtx);
	world_normal = matrix_to_tuple(world_normal_mtx);
	world_normal->w = 0;
	free_matrix(transposed_inverse);
	free_matrix(obj_normal_mtx);
	free_matrix(world_normal_mtx);
	return (normalise(world_normal));
}

t_tuple	*ft_object_point(t_matrix *inverse, t_tuple *world_point)
{
	t_matrix	*world_point_mtx;
	t_matrix	*object_point_mtx;
	t_tuple		*object_point;

	world_point_mtx = tuple_to_matrix(world_point);
	object_point_mtx = multiply_matrices(inverse, world_point_mtx);
	object_point = matrix_to_tuple(object_point_mtx);
	free_matrix(world_point_mtx);
	free_matrix(object_point_mtx);
	return (object_point);
}

t_tuple	*normal_at(t_sphere *sph, t_tuple *world_p)
{
	t_tuple		*obj_p;
	t_tuple		*obj_normal;
	t_tuple		*world_normal;
	t_matrix	*inverse;

	inverse = invert_matrix(sph->transf);
	obj_p = ft_object_point(inverse, world_p);
	obj_normal = diff_tuple(obj_p, ft_tuple(0, 0, 0, POINT));
	world_normal = ft_world_normal(inverse, obj_normal);
	free_matrix(inverse);
	// print_tuple(obj_p, "object point");
	// print_tuple(obj_normal, "object normal");
	return (world_normal);
}

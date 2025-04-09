/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:56:44 by ameechan          #+#    #+#             */
/*   Updated: 2025/04/08 12:28:41 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	set_transf(void *obj, t_matrix *trans)
{
		free_matrix(((t_object *)obj)->transf);
		((t_object *)obj)->transf = trans;
}

t_ray	*transform(t_ray *r, t_matrix *inverse)
{
	t_ray		*new;
	t_matrix	*temp;
	t_matrix	*ray_mtx;

	new = malloc(sizeof(t_ray));
	if (!new)
		malloc_err("transform");//	debugging
	temp = tuple_to_matrix(r->direction);
	ray_mtx = multiply_matrices(inverse, temp);
	new->direction = matrix_to_tuple(ray_mtx);
	free_matrix(temp);
	free_matrix(ray_mtx);
	temp = tuple_to_matrix(r->origin);
	ray_mtx = multiply_matrices(inverse, temp);
	new->origin = matrix_to_tuple(ray_mtx);
	free_matrix(temp);
	free_matrix(ray_mtx);
	return (new);
}

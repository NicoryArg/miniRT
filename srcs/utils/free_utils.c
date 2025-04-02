/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:00:18 by nryser            #+#    #+#             */
/*   Updated: 2025/04/02 14:00:18 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"

void	free_ray(t_ray *ray)
{
	if (!ray)
		return ;
	free(ray);
}
void	free_matrix(t_matrix *matrix)
{
	int	i;

	if (!matrix)
		return;
	if (matrix->values)
	{
		i = 0;
		while (i < matrix->rows)
		{
			free(matrix->values[i]);
			i++;
		}
		free(matrix->values);
	}
	free(matrix);
}


void	free_sphere(t_sphere *sphere)
{
	if (!sphere)
		return ;
	free_matrix(sphere->transf);
	free(sphere);
}

void	free_hits(t_inters *xs)
{
	int	i;

	i = 0;
	while (i < xs->count)
		free(xs->hits[i++]);
	free(xs->hits);
	free(xs);
}

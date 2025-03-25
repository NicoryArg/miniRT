/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:11:53 by nryser            #+#    #+#             */
/*   Updated: 2025/03/25 18:12:03 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"

void	free_ray(t_ray *ray)
{
	if (!ray)
		return ;
	free(ray->origin);
	free(ray->direction);
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
	free(sphere->centre);
	free(sphere->transf);
	free(sphere);
}

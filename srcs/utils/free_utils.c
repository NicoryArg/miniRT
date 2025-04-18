/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:26:59 by nryser            #+#    #+#             */
/*   Updated: 2025/04/18 16:26:59 by nryser           ###   ########.ch       */
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
		return ;
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
	if (sphere->base.transf)
		free_matrix(sphere->base.transf);
	free_material(&sphere->base.m); // <— Use your helper here
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

void	free_world(t_world *w)
{
	int	i;

	if (!w)
		return ;
	i = 0;
	while (i < w->object_count)
	{
		free_sphere(w->objects[i]);
		i++;
	}
	free(w->objects);
	free(w->light);
	free(w);
}
void	free_material(t_material *m)
{
	if (m->pattern)
	{
		if (m->pattern->transform)
			free_matrix(m->pattern->transform);
		free(m->pattern);
	}
}

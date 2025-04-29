/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:12:46 by nryser            #+#    #+#             */
/*   Updated: 2025/04/29 20:16:20 by nryser           ###   ########.ch       */
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

void	free_hitlists(t_hitlist *xs)
{
	t_hitlist	*tmp;

	while (xs)
	{
		tmp = xs->next;
		free(xs->hit);
		free(xs);
		xs = tmp;
	}
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
	int			i;
	t_object	*obj;

	if (!w)
		return ;

	i = 0;
	while (i < w->object_count)
	{
		obj = (t_object *)w->objects[i];

		// Free object by type
		if (obj->type == SPHERE)
			free_sphere((t_sphere *)obj);
		else if (obj->type == PLANE)
			free(((t_plane *)obj));
		else if (obj->type == CYLINDER)
			free(((t_cylinder *)obj));

		i++;
	}
	free(w->objects);
	free(w->lights);
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

void	free_hitlist(t_hitlist **hs)
{
	t_hitlist	*current;
	t_hitlist	*next;

	if (!hs)
		return;
	current = *hs;
	while (current)
	{
		next = current->next;
		free(current->hit);
		free(current);
		current = next;
	}
	free(hs); // free the malloc from new_hitlist()
}


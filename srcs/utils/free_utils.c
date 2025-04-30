/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 01:41:54 by nryser            #+#    #+#             */
/*   Updated: 2025/04/30 01:49:56 by nryser           ###   ########.ch       */
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

void	free_plane(t_plane *plane)
{
	if (!plane)
		return ;
	if (plane->base.transf)
		free_matrix(plane->base.transf);
	free_material(&plane->base.m);
	free(plane);
}

void	free_cylinder(t_cylinder *cyl)
{
	if (!cyl)
		return ;
	if (cyl->base.transf)
		free_matrix(cyl->base.transf);
	free_material(&cyl->base.m);
	free(cyl);
}
void	free_cone(t_cone *cone)
{
	if (!cone)
		return ;
	if (cone->base.transf)
		free_matrix(cone->base.transf);
	free_material(&cone->base.m);
	free(cone);
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
		if (obj->type == SPHERE)
			free_sphere((t_sphere *)obj);
		else if (obj->type == PLANE)
			free_plane((t_plane *)obj);
		else if (obj->type == CYLINDER)
			free_cylinder((t_cylinder *)obj);
		else if (obj->type == CONE)
			free_cone((t_cone *)obj);
		i++;
	}
	free(w->objects);
	i = 0;
	while (i < w->light_count)
	{
		if (w->lights[i])
			free(w->lights[i]);
		i++;
	}
	free(w->lights);
	free(w);
}

void	free_material(t_material *m)
{
	if (m && m->pattern)
		free_pattern(m->pattern);
}

void	free_pattern(t_pattern *pattern)
{
	if (!pattern)
		return;
	if (pattern->transform)
		free_matrix(pattern->transform);
	if (pattern->a_pattern)
		free_pattern(pattern->a_pattern);
	if (pattern->b_pattern)
		free_pattern(pattern->b_pattern);
	free(pattern);
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


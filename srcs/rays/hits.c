/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:34:06 by nryser            #+#    #+#             */
/*   Updated: 2025/03/24 16:34:06 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	sort_intersections(t_hit	**xs, int count)
{
	int		i;
	int		j;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (xs[i]->t > xs[j]->t)
				ft_swap(&xs[i], &xs[j]);
			j++;
		}
		i++;
	}
}

//Rendering camera-facing images (like silhouette)
double	find_visible_hit(t_hit **hits, int count)
{
	int		i = 0;

	sort_intersections(hits, count);//optional
	while (i < count && hits[i]->t < 0)
		i++;
	if (i < count)
		return (hits[i]->t);
	return (-1);
}


double	find_hit(t_hit	**intersections, int count)
{
	double	hit;

	// printf("xs[0]: %f\n", intersections[0]->t);
	// printf("xs[1]: %f\n", intersections[1]->t);
	sort_intersections(intersections, count);
	hit = intersections[0]->t;
	return (hit);
}

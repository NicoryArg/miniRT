/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:48:48 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/22 15:49:03 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	ft_swap(t_hit **a, t_hit **b)
{
	t_hit	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

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

double	find_hit(t_hit	**intersections, int count)
{
	double	hit;

	// printf("xs[0]: %f\n", intersections[0]->t);
	// printf("xs[1]: %f\n", intersections[1]->t);
	sort_intersections(intersections, count);
	hit = intersections[0]->t;
	return (hit);
}

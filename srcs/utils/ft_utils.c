/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 05:43:40 by nryser            #+#    #+#             */
/*   Updated: 2025/04/26 06:02:39 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"

void	ft_swap(t_hit **a, t_hit **b)
{
	t_hit	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	print_progress_bar(int y, int total)
{
	int		percent;
	int		filled;
	int		i;

	percent = (y * 100) / total;
	filled = (percent * 50) / 100;
	i = 0;
	printf("\r[");
	while (i < filled)
	{
		printf("\033[32m=\033[0m");
		i++;
	}
	while (i < 50)
	{
		printf(" ");
		i++;
	}
	printf("] %3d%% (%d/%d)", percent, y, total);
	if (y == total)
		printf("\n");
}




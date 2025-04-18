/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:29:11 by ameechan          #+#    #+#             */
/*   Updated: 2025/04/18 14:53:56 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	ft_main_plane(int run)
{
	if (run == 0)
		return (0);
	if (local_normal_plane_test(1))
		return (-1);
	if (intersect_plane_test(1))
		return (-1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:44:44 by nryser            #+#    #+#             */
/*   Updated: 2025/04/18 20:44:44 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"
#include "tests.h"


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

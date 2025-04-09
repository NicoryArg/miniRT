/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:41:26 by nryser            #+#    #+#             */
/*   Updated: 2025/04/09 17:41:26 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	ft_main_world(int run)
{
	if (run == 0)
		return (0);
	if (world_test(0))
		printf("Error: world_test failed\n");
	if (default_world_test(0))
		printf(AKA"Error: default_world_test failed\n"RES);
	if (intersect_world_test(0))
		printf(AKA"Error: intersect_world_test failed\n"RES);
	if (ft_pre_compute_test(0))
		printf(R_B"ft_pre_compute_test failed\n"RES);
	if (shade_hit_test(0))
		printf(AKA"Error: shade_hit_test failed\n"RES);
	if (color_at_test(1))
		printf(AKA"Error: color_at_test failed\n"RES);
	printf(R_B"END OF WORLD TESTS\n"RES);
	return (0);
}

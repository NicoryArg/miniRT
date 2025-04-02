/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:26:17 by nryser            #+#    #+#             */
/*   Updated: 2025/04/02 18:26:17 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	ft_main_world(void)
{
	if (world_test(1))
		printf("Error: world_test failed\n");
	if (default_world_test(1))
		printf(AKA"Error: default_world_test failed\n"RES);
	if (intersect_world_test(1))
		printf(AKA"Error: intersect_world_test failed\n"RES);
	printf(R_B"END OF WORLD TESTS\n"RES);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:58:58 by nryser            #+#    #+#             */
/*   Updated: 2025/03/18 15:58:58 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	main()
{
	if (position_test(0))//	0 to skip, 1 to run
		printf(R_B"Error:"RES" position_test failed\n");
	if (sph_unique_id(0, 10))// 0 to skip, 1 to run
		printf(R_B"Error:"RES" sph_unique_id failed\n");
	if (sph_ray_intersect(1))// 0 to skip, 1 to run
		printf(R_B"Error:"RES" sph_ray_intersect failed\n");
	printf(R_B"END OF RAYS TESTS\n"RES);
	return (0);
}

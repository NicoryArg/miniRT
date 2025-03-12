/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:48:26 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/12 13:40:54 by ameechan         ###   ########.fr       */
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

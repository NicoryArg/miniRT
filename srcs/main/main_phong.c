/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_phong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:30:27 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/31 19:14:54 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

// int	main(void)
// {
// 	if (normal_at_test(0)) //1 to run , 0 to skip
// 		printf("Error: normal_at_test failed\n");
// 	if (light_test(0)) //1 to run , 0 to skip
// 		printf("Error: light_test failed\n");
// 	if (material_test(0)) //1 to run , 0 to skip
// 		printf("Error: material_test failed\n");
// 	if (shading_test(1)) //1 to run , 0 to skip
// 		printf("Error: shading_test failed\n");
// 	printf(R_B"END OF REFLECTION TESTS\n"RES);
// 	return (0);
// }

int	ft_main_phong(int run)
{
	if (run == 0)
		return (0);
	if (normal_at_test(1)) //1 to run , 0 to skip
		printf("Error: normal_at_test failed\n");
	if (light_test(0)) //1 to run , 0 to skip
		printf("Error: light_test failed\n");
	if (material_test(0)) //1 to run , 0 to skip
		printf("Error: material_test failed\n");
	if (shading_test(0)) //1 to run , 0 to skip
		printf("Error: shading_test failed\n");
	printf(R_B"END OF REFLECTION TESTS\n"RES);
	return (0);
}

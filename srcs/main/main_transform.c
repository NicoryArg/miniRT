/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:23:55 by ameechan          #+#    #+#             */
/*   Updated: 2025/04/01 15:50:43 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

// int	main(void)
// {
// 	if (translate_test(0)) //1 to run , 0 to skip
// 		printf("Error: translate_test failed\n");
// 	if (scale_test(0))	//1 to run, 0 to skip
// 		printf("Error: scale_test failed\n");
// 	if (rotate_test(0, 0, 0)) //1 to run, 0 to skip
// 		printf("Error: rotate_test failed\n");
// 	if (chained_test(0))
// 		printf("Error: chained_test failed\n");
// 	printf(R_B"END OF TRANSFORM TESTS\n"RES);
// 	return (0);
// }

int	ft_main_transform(void)
{
	if (translate_test(1)) //1 to run , 0 to skip
		printf("Error: translate_test failed\n");
	if (scale_test(1))	//1 to run, 0 to skip
		printf("Error: scale_test failed\n");
	if (rotate_test(1, 1, 1)) //1 to run, 0 to skip
		printf("Error: rotate_test failed\n");
	if (chained_test(1))
		printf("Error: chained_test failed\n");
	printf(R_B"END OF TRANSFORM TESTS\n"RES);
	return (0);
}

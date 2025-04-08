/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:23:55 by ameechan          #+#    #+#             */
/*   Updated: 2025/04/09 00:25:40 by ameechan         ###   ########.fr       */
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

int	ft_main_transform(int run)
{
	if (run == 0)
		return (0);
	if (translate_test(1)) //1 to run , 0 to skip
		return(printf(R_B"translate_test failed\n"RES));
	if (scale_test(1))	//1 to run, 0 to skip
		return(printf(R_B"scale_test failed\n"RES));
	if (rotate_test(1, 1, 1)) //1 to run, 0 to skip
		return(printf(R_B"rotate_test failed\n"RES));
	if (chained_test(1)) //1 to run, 0 to skip
		return(printf(R_B"chained_test failed\n"RES));
	printf(G_B"END OF TRANSFORM TESTS\n"RES);
	return (0);
}

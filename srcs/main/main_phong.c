/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_phong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:10:09 by nryser            #+#    #+#             */
/*   Updated: 2025/03/31 18:10:14 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	main(void)
{
	if (normal_at_test(0)) //1 to run , 0 to skip
		printf("Error: normal_at_test failed\n");
	if (light_test(0)) //1 to run , 0 to skip
		printf("Error: light_test failed\n");
	if (material_test(1)) //1 to run , 0 to skip
		printf("Error: material_test failed\n");
	printf(R_B"END OF REFLECTION TESTS\n"RES);
	return (0);
}

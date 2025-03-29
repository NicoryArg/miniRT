/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_reflection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:30:27 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/29 14:50:11 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	main(void)
{
	if (normal_at_test(0)) //1 to run , 0 to skip
		printf("Error: normal_at_test failed\n");
	if (light_test(1)) //1 to run , 0 to skip
		printf("Error: light_test failed\n");
	if (material_test(1)) //1 to run , 0 to skip
		printf("Error: material_test failed\n");
	printf(R_B"END OF REFLECTION TESTS\n"RES);
	return (0);
}

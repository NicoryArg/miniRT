/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_shadows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:21:54 by ameechan          #+#    #+#             */
/*   Updated: 2025/04/16 15:31:18 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	ft_main_shadows(int run)
{
	if (run == 0)
		return (0);
	if (shadows_test(1)) //1 to run , 0 to skip
		return (printf(R_B"shadows_test failed\n"RES));
	printf(G_B"END OF SHADOWS TESTS\n"RES);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:48:26 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/10 20:19:16 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	main()
{
	if (position_test(1))
		printf(R_B"Error:"RES" position_test failed\n");
	printf(R_B"END OF RAYS TESTS\n"RES);
	return (0);
}

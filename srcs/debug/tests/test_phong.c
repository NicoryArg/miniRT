/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_phong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:58:26 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/29 14:49:49 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

//#################################################################//
///////////////////////////// LIGHT /////////////////////////////////
//#################################################################//

int	light_test(int run)
{
	if (run == 0)
		return (0);
	t_colour	*lum;
	t_tuple		*pos;
	t_light		*light;
	int			i = 1;


//TEST 1
	//print banners
	print_test_banner("light has a position and intensity (lum)");
	print_test_number(&i);
	//initiate variables
	lum = ft_colour(255, 255, 255);
	pos = ft_tuple(0, 0, 0, POINT);
	//run test;
	light = ft_light(pos, lum);
	//print output
	print_light(light, "light");

	return (0);
}

//#################################################################//
//////////////////////////// MATERIAL ///////////////////////////////
//#################################################################//

int	material_test(int run)
{
	if (run == 0)
		return (0);
	int			i = 1;
	t_material	*m;

	print_test_banner("MATERIAL TESTS");
	print_test_number(&i);
	m = ft_material();

	print_material(m);
	return (0);
}

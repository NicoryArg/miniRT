/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_phong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:19:23 by nryser            #+#    #+#             */
/*   Updated: 2025/03/31 18:19:30 by nryser           ###   ########.ch       */
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
	t_sphere	*sph;

//TEST 1
	//print banners
	print_test_banner("Assign default values to material");
	print_test_number(&i);
	//run test;
	m = ft_material();
	//print output
	print_material(m);
	free(m->c);
	free(m);

//TEST 2
	//print banners
	print_test_banner("Assign default material to sphere");
	print_test_number(&i);
	//initiate variables
	sph = ft_sphere(1);
	//print input
	printf(G_B"Sphere->m:\n"RES);
	print_material(sph->m);
	//run test;
	printf(LILA"Assigning default material to sphere\n"RES);
	m = sph->m;
	m = ft_material();
	//print output
	printf(G_B"Sphere->m:\n"RES);
	print_material(m);
	//free memory
	free(m->c);
	free(m);
	free(sph);
//TEST 3
	//print banners
	print_test_banner("Assign material to sphere");
	print_test_number(&i);
	//initiate variables
	sph = ft_sphere(1);
	m = ft_material();
	//print run test
	sph->m = m;
	//print output
	printf(G_B"Sphere->m:\n"RES);
	print_material(sph->m);
	//free memory
	free(m->c);
	free(m);
	return (0);
}

//#################################################################//
//////////////////////////// LIGHTING ///////////////////////////////
//#################################################################//

int	lighting_test(int run)
{
	if (run == 0)
		return (0);
	// int			i = 1;
	// t_material	*m;
	// t_light		*l;
	// t_tuple		*pos;
	// t_colour	*lum;
	// t_tuple		*eyev;
	// t_tuple		*normalv;
	// t_tuple		*result;

	return (0);
}

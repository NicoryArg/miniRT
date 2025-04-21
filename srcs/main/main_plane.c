/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:29:11 by ameechan          #+#    #+#             */
/*   Updated: 2025/04/19 01:38:19 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"
#include "tests.h"


int	ft_main_plane(int run)
{
	if (run == 0)
		return (0);
	if (local_normal_plane_test(1))
		return (printf(AKA"❌ local_normal_plane_test failed\n"RES));
	if (intersect_plane_test(1))
		return (printf(AKA"❌ intersect_plane_test failed\n"RES));
	printf(G_B"END OF PLANE TESTS\n"RES);
	return (0);
}

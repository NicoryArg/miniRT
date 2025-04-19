/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cyl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 01:34:38 by ameechan          #+#    #+#             */
/*   Updated: 2025/04/19 14:35:36 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "tests.h"

int	ft_main_cylinder(int run)
{
	if (run == 0)
		return (0);
	if (test_intersect_cylinder(0))
		return(printf(AKA"❌ test_intersect_cylinder failed\n"RES));
	if (test_normal_at_cylinder(0))
		return(printf(AKA"❌ test_normal_at_cylinder failed\n"RES));
	if (test_truncate_cylinder(1))
		return(printf(AKA"❌ test_truncate_cylinder failed\n"RES));
	return (0);
}


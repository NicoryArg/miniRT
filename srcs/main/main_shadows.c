/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_shadows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:44:13 by nryser            #+#    #+#             */
/*   Updated: 2025/04/18 20:44:27 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"
#include "tests.h"

int	ft_main_shadows(int run)
{
	if (run == 0)
		return (0);
	if (shadows_test(1)) //1 to run , 0 to skip
		return (printf(R_B"shadows_test failed\n"RES));
	printf(G_B"END OF SHADOWS TESTS\n"RES);
	return (0);
}

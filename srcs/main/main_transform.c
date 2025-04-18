/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:48:37 by nryser            #+#    #+#             */
/*   Updated: 2025/04/18 19:48:37 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "tests.h"
#include "engine.h"

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

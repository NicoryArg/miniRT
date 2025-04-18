/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tuples.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:23:11 by nryser            #+#    #+#             */
/*   Updated: 2025/04/18 19:23:11 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "tests.h"
#include "engine.h"

int	ft_main_tuples(int run)
{
	if (run == 0)
		return (0);
	if (t_tuple_to_matrix(1))
		return(printf(R_B"❌ tuple_to_matrix test failed\n"RES));
	if (t_matrix_to_tuple(1))
		return(printf(R_B"❌ matrix_to_tuple test failed\n"RES));
	printf(R_B"END OF TUPLE TESTS\n"RES);
	return (0);
}

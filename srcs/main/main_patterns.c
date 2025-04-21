/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_patterns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 22:00:58 by nryser            #+#    #+#             */
/*   Updated: 2025/04/18 22:00:58 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"
#include "tests.h"

int	ft_main_patterns(int run)
{
	if (run == 0)
		return (0);
	if (stripe_pattern_test(0))//	0 to skip, 1 to run
		return(printf(R_B"stripe_test failed\n"RES));
	if (pattern_lighting_test(0))//	0 to skip, 1 to run
		return(printf(R_B"pattern_lighting_test failed\n"RES));
	if (stripe_transform_test(0))//	0 to skip, 1 to run
		return(printf(R_B"stripe_transform_test failed\n"RES));
	if (pattern_generalization_test(1))//	0 to skip, 1 to run
		return(printf(R_B"pattern_generalization_test failed\n"RES));

	printf(G_B"END OF PATTERN TESTS\n"RES);
	return (0);
}

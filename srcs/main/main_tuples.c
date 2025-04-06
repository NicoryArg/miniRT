/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tuples.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:50:27 by ameechan          #+#    #+#             */
/*   Updated: 2025/04/06 11:52:30 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

// int	main(void)
// {
// 	t_tuple_to_matrix(0);
// 	t_matrix_to_tuple(0);
// 	printf(R_B"END OF TUPLE TESTS\n"RES);
// 	return (0);
// }

int	ft_main_tuples(void)
{
	if (t_tuple_to_matrix(1))
		return(printf(R_B"❌ tuple_to_matrix test failed\n"RES));
	if (t_matrix_to_tuple(1))
		return(printf(R_B"❌ matrix_to_tuple test failed\n"RES));
	printf(R_B"END OF TUPLE TESTS\n"RES);
	return (0);
}

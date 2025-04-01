/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tuples.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:50:27 by ameechan          #+#    #+#             */
/*   Updated: 2025/04/01 15:47:09 by ameechan         ###   ########.fr       */
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
	t_tuple_to_matrix(1);
	t_matrix_to_tuple(1);
	printf(R_B"END OF TUPLE TESTS\n"RES);
	return (0);
}

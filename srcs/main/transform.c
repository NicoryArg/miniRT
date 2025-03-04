/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:23:55 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/04 15:08:05 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

//#############################################################################
//#############################################################################
//##########################  TRANSLATION  ####################################
//#############################################################################
//#############################################################################
int	main(void)
{
	t_matrix	*transform;
	t_matrix	*inverse;
	t_matrix	*p;
	t_tuple		*point;

	transform = translate(5, -3, 2);
	inverse = invert_matrix(transform);
	point = make_tuple(-3, 4, 5, POINT);
	if (!transform || !point || !inverse)
	{
		printf("Error: one or more arguments are NULL\n");
		return (1);
	}
	printf("##### TEST 1 #####\n");
	print_tuple(point, "p");
	print_matrix(transform);
	printf("Multiplying `p` by translation matrix\n");
	p = tuple_to_matrix(point);
	print_matrix(p);
	printf("#####################\n");
	free(point);
	free_matrix(transform);
	free_matrix(inverse);
	return (0);
}

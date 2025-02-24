/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:53:12 by ameechan          #+#    #+#             */
/*   Updated: 2025/02/24 17:32:00 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	print_tuple(t_tuple *tuple, char *name)
{
	if (is_vector(tuple))
		printf("tuple `%s` is VECTOR:\n", name);
	else if (is_point(tuple))
		printf("tuple `%s` is POINT:\n", name);
	else
		printf("ERROR: tuple type undefined\n");
	printf("w: %d\n", tuple->w);
	printf("x: %.5f\n", tuple->x);
	printf("y: %.5f\n", tuple->y);
	printf("z: %.5f\n", tuple->z);
}

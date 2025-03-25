/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reflect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:59:08 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/25 16:16:44 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_tuple	*ft_reflect(t_tuple *in, t_tuple *normal)
{
	double	dot_product;
	t_tuple	*temp;
	t_tuple	*reflect;

	dot_product = dot(in, normal);
	temp = mult_tuple(normal, 2*dot_product);
	reflect = diff_tuple(in, temp);
	free(temp);
	return (reflect);
}

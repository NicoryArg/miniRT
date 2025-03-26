/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_phong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:58:26 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/26 16:59:00 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

int	material_test(int run)
{
	if (run == 0)
		return (0);
	int			i = 1;
	t_material	*m;

	print_test_banner("MATERIAL TESTS");
	print_test_number(&i);
	m = ft_material();

	print_material(m);
	return (0);
}

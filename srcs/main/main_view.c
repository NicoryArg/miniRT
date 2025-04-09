/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:59:42 by nryser            #+#    #+#             */
/*   Updated: 2025/04/09 20:59:42 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	ft_main_view(int run)
{
	if (run == 0)
		return (0);
	if(view_transform_test(1))
		return (printf(AKA"Error: view_transform_test failed\n"RES));
	printf(G_B"END OF VIEW TESTS\n"RES);
	return (0);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:29:31 by nryser            #+#    #+#             */
/*   Updated: 2025/03/19 10:29:31 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"

// int	main(void)
// {
// 	t_matrix	*a;
// 	t_matrix	*b;

// 	a = create_matrix(2, 2, 0);
// 	b = create_matrix(2, 2, 0);
// 	fill_matrix(a);
// 	fill_matrix(b);
// 	if (equal_matrix(a, b))
// 		printf("Equal!\n");
// 	else
// 		printf("Not Equal\n");
// 	return (0);
// }



int	main(void)
{
	t_engine	engine;

	init_engine(&engine);
	mlx_key_hook(engine.window, on_key_hook_event, &engine);
	mlx_hook(engine.window, 17, 0, on_destroy_event, &engine);
	mlx_loop(engine.mlx);
	cleanup(&engine);
}

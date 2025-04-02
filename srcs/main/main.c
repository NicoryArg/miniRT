/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:33:07 by nryser            #+#    #+#             */
/*   Updated: 2025/04/02 18:33:07 by nryser           ###   ########.ch       */
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



int	ft_main_engine(void)
{
	t_engine	engine;

	init_engine(&engine);
	mlx_key_hook(engine.window, on_key_hook_event, &engine);
	mlx_hook(engine.window, 17, 0, on_destroy_event, &engine);
	mlx_loop(engine.mlx);
	cleanup(&engine);
	return (0);
}

int	main()
{
	print_test_banner("RUNNING ALL TESTS");
	// ft_main_tuples();
	// ft_main_transform();
	// ft_main_rays();
	// ft_main_phong();
	ft_main_world();
	//ft_main_engine();
	printf(R_B"END OF ALL TESTS\n"RES);
	return (0);
}

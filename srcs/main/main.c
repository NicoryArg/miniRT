/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:36:04 by nryser            #+#    #+#             */
/*   Updated: 2025/04/11 17:36:04 by nryser           ###   ########.ch       */
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


int	ft_main_engine(int run)
{
	if (run == 0)
		return (0);
	t_engine	engine;

	init_engine(&engine);
	// draw_sphere(&engine);
	draw_world(&engine);
	printf("⚠️\t"AKA"Resizing the window causes the image to disappear \t⚠️\n");
	printf("\tPlease refrain from resizing the window.\n"RES);
	mlx_key_hook(engine.window, on_key_hook_event, &engine);
	mlx_hook(engine.window, 17, 0, on_destroy_event, &engine);
	mlx_loop(engine.mlx);
	cleanup(&engine);
	return (0);
}

int	main()
{
	// print_test_banner("RUNNING ALL TESTS");
	if (ft_main_tuples(0)) //1 to run , 0 to skip
		return (-1);
	if (ft_main_transform(0)) //1 to run , 0 to skip
		return (-1);
	if (ft_main_rays(0)) //1 to run, 0 to skip
		return (-1);
	if (ft_main_phong(0)) //1 to run, 0 to skip
		return (-1);
	if (ft_main_world(0)) //1 to run, 0 to skip
		return (-1);
	if (ft_main_view(1)) //1 to run, 0 to skip
		return (-1);
	if (ft_main_engine(1)) //1 to run, 0 to skip
		return (-1);
	printf(G_B"END OF ALL TESTS\n"RES);
	return (0);
}




////////////////////////////////////////////////////////////////
////////////////////// RUN ALL TESTS ///////////////////////////
////////////////////////////////////////////////////////////////

// int	main()
// {
// 	print_test_banner("RUNNING ALL TESTS");
// 	ft_main_tuples();
// 	ft_main_transform();
// 	ft_main_rays();
// 	ft_main_phong();
// 	printf(R_B"END OF ALL TESTS\n"RES);
// 	return (0);
// }

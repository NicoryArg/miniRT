/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:15:55 by nryser            #+#    #+#             */
/*   Updated: 2025/04/23 17:15:55 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"
#include "tests.h"

int	ft_main_render(int run)
{
	if (run == 0)
		return (0);

	// Run any of the render scenes below by toggling their run flag to 1
	if (ft_main_draw_2d(0))
		return (printf(AKA"❌ draw_2d failed\n"RES));
	if (ft_main_draw_silhouette(0))
		return (printf(AKA"❌ draw_silhouette failed\n"RES));
	if (ft_main_draw_sphere(0))
		return (printf(AKA"❌ draw_sphere failed\n"RES));
	if (ft_main_draw_world(0))
		return (printf(AKA"❌ draw_world failed\n"RES));
	if (ft_main_draw_world_shadows(0))
		return (printf(AKA"❌ draw_world failed\n"RES));
	if (ft_main_draw_scene_patterns(0))
		return (printf(AKA"❌ draw_patterns failed\n"RES));
	if (ft_main_draw_sphere_pattern(0))
		return (printf(AKA"❌ draw_sphere_pattern failed\n"RES));
	if (ft_main_draw_sphere_uv(0))
		return (printf(AKA"❌ draw_sphere_checkers failed\n"RES));
	if (ft_main_draw_sphere_nested(0))
		return (printf(AKA"❌ draw_sphere_nested failed\n"RES));
	if (ft_main_draw_scene_nested(0))
		return (printf(AKA"❌ draw_scene_nested failed\n"RES));
	if (ft_main_draw_world_planes(0))
		return (printf(AKA"❌ draw_world failed\n"RES));
	if (ft_main_draw_infinite_cylinders(0))
		return (printf(AKA"❌ drar_infinite_cylinders failed\n"RES));
	if (ft_main_draw_truncated_cylinders(0))
		return (printf(AKA"❌ draw_truncated_cylinders failed\n"RES));
	printf(G_B"END OF RENDER DEMOS\n"RES);
	return (0);
}


int	run_render_with(void (*render_func)(t_engine *))
{
	t_engine	engine;

	init_engine(&engine);
	render_func(&engine);
	mlx_put_image_to_window(engine.mlx, engine.window,
		engine.image.img_ptr, 0, 0);
	printf(AKA"⚠️\tResizing the window causes the image to disappear \t⚠️\n");
	printf("\tPlease refrain from resizing the window\n"RES);
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
	if (ft_main_view(0)) //1 to run, 0 to skip
		return (-1);
	if (ft_main_shadows(0)) //1 to run, 0 to skip
		return (-1);
	if (ft_main_plane(0))
		return (-1);
	if(ft_main_patterns(0))
		return (-1);
	if (ft_main_cylinder(0))
		return (-1);
	///////////////////////////////////////////////
	if (ft_main_render(1)) //1 to run, 0 to skip
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

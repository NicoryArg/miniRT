/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entrypoint_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:56:17 by nryser            #+#    #+#             */
/*   Updated: 2025/05/05 09:57:30 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"



int	validate_and_load(int ac, char **av, t_input *data)
{
	if (!check_file(ac, av))
		return (-1);
	data->lines = copy_input(av[1]);
	if (!data->lines)
		return (printf(""X"❌ copy_input failed\n"));
	data->list = parse_input(data->lines);
	if (!data->list)
		return(printf(""X"❌ parse_input failed\n"));
	if (valid_input(data, data->bonus))
	{
		// free_data(data);
		return(printf("❌ "INVALID_INPUT""));
	}
	// *scene = build_scene_from_tokens(list);
	return (1);
}

void	draw_scene_parsed(t_engine *engine, t_parsed_scene *scene)
{
	t_world			*w;
	t_camera		cam;

	w = convert_scene_to_world(scene);
	cam = ft_camera(WIN_SIZE, WIN_SIZE, scene->fov);
	cam.transf = view_transform(
			scene->camera_pos,
			add_tuple(scene->camera_pos, scene->camera_dir),
			ft_tuple(0, 1, 0, VECTOR));
	render(cam, w, &engine->image);
	mlx_put_image_to_window(engine->mlx, engine->window,
		engine->image.img_ptr, 0, 0);
	free_world(w);
	free_matrix(cam.transf);
}

////////////TO USE WITH THE OTHER RENDERING FUNCTION
// void	draw_scene_parsed(t_engine *engine, int ac, char **av)
// {
// 	t_parsed_scene	scene;
// 	t_world			*w;
// 	t_camera		cam;

// 	if (validate_and_load(ac, av, &scene) < 0)
// 	{
// 		printf("❌ Failed to load scene file\n");
// 		return;
// 	}
// 	w = convert_scene_to_world(&scene);
// 	cam = ft_camera(WIN_SIZE, WIN_SIZE, 60);
// 	cam.transf = view_transform(
// 		ft_tuple(0, 2, -9, POINT),
// 		ft_tuple(0, 0, 10, POINT),
// 		ft_tuple(0, 1, 0, VECTOR));
// 	render(cam, w, &engine->image);
// 	mlx_put_image_to_window(engine->mlx, engine->window,
// 		engine->image.img_ptr, 0, 0);
// 	free_world(w);
// 	free_matrix(cam.transf);
// }

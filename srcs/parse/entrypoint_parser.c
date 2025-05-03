/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entrypoint_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 08:55:15 by nryser            #+#    #+#             */
/*   Updated: 2025/05/03 08:55:19 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

int	validate_and_load(int ac, char **av, t_parsed_scene *scene)
{
	char		**lines;
	t_tokens	*tokens;

	if (!check_file(ac, av))
		return (-1);
	printf("entering copy_input \n");
	lines = copy_input(av[1]);
	if (!lines)
	{
		printf("❌ copy_input failed\n");
		return (-1);
	}
	printf("Entering parse_input2\n");
	tokens = parse_input(lines);
	if (!tokens)
	{
		printf("❌ parse_input failed\n");
		return (-1);
	}
	printf("entering build_scene\n");
	*scene = build_scene_from_tokens(tokens);
	return (1);
}

void	draw_scene_parsed(t_engine *engine)
{
	t_parsed_scene	scene;
	t_world			*w;
	t_camera		cam;

	if (validate_and_load(2, (char*[]){"./miniRT", "scene.rt"}, &scene) < 0)//under is the correct function for main ↓↓
	{
		printf("❌ Failed to load scene.rt\n");
		return ;
	}
	w = convert_scene_to_world(&scene);
	cam = ft_camera(WIN_SIZE, WIN_SIZE, scene.fov);
	// cam.transf = view_transform(
	// 	ft_tuple(0, 3, -10, POINT),               // Camera above
	// 	ft_tuple(0, 0, 0, POINT),                 // Looking toward the origin
	// 	ft_tuple(0, 1, 0, VECTOR)                 // Up vector
	// );
	cam.transf = view_transform(
		scene.camera_pos,				// from
		add_tuple(scene.camera_pos, scene.camera_dir), // to (camera looks toward pos + dir)
		ft_tuple(0, 1, 0, VECTOR)		// up vector
	);
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


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:48:43 by nryser            #+#    #+#             */
/*   Updated: 2025/04/11 16:49:17 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"

t_camera	ft_camera(double hsize, double vsize, double fov_degrees)
{
	t_camera	camera;
	double		half_view;
	double		aspect;
	double		fov_radians;

	camera.hsize = hsize;
	camera.vsize = vsize;
	fov_radians = fov_degrees * M_PI/180;
	camera.fov = fov_radians;
	camera.transf = create_identity_matrix(4);
	half_view = tan(fov_radians / 2);
	aspect = hsize / vsize;
	if (aspect >= 1)
	{
		camera.half_width = half_view;
		camera.half_height = half_view / aspect;
	}
	else
	{
		camera.half_width = half_view * aspect;
		camera.half_height = half_view;
	}
	camera.pixel_size = (camera.half_width * 2) / camera.hsize;
	return (camera);
}

t_image	render(t_camera cam, t_world *world, t_image img)
{
	int		x;
	int		y;
	t_ray	*ray;
	t_colour col;

	y = 0;
	while (y < (int)cam.vsize)
	{
		x = 0;
		while (x < (int)cam.hsize)
		{
			ray = ray_for_pixel(cam, x, y);
			col = color_at(world, ray);
			put_pixel(&img, x, y, convert_colour_to_int(col));
			free_ray(ray);
			x++;
		}
		y++;
	}
	return (img);
}

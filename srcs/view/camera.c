/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:14:19 by ameechan          #+#    #+#             */
/*   Updated: 2025/04/11 11:36:25 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

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
/**
 * @brief calculates world_x or world_y for get_pxl
 */
static double	w_pt(t_camera cam, int p, char c)
{
	double	offset;

	offset = (p + 0.5) * cam.pixel_size;
	if (c == 'x')
		return (cam.half_width - offset);
	else if (c == 'y')
		return (cam.half_height - offset);
	printf(AKA"Error: w_pt() requires 'x' or 'y'\n"RES);
	return (0);
}

static t_tuple	get_pxl(t_camera cam, double world_x, double world_y)
{
	t_tuple		pixel;
	t_matrix	*pixel_mtx;
	t_matrix	*point;
	t_matrix	*inverse;

	inverse = invert_matrix(cam.transf);
	point = tuple_to_matrix(ft_tuple(world_x, world_y, -1, POINT));
	pixel_mtx = multiply_matrices(inverse, point);
	pixel = matrix_to_tuple(pixel_mtx);
	free_matrix(pixel_mtx);
	free_matrix(point);
	free_matrix(inverse);
	return (pixel);
}

static t_tuple	rfp_origin(t_matrix *transf)
{
	t_matrix	*point;
	t_matrix	*inverse;
	t_matrix	*temp;
	t_tuple		res;

	point = tuple_to_matrix(ft_tuple(0,0,0,POINT));
	inverse = invert_matrix(transf);
	temp = multiply_matrices(inverse, point);
	res = matrix_to_tuple(temp);
	free(point);
	free(inverse);
	free(temp);
	return (res);
}

t_ray	*ray_for_pixel(t_camera cam, int px, int py)
{
	t_tuple	pixel;
	t_ray	*ray;
	t_tuple	origin;
	t_tuple	direction;

	pixel = get_pxl(cam, w_pt(cam,px,'x'), w_pt(cam,py,'y'));
	origin = rfp_origin(cam.transf);
	direction = normalise(diff_tuple(pixel, origin));
	ray = ft_ray(origin, direction);
	return (ray);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_renders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:55:45 by nryser            #+#    #+#             */
/*   Updated: 2025/04/18 21:56:13 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"
#include "tests.h"

int	ft_main_draw_2d(int run)
{
	if (run == 0)
		return (0);
	if (draw_circle(0))
		return (run_render_with(draw_circle_scene));
	if(draw_hour_markers(1))
		return (run_render_with(draw_clock_scene));
	if (draw_trajectory(0))
		return (run_render_with(draw_trajectory_scene));
	printf(AKA"❌ No 2D draw mode was selected\n"RES);
	return (0);
}
int	ft_main_draw_silhouette(int run)
{
	if (run == 0)
		return (0);
	return (run_render_with(draw_silhouette));
}

int	ft_main_draw_sphere(int run)
{
	if (run == 0)
		return (0);
	return (run_render_with(draw_sphere));
}

int	ft_main_draw_world(int run)
{
	if (run == 0)
		return (0);
	return (run_render_with(draw_world));
}

int	ft_main_draw_world_shadows(int run)
{
	if (run == 0)
		return (0);
	return (run_render_with(draw_world_with_shadows));
}

int	ft_main_draw_world_planes(int run)
{
	if (run == 0)
		return (0);
	return (run_render_with(draw_planes));
}

int	ft_main_draw_infinite_cylinders(int run)
{
	if (run == 0)
		return (0);
	return (run_render_with(draw_cyl_infinite));
}

int	ft_main_draw_truncated_cylinders(int run)
{
	if (run == 0)
		return (0);
	return (run_render_with(draw_cyl_truncated));
}

int	ft_main_draw_capped_cylinders(int run)
{
	if (run == 0)
		return (0);
	return (run_render_with(draw_cyl_capped));
}

int	ft_main_draw_patterns(int run)
{
	if (run == 0)
		return (0);
	return (run_render_with(draw_patterns));
}

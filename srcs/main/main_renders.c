/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_renders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:00:31 by nryser            #+#    #+#             */
/*   Updated: 2025/04/18 20:01:10 by nryser           ###   ########.ch       */
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
	if(draw_hour_markers(0))
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

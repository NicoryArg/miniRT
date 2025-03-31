/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_clock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:06:19 by nryser            #+#    #+#             */
/*   Updated: 2025/03/19 22:06:19 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"
#include "engine.h"

#define CLOCK_RADIUS (WIN_SIZE / 4)  // Clock radius = 3/8 of canvas width
#define CENTER_X (WIN_SIZE / 2)  // Center of screen (X)
#define CENTER_Y (WIN_SIZE / 2)  // Center of screen (Y)
#define HOUR_COUNT 12
#define ROTATION_STEP (M_PI / 6) // π/6 radians per hour

static void	compute_hour_position(int hour, t_tuple **transformed)
{
	t_matrix	*rotation;
	t_matrix	*hour_matrix;
	t_matrix	*result_matrix;
	t_tuple		*hour_pos;

	hour_pos = ft_tuple(0, 0, 1, POINT);
	hour_matrix = tuple_to_matrix(hour_pos);
	rotation = rotate_y(hour * ROTATION_STEP);
	result_matrix = multiply_matrices(rotation, hour_matrix);
	*transformed = matrix_to_tuple(result_matrix);
	free_matrix(rotation);
	free_matrix(result_matrix);
	free_matrix(hour_matrix);
	free(hour_pos);
}

void	draw_hour_markers(t_image *img)
{
	t_tuple		*transformed;
	int			hour;
	int			screen_x;
	int			screen_y;

	hour = 0;
	while (hour < HOUR_COUNT)
	{
		// Compute rotated position
		compute_hour_position(hour, &transformed);
		// Scale & Convert to screen coordinates
		screen_x = CENTER_X + (int)(transformed->x * CLOCK_RADIUS);
		screen_y = CENTER_Y - (int)(transformed->z * CLOCK_RADIUS); // Flip Y axis
		draw_marker(img, screen_x, screen_y, COLOR_X, MARKER_SIZE);
		free(transformed);
		hour++;
	}
}



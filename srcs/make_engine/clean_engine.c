/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_engine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:34:14 by nryser            #+#    #+#             */
/*   Updated: 2025/03/18 19:34:17 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/engine.h"

void	error_message(char *text, int mode)
{
	if (mode == 0)
		perror(text);
	else if (text)
		ft_putstr_fd(text, 2);
	exit(EXIT_FAILURE);
}

int	on_destroy_event(t_engine *engine)
{
	mlx_destroy_image(engine->mlx, engine->image.img_ptr);
	mlx_destroy_window(engine->mlx, engine->window);
	exit(EXIT_SUCCESS);
}

void	cleanup(t_engine *engine)
{
	if (engine->image.img_ptr)
	{
		printf("Destroying image\n");
		mlx_destroy_image(engine->mlx, engine->image.img_ptr);
		engine->image.img_ptr = NULL;
	}
	if (engine->window)
	{
		printf("Destroying window\n");
		mlx_destroy_window(engine->mlx, engine->window);
		engine->window = NULL;
	}
}

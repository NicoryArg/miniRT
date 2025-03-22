/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_projectile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:05:05 by nryser            #+#    #+#             */
/*   Updated: 2025/03/19 22:05:23 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"


t_projectile	*new_projectile()
{
	t_projectile	*p;
	t_tuple			*velocity;

	p = malloc(sizeof(t_projectile));
	if (!p)
		return (NULL);
	p->position = make_tuple(1, 1, 0, POINT);
	velocity = make_tuple(1, 2, 0, VECTOR);
	p->velocity = mult_tuple(normalise(velocity), 4.7);
	free(velocity);
	return (p);
}

t_environment	*new_environment()
{
	t_environment	*e;

	e = malloc(sizeof(t_environment));
	if (!e)
		return (NULL);
	e->gravity = make_tuple(0, -0.5, 0, VECTOR);
	e->wind = make_tuple(-0.01, 0, 0, VECTOR);
	return (e);
}

t_projectile	*update_projectile(t_projectile *p, t_environment *e)
{
	t_tuple		*new_pos;
	t_tuple		*new_vel;

	new_vel = add_tuple(p->velocity, add_tuple(e->gravity, e->wind));
	new_pos = add_tuple(p->position, p->velocity);
	if (new_pos->y < 0)
	{
		new_pos->y = 0;
		new_vel->y *= -0.8; // 🔄 Bounce effect (reduce velocity)
	}
	if (magnitude(new_vel) > 500)
		new_vel = mult_tuple(normalise(new_vel), 20);
	free(p->position);
	free(p->velocity);
	p->position = new_pos;
	p->velocity = new_vel;
	return (p);
}


void	draw_trajectory(t_image *img)
{
	t_projectile	*p;
	t_environment	*e;
	int				screen_x;
	int				screen_y;

	p = new_projectile();
	e = new_environment();
	if (!p || !e)
		return ;
	while (p->position->x < WIN_SIZE / SCALE)// width as 2700
	{
		screen_x = (int)(p->position->x * SCALE);
		screen_y = WIN_SIZE - (int)(p->position->y * SCALE);//height as 2700
		draw_marker(img, screen_x, screen_y, RED, MARKER_SIZE);
		p = update_projectile(p, e);
		if (screen_y <= 0 || screen_y >= WIN_SIZE)//height as 2700
			p->velocity->y *= -1;
	}
	free(p->position);
	free(p->velocity);
	free(p);
	free(e->gravity);
	free(e->wind);
	free(e);
}

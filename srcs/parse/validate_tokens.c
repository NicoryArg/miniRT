/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:23:27 by nryser            #+#    #+#             */
/*   Updated: 2025/05/05 09:23:33 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

int	valid_tokens(char **tok)
{
	e_identifier	type;

	if (!tok || !tok[0] || !tok[0][0])
		return (0);
	type = get_identifier(tok[0]);
	if (type == UFO)
	{
		printf("❌ Unknown identifier: '%s'\n", tok[0]);
		return (0);
	}
	if (type == A)
		return (valid_ambient(tok));
	else if (type == C)
		return (valid_camera(tok));
	else if (type == L)
		return (valid_light(tok));
	else if (type == SP)
		return (valid_sphere(tok));
	else if (type == PL)
		return (valid_plane(tok));
	else if (type == CY)
		return (valid_cylinder(tok));
	else if (type == CO)
		return (valid_cone(tok));
	return (0);
}

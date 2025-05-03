/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 07:50:26 by nryser            #+#    #+#             */
/*   Updated: 2025/05/03 07:50:41 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

int	valid_tokens(char **tok)
{
	e_identifier	type;

	if (!tok || !(*tok) || !(**tok))
		return (0);
	type = get_identifier(*tok);
	if (type == UFO)
	{
		printf("❌ get_identifier failed for token: '%s'\n", tok[0]);
		return (0);
	}
	if (type == SP && !valid_sphere(tok))
	{
		printf("❌ valid_sphere failed for line: ");
		for (int i = 0; tok[i]; i++)
			printf("%s ", tok[i]);
		printf("\n");
		return (0);
	}
	else if (type == A && !valid_ambient(tok))
		return (0);
	else if (type == L && !valid_light(tok))
		return (0);
	// else if (type == C)
	// 	return (valid_camera(tok));
	// else if (type == L)
	// 	return (valid_light(tok));
	// else if (type == PL)
	// 	return (valid_plane(tok));
	// else if (type == CY)
	// 	return (valid_cylinder(tok));
	// else if (type == CO)
	// 	return (valid_cone(tok));
	return (1);
}



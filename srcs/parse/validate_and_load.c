/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_and_load.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:13:20 by ameechan          #+#    #+#             */
/*   Updated: 2025/05/01 12:15:29 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	validate_and_load(int ac, char **av)
{
	char		*file;
	char		**lines;
	t_tokens	*head;

	file = av[1];
	lines = NULL;
	if (check_file(ac, av))
		return (-1);
	lines = copy_input(file);
	if (!lines)
		return (-1);
	head = parse_input(lines);
	if (!head)
		return (-1);
	// for (int i = 0; lines[i]; i++)
	// 	printf("%s\n", lines[i]);
	// free_array(lines);
	return (0);
}


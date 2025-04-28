/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_and_load.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:13:20 by ameechan          #+#    #+#             */
/*   Updated: 2025/04/24 18:42:12 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	validate_and_load(int ac, char **av)
{
	char	*file;

	file = av[1];
	if (check_file(ac, av))
		return(1);
	if (check_input(file))
		return(1);
	return (0);
}

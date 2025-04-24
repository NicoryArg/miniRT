/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_and_load.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:13:20 by ameechan          #+#    #+#             */
/*   Updated: 2025/04/24 18:18:42 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int	readable_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	printf(G_B"✔ "GR"readable file\n"RES);
	close(fd);
	return (0);
}


static int	valid_extension(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (i < 4)
		return (-1);
	else if (file[i-1] != 't' || file[i-2] != 'r' || file[i-3] != '.')
		return (-1);
	else
		printf(G_B"✔ "GR"valid extension\n"RES);
	return (0);
}

int	check_file(int ac, char **av)
{
	if (ac != 2)
		return(printf(B_B"usage:"RES" %s <filename>\n", av[0]));
	if (valid_extension(av[1]))
		return(printf(AKA"Error\n❌ invalid extension "RES"`%s`\n", av[1]));
	if (readable_file(av[1]))
		return(printf(AKA"Error\n❌ can't open file "RES"`%s`\n", av[1]));
	if ()
	return (0);
}

int	validate_and_load(int ac, char **av)
{
	if (check_file(ac, av))
		return(1);
	return (0);
}

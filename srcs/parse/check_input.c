/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:42:06 by ameechan          #+#    #+#             */
/*   Updated: 2025/04/28 17:36:09 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int	grab_input(char *file, char **buf)
{
	int	bytes_read;
	int	total_read;
	int	size;
	int	fd;

	size = 10240;
	*buf = calloc(sizeof(char), size);
	fd = open(file, O_RDONLY);
	while ((bytes_read = read(fd, *buf + total_read, size - total_read)) > 0)
	{
		total_read += bytes_read;
		if (total_read >= size)
		{
			free(*buf);
			return(printf(AKA"Error\n❌ File too big"RES" (Max: 10240b)n"));
		}
	}
	if (bytes_read < 0)
	{
		free(*buf);
		return (printf(AKA"Error\n❌ Read error\n"RES));
	}
	close(fd);
	return (0);
}

int	check_input(char *file)
{
	char	*input;

	if (grab_input(file, &input))
		return (-1);
	if ()
	printf("%s", input);
	return (0);
}

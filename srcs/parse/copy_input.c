/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:42:06 by ameechan          #+#    #+#             */
/*   Updated: 2025/04/29 19:42:08 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int	grab_input(char *file, char **buf)
{
	int	bytes_read;
	int	total;
	int	fd;

	total = 0;
	*buf = calloc(sizeof(char), MAX_FILE);
	fd = open(file, O_RDONLY);
	while ((bytes_read = read(fd, *buf + total, MAX_FILE - total)) > 0)
	{
		total += bytes_read;
		if (total >= MAX_FILE)
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
	printf(G_B"✔ "GR"input grabbed\n"RES);
	return (0);
}

static int	count_lines(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == '\n')
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != '\n')
			i++;
	}
	return (count);
}

static char **alloc_lines(char *str)
{
	int		i;
	int		count;
	char	**lines;

	i = 0;
	count = count_lines(str);
	lines = calloc(count + 1, sizeof(char *));
	if (!lines)
		return (NULL);
	while (i < count)
	{
		lines[i] = calloc(MAX_LINE_LEN, sizeof(char));
		if (!lines[i])
			free_array(lines);
		i++;
	}
	return (lines);
}


char	**copy_input(char *file)
{
	char	*input;
	char	**lines;

	if (grab_input(file, &input))
		return (NULL);
	lines = alloc_lines(input);
	if (!lines)
		return (NULL);
	if (split_lines(input, lines))
		free_array(lines);
	free(input);
	return (lines);
}

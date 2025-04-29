/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:17:29 by ameechan          #+#    #+#             */
/*   Updated: 2025/04/29 21:10:44 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# define MAX_FILE 10240
# define MAX_LINE_LEN 51

typedef enum identifier
{
	A,
	C,
	L,
	SP,
	PL,
	CY,
	CO,
	UFO,
}	e_identifier;

//check_file.c
int		check_file(int ac, char **av);

//copy_input.c
char	**copy_input(char *file);

//free_parse.c
void	free_array(char **array);

//split_lines.c
int		split_lines(char *str, char **lines);

//validate_and_load.c
int		validate_and_load(int ac, char **av);

//validate_input.c
int		validate_input(char **lines);

//ERROR MESSAGE UTILS

# define X "Error\n"
# define O "✔ "GR""
# define INVALID_ID ""X""RES"`"AKA"%s"RES"`is invalid identifier\n"

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:17:29 by ameechan          #+#    #+#             */
/*   Updated: 2025/05/01 12:14:22 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# define MAX_FILE 10240
# define MAX_LINE_LEN 51

typedef struct s_tokens t_tokens;

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

typedef struct s_input
{
	int			shapes;			//number of shape identifiers (sp, cy, etc.)
	char		**lines;		//2d array for each line of the input file
	t_tokens	*head;			//first pointer to linked list of tokens (for each line)
}	t_input;

typedef struct s_tokens
{
	char			**tokens;	//2d array of all args for a given identifier
	e_identifier	type;		//identifier type (A, C, L, sp, cy, etc.)
	int				count;		//number of arguments (sp expects 4, A expects 3, etc.)
	t_tokens		*next;		//pointer to next identifier and it's arguments
}	t_tokens;

//build_list.c
t_tokens	*create_token_node(char **tokens, e_identifier type);
void		append_token_node(t_tokens **head, t_tokens *new_node);
void		print_node(t_tokens *node);

//check_file.c
int			check_file(int ac, char **av);

//copy_input.c
char		**copy_input(char *file);

//free_parse.c
void		free_array(char **array);

//split_lines.c
int			split_lines(char *str, char **lines);

//validate_and_load.c
int			validate_and_load(int ac, char **av);

//parse_input.c
t_tokens	*parse_input(char **lines);

//ERROR MESSAGE UTILS

# define X "Error\n"
# define O "✔ "GR""
# define INVALID_ID ""X""RES"`"AKA"%s"RES"`is invalid identifier\n"

#endif

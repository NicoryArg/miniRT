/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:17:29 by ameechan          #+#    #+#             */
/*   Updated: 2025/04/24 18:44:31 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

//check_file.c
int	check_file(int ac, char **av);

//check_input.c
int	check_input(char *file);

//validate_and_load.c
int	validate_and_load(int ac, char **av);

#endif

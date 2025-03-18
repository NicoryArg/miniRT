/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:53:12 by ameechan          #+#    #+#             */
/*   Updated: 2025/03/18 18:17:55 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	print_tuple(t_tuple *tuple, char *name)
{
	if (is_vector(tuple))
		printf(G_B"tuple `%s` is VECTOR:\n"RES, name);
	else if (is_point(tuple))
		printf(G_B"tuple `%s` is POINT:\n"RES, name);
	else
		printf(R_B"ERROR:"RES" tuple type undefined\n");
	printf(YEL"\tx:"RES" %.5f\n", tuple->x);
	printf(YEL"\ty:"RES" %.5f\n", tuple->y);
	printf(YEL"\tz:"RES" %.5f\n", tuple->z);
	printf(YEL"\tw:"RES" %d\n", tuple->w);
}
void	print_matrix(t_matrix *matrix)
{
	int		i;
	int		j;

	i = 0;
	while (i < matrix->rows)
	{
		printf("|");
		j = 0;
		while (j < matrix->cols)
		{
			if (matrix->values[i][j] == (int)matrix->values[i][j])
				printf(" %6.0f |", matrix->values[i][j]);
			else
				printf(" %10.5f |", matrix->values[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	print_test_banner(const char *word)
{
	int total_width = 62;  // Adjust if needed
	int word_length = strlen(word);
	int padding = (total_width - word_length - 4) / 2;  // 4 accounts for spaces around word
	int extra = (total_width - word_length - 4) % 2;    // Handle odd length cases

	printf(B_B"##############################################################\n");
	printf("#%*s%s%*s#\n", padding, "", word, padding + extra, "");
	printf("##############################################################\n"RES);
}

void	print_test_number(int *i)
{
	printf(CYAN"##### TEST %d #####\n"RES, (*i)++);
}

void	malloc_err(char *func_name)
{
	printf(R_B"Error:"RES" [%s] -> failed to allocate memory\n", func_name);
	exit(1);
}




//##############################################################//
//######################## OBSOLETE ###########################//
//##############################################################//



/*
void	print_rs(t_ray_sphere *rs)
{
	// printf(G_B"x_count:"RES" %d\n", rs->x_count);
	printf(G_B"tc:"RES" %f\n", rs->tc);
	print_tuple(rs->l, "rs->l");
	printf(G_B"l_len:"RES"\t%f\n", rs->l_len);
	printf(G_B"d:"RES" %f\n", rs->d);
	printf(G_B"offset:"RES" %f\n", rs->offset);
} */

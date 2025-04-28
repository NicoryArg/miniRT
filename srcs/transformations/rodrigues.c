/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rodrigues.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:14:17 by nryser            #+#    #+#             */
/*   Updated: 2025/04/28 17:22:54 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "engine.h"

#include "minirt.h"

t_matrix	*build_skew_matrix(t_tuple v)
{
	t_matrix	*skew;

	skew = create_matrix(4, 4, 0);
	skew->values[0][0] = 0;
	skew->values[0][1] = -v.z;
	skew->values[0][2] = v.y;
	skew->values[1][0] = v.z;
	skew->values[1][1] = 0;
	skew->values[1][2] = -v.x;
	skew->values[2][0] = -v.y;
	skew->values[2][1] = v.x;
	skew->values[2][2] = 0;
	skew->values[3][3] = 1;
	return (skew);
}

t_matrix	*add_matrices(t_matrix *a, t_matrix *b)
{
	t_matrix	*result;
	int			i;
	int			j;

	result = create_matrix(a->rows, a->cols, 0);
	i = 0;
	while (i < a->rows)
	{
		j = 0;
		while (j < a->cols)
		{
			result->values[i][j] = a->values[i][j] + b->values[i][j];
			j++;
		}
		i++;
	}
	return (result);
}

void	add_matrices_inplace(t_matrix *a, t_matrix *b)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->rows)
	{
		j = 0;
		while (j < a->cols)
		{
			a->values[i][j] += b->values[i][j];
			j++;
		}
		i++;
	}
}

static t_matrix	*handle_special_case(double c, t_tuple from)
{
	t_tuple	axis;

	if (fabs(c - 1.0) < EPSILON)
		return (create_identity_matrix(4));
	if (fabs(c + 1.0) < EPSILON)
	{
		axis = cross(from, ft_tuple(1, 0, 0, VECTOR));
		if (magnitude(axis) < EPSILON)
			axis = cross(from, ft_tuple(0, 1, 0, VECTOR));
		axis = normalize(axis);
		return (multiply_matrices(rotate_x(M_PI), rotate_y(M_PI)));
	}
	return (NULL);
}

t_matrix	*rotation_matrix(t_tuple from, t_tuple to)
{
	t_tuple		v;
	double		c;
	double		k;
	t_matrix	*skew;
	t_matrix	*skew_sq;
	t_matrix	*result;
	t_matrix	*special;

	from = normalize(from);
	to = normalize(to);
	c = dot(from, to);
	special = handle_special_case(c, from);
	if (special)
		return (special);
	v = cross(from, to);
	skew = build_skew_matrix(v);
	skew_sq = multiply_matrices(skew, skew);
	k = 1.0 / (1.0 + c);
	scale_matrix(skew_sq, k);
	result = add_matrices(create_identity_matrix(4), skew);
	add_matrices_inplace(result, skew_sq);
	free_matrix(skew);
	free_matrix(skew_sq);
	return (result);
}

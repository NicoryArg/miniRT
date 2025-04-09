/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:02:21 by nryser            #+#    #+#             */
/*   Updated: 2025/04/09 21:02:21 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"
#include "engine.h"

int	view_transform_test(int run)
{
	if (!run)
		return (0);
	int i = 1;
	t_tuple from, to, up;
	t_matrix *t, *expected;

	// TEST 1 — Default orientation
	print_test_banner("View transform: default orientation");
	print_test_number(&i);
	from = ft_tuple(0, 0, 0, POINT);
	to = ft_tuple(0, 0, -1, POINT);
	up = ft_tuple(0, 1, 0, VECTOR);
	t = view_transform(from, to, up);
	expected = create_identity_matrix(4);
	printf(B_B"computed:\n"RES); print_matrix(t);
	printf(G_B"expected:\n"RES); print_matrix(expected);
	if (equal_matrix(t, expected))
		printf(GR"✔ transformation is identity\n"RES);
	else
		printf(AKA"❌ transformation is not identity\n"RES);
	printf("________________________________________________\n");
	free_matrix(t);
	free_matrix(expected);

	// TEST 2 — Looking in positive z direction
	print_test_banner("View transform: looking in positive Z");
	print_test_number(&i);
	from = ft_tuple(0, 0, 0, POINT);
	to = ft_tuple(0, 0, 1, POINT);
	up = ft_tuple(0, 1, 0, VECTOR);
	t = view_transform(from, to, up);
	expected = scale(-1, 1, -1);
	printf(B_B"computed:\n"RES); print_matrix(t);
	printf(G_B"expected:\n"RES); print_matrix(expected);
	if (equal_matrix(t, expected))
		printf(GR"✔ transformation matches scaling(-1, 1, -1)\n"RES);
	else
		printf(AKA"❌ transformation does not match expected\n"RES);
	printf("________________________________________________\n");
	free_matrix(t);
	free_matrix(expected);

	// TEST 3 — View transformation moves the world
	print_test_banner("View transform: moving the world");
	print_test_number(&i);
	from = ft_tuple(0, 0, 8, POINT);
	to = ft_tuple(0, 0, 0, POINT);
	up = ft_tuple(0, 1, 0, VECTOR);
	t = view_transform(from, to, up);
	expected = translate(0, 0, -8);
	printf(B_B"computed:\n"RES); print_matrix(t);
	printf(G_B"expected:\n"RES); print_matrix(expected);
	if (equal_matrix(t, expected))
		printf(GR"✔ transformation matches translation(0,0,-8)\n"RES);
	else
		printf(AKA"❌ transformation does not match expected\n"RES);
	printf("________________________________________________\n");
	free_matrix(t);
	free_matrix(expected);

	// TEST 4 — Arbitrary view transformation
	print_test_banner("View transform: arbitrary orientation");
	print_test_number(&i);
	from = ft_tuple(1, 3, 2, POINT);
	to = ft_tuple(4, -2, 8, POINT);
	up = ft_tuple(1, 1, 0, VECTOR);
	t = view_transform(from, to, up);
	expected = create_matrix(4, 4, 0);
	expected->values[0][0] = -0.50709;
	expected->values[0][1] = 0.50709;
	expected->values[0][2] = 0.67612;
	expected->values[0][3] = -2.36643;
	expected->values[1][0] = 0.76772;
	expected->values[1][1] = 0.60609;
	expected->values[1][2] = 0.12122;
	expected->values[1][3] = -2.82843;
	expected->values[2][0] = -0.35857;
	expected->values[2][1] = 0.59761;
	expected->values[2][2] = -0.71714;
	expected->values[2][3] = 0.00000;
	expected->values[3][0] = 0.00000;
	expected->values[3][1] = 0.00000;
	expected->values[3][2] = 0.00000;
	expected->values[3][3] = 1.00000;
	printf(B_B"computed:\n"RES); print_matrix(t);
	printf(G_B"expected:\n"RES); print_matrix(expected);
	if (equal_matrix(t, expected))
		printf(GR"✔ transformation matches expected matrix\n"RES);
	else
		printf(AKA"❌ transformation does not match expected\n"RES);
	printf("________________________________________________\n");
	free_matrix(t);
	free_matrix(expected);

	return (0);
}


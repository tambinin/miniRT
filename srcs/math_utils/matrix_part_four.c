/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_part_four.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:24:53 by tambinin          #+#    #+#             */
/*   Updated: 2025/03/14 18:25:10 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_tuple	new_tuple(float x, float y, float z)
{
	t_tuple	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_tuple	new_point(float x, float y, float z)
{
	t_tuple	a;

	a = new_tuple(x, y, z);
	return (a);
}

t_tuple	new_vect(float x, float y, float z)
{
	t_tuple	a;

	a = new_tuple(x, y, z);
	return (a);
}

t_tuple	mult_mat_tp(t_mat a, t_tuple b)
{
	int		i;
	float	p[MAX];
	t_tuple	c;

	i = 0;
	while (i < MAX)
	{
		p[i] = 0.0f;
		i++;
	}
	i = 1;
	while (i < MAX)
	{
		p[i] = a.mat[i][0] * b.x + a.mat[i][1] * b.y + a.mat[i][2] * b.z;
		i++;
	}
	c = new_tuple(p[1], p[2], p[3]);
	return (c);
}

t_vect	mult_mat_vect(t_mat a, t_vect b)
{
	t_vect	res;

	res = new_vect(0.0, 0.0, 0.0);
	res.x = a.mat[0][0] * b.x + a.mat[0][1] * b.y + a.mat[0][2] * b.z;
	res.y = a.mat[1][0] * b.x + a.mat[1][1] * b.y + a.mat[1][2] * b.z;
	res.z = a.mat[2][0] * b.x + a.mat[2][1] * b.y + a.mat[2][2] * b.z;
	return (res);
}

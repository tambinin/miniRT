/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:21:29 by tambinin          #+#    #+#             */
/*   Updated: 2025/03/14 18:21:46 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float	determinant(t_mat a)
{
	float	d;
	int		j;

	d = 0;
	if (a.size == 2)
		d = a.mat[0][0] * a.mat[1][1] - a.mat[0][1] * a.mat[1][0];
	else
	{
		j = 0;
		while (j < a.size)
		{
			d = d + (a.mat[0][j] * cofactor(a, 0, j));
			j++;
		}
	}
	return (d);
}

float	cofactor(t_mat a, int i, int j)
{
	float	res;
	int		sign;

	sign = 1;
	res = minor(a, i, j);
	if ((i + j) % 2 == 0)
		sign = 1;
	else
		sign = -1;
	return (res * sign);
}

float	minor(t_mat a, int i, int j)
{
	float	res;
	t_mat	b;

	b = submatrix(a, i, j);
	res = determinant(b);
	return (res);
}

t_mat	inverse(t_mat a)
{
	int		i;
	int		j;
	float	det;
	float	m[MAX][MAX];
	t_mat	b;

	if (invertible(a) == true)
	{
		det = determinant(a);
		i = 0;
		while (i < a.size)
		{
			j = 0;
			while (j < a.size)
			{
				m[i][j] = cofactor(a, i, j) / det;
				j++;
			}
			i++;
		}
		b = create_mat(m, MAX);
	}
	else
		b = identity_mat();
	return (b);
}

t_mat	transpose(t_mat a)
{
	int		i;
	int		j;
	float	m[MAX][MAX];
	t_mat	b;

	i = 0;
	while (i < a.size)
	{
		j = 0;
		while (j < a.size)
		{
			m[j][i] = a.mat[i][j];
			j++;
		}
		i++;
	}
	b = create_mat(m, a.size);
	return (b);
}

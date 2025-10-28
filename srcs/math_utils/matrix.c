/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:30:12 by candriam          #+#    #+#             */
/*   Updated: 2025/03/14 18:36:25 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_mat	create_mat(float mat[MAX][MAX], int size)
{
	t_mat	a;
	int		count;

	a.size = size;
	count = size * size;
	ft_memmove(a.mat, mat, sizeof(float) * count);
	return (a);
}

int	compare_mat(t_mat a, t_mat b)
{
	int	res;

	res = ft_memcmp(a.mat, b.mat, sizeof(float) * COUNT);
	if (!res)
		return (0);
	else
		return (res);
}

bool	invertible(t_mat a)
{
	if (determinant(a) == 0)
		return (false);
	return (true);
}

static void	init_mult_mat(float m[MAX][MAX])
{
	int		i;
	int		j;

	i = 0;
	while (i < MAX)
	{
		j = 0;
		while (j < MAX)
		{
			m[i][j] = 0.0;
			j++;
		}
		i++;
	}
}

t_mat	multiply_mat(t_mat a, t_mat b)
{
	int		i;
	int		j;
	int		k;
	float	m[MAX][MAX];
	t_mat	c;

	init_mult_mat(m);
	i = 0;
	while (i < MAX)
	{
		j = 0;
		while (j < MAX)
		{
			k = 0;
			while (k < MAX)
			{
				m[i][j] += a.mat[i][k] * b.mat[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	c = create_mat(m, MAX);
	return (c);
}

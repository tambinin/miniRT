/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_part_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:22:52 by tambinin          #+#    #+#             */
/*   Updated: 2025/03/14 18:23:11 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	add_mat(float a[MAX][MAX], float b[MAX][MAX], float m[MAX][MAX])
{
	int	i;
	int	j;

	i = 0;
	while (i < MAX)
	{
		j = 0;
		m[i][j] = 0;
		while (j < MAX)
		{
			m[i][j] = a[i][j] + b[i][j];
			j++;
		}
		i++;
	}
}

void	sub_mat(float a[MAX][MAX], float b[MAX][MAX], float m[MAX][MAX])
{
	int	i;
	int	j;

	i = 0;
	while (i < MAX)
	{
		j = 0;
		m[i][j] = 0;
		while (j < MAX)
		{
			m[i][j] = a[i][j] - b[i][j];
			j++;
		}
		i++;
	}
}

void	scale_mat(float a[MAX][MAX], float k, float m[MAX][MAX])
{
	int	i;
	int	j;

	i = 0;
	while (i < MAX)
	{
		j = 0;
		m[i][j] = 0;
		while (j < MAX)
		{
			m[i][j] = k * a[i][j];
			j++;
		}
		i++;
	}
}

t_mat	identity_mat(void)
{
	float	mat[MAX][MAX];
	t_mat	a;

	ft_memset(mat, 0, sizeof(mat));
	mat[0][0] = 1;
	mat[1][1] = 1;
	mat[2][2] = 1;
	mat[3][3] = 1;
	a = create_mat(mat, MAX);
	return (a);
}

t_mat	submatrix(t_mat a, int rem_i, int rem_j)
{
	int		i;
	int		j;
	float	m[MAX][MAX];
	t_mat	b;

	if (a.size == 0)
		b = identity_mat();
	i = 0;
	while (i < a.size - 1)
	{
		j = 0;
		while (j < a.size - 1)
		{
			m[i][j] = a.mat[i + (i >= rem_i)][j + (j >= rem_j)];
			j++;
		}
		i++;
	}
	b = create_mat(m, a.size - 1);
	return (b);
}

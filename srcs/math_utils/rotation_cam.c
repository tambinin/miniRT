/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:27:50 by tambinin          #+#    #+#             */
/*   Updated: 2025/03/14 19:28:12 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_mat	rotate_on_x(float degree)
{
	float	mat[MAX][MAX];
	t_mat	x;
	float	rad;

	ft_memset(mat, 0, sizeof(mat));
	rad = degree * M_PI / 180.0;
	mat[0][0] = 1;
	mat[1][1] = cos(rad);
	mat[1][2] = -sin(rad);
	mat[2][1] = sin(rad);
	mat[2][2] = cos(rad);
	mat[3][3] = 1;
	x = create_mat(mat, MAX);
	return (x);
}

t_mat	rotate_on_y(float degree)
{
	float	mat[MAX][MAX];
	t_mat	y;
	float	rad;

	ft_memset(mat, 0, sizeof(mat));
	rad = degree * M_PI / 180.0;
	mat[0][0] = cos(rad);
	mat[1][1] = 1;
	mat[2][0] = -sin(rad);
	mat[0][2] = sin(rad);
	mat[2][2] = cos(rad);
	mat[3][3] = 1;
	y = create_mat(mat, MAX);
	return (y);
}

t_mat	rotate_on_z(float degree)
{
	float	mat[MAX][MAX];
	t_mat	z;
	float	rad;

	ft_memset(mat, 0, sizeof(mat));
	rad = degree * M_PI / 180.0;
	mat[0][0] = cos(rad);
	mat[1][0] = sin(rad);
	mat[0][1] = -sin(rad);
	mat[1][1] = cos(rad);
	mat[2][2] = 1;
	mat[3][3] = 1;
	z = create_mat(mat, MAX);
	return (z);
}

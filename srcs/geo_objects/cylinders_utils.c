/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinders_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:38:22 by tambinin          #+#    #+#             */
/*   Updated: 2025/03/14 17:38:46 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float	calcul_discriminant(float a, float b, float c)
{
	float	delta;

	delta = square(b) - 4 * a * c;
	return (delta);
}

float	solve_roots(float a, float b, float delta, float *t)
{
	if (fabs(delta) < EPSILON)
	{
		t[0] = -b / (2 * a);
		if (t[0] >= 0)
			return (t[0]);
		else
			return (-1.0);
	}
	delta = sqrt(delta);
	t[0] = (-b - delta) / (2 * a);
	t[1] = (-b + delta) / (2 * a);
	if (t[0] > t[1])
		ft_swap(&t[0], &t[1]);
	if (t[0] >= 0)
		return (t[0]);
	else if (t[1] >= 0)
		return (t[1]);
	else
		return (-1.0);
}

float	solve_second_degree(float a, float b, float c)
{
	float	delta;
	float	t[2];
	float	res;

	delta = calcul_discriminant(a, b, c);
	if (delta < 0)
		return (-1.0);
	res = solve_roots(a, b, delta, t);
	return (res);
}

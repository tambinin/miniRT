/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:29:03 by candriam          #+#    #+#             */
/*   Updated: 2025/02/02 12:25:18 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float	dot_product(t_vect a, t_vect b)
{
	float	c;

	c = a.x * b.x + a.y * b.y + a.z * b.z;
	return (c);
}

t_vect	cross_product(t_vect a, t_vect b)
{
	t_vect	c;

	c.x = a.y * b.z - a.z * b.y;
	c.y = a.z * b.x - a.x * b.z;
	c.z = a.x * b.y - a.y * b.x;
	return (c);
}

float	magnitude(t_vect a)
{
	float	len;

	len = sqrtf(dot_product(a, a));
	return (len);
}

t_vect	normalize(t_vect a)
{
	t_vect	res;
	float	len;

	len = magnitude(a);
	if (len < 0.001)
		return (new_vect(0.0, 0.0, 0.0));
	res.x = a.x / len;
	res.y = a.y / len;
	res.z = a.z / len;
	return (res);
}

float	length(t_vect *u, t_vect *v)
{
	float	dx;
	float	dy;
	float	dz;

	dx = v->x - u->x;
	dy = v->y - u->y;
	dz = v->z - u->z;
	return (sqrt(dx * dx + dy * dy + dz * dz));
}

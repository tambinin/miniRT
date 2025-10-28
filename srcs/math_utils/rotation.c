/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:41:08 by tambinin          #+#    #+#             */
/*   Updated: 2025/03/14 19:28:44 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_pt	rotate_x(t_pt p, float angle)
{
	t_pt	rotated;
	float	rad;

	rad = angle * (M_PI / 180.0);
	rotated.x = p.x;
	rotated.y = p.y * cos(rad) - p.z * sin(rad);
	rotated.z = p.y * sin(rad) + p.z * cos(rad);
	return (rotated);
}

t_pt	rotate_y(t_pt p, float angle)
{
	t_pt	rotated;
	float	rad;

	rad = angle * (M_PI / 180.0);
	rotated.x = p.x * cos(rad) + p.z * sin(rad);
	rotated.y = p.y;
	rotated.z = -p.x * sin(rad) + p.z * cos(rad);
	return (rotated);
}

t_pt	rotate_z(t_pt p, float angle)
{
	t_pt	rotated;
	float	rad;

	rad = angle * (M_PI / 180.0);
	rotated.x = p.x * cos(rad) - p.y * sin(rad);
	rotated.y = p.x * sin(rad) + p.y * cos(rad);
	rotated.z = p.z;
	return (rotated);
}

t_vect	rotate_vect(t_vect v, float angle_x, float angle_y, float angle_z)
{
	v = rotate_x(v, angle_x);
	v = rotate_y(v, angle_y);
	v = rotate_z(v, angle_z);
	return (v);
}

t_vect	rotate_around_center(t_vect point, t_vect center, float angle[3])
{
	t_vect	translated_point;

	translated_point = sub_vect(point, center);
	translated_point = rotate_vect(translated_point, angle[0], angle[1],
			angle[2]);
	return (add_vect(translated_point, center));
}

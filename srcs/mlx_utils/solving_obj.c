/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 23:14:07 by tambinin          #+#    #+#             */
/*   Updated: 2025/03/14 23:15:01 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	solve_quad(float *t, t_vect ray_dir, t_vect ray_orig, t_shape *shape)
{
	t_vect	pos;
	t_vect	oc;
	float	delta;
	float	var[2];
	float	radius;

	pos = shape->form.sp.position;
	radius = shape->form.sp.radius;
	oc = sub_vect(ray_orig, pos);
	var[0] = 2 * dot_product(oc, ray_dir);
	var[1] = dot_product(oc, oc) - radius * radius;
	delta = var[0] * var[0] - 4 * var[1];
	if (delta > 0)
	{
		delta = sqrt(delta);
		t[0] = (-var[0] - delta) / (2 * var[1]);
		t[1] = (-var[0] + delta) / (2 * var[1]);
		if (t[0] > 0 || t[1] > 0)
		{
			*t = fmin(t[0], t[1]);
			return (1);
		}
	}
	return (0);
}

int	solve_plane(float *var, t_vect ray_dir, t_vect ray_orig, t_shape *shape)
{
	t_vect	normal;
	t_vect	point;
	t_vect	ray;
	float	div;

	normal = shape->form.pl.normal;
	point = shape->form.pl.position;
	div = dot_product(ray_dir, normal);
	if (fabs(div) < EPSILON)
		return (0);
	ray = sub_vect(point, ray_orig);
	*var = dot_product(ray, normal) / div;
	if (*var > EPSILON)
	{
		return (1);
	}
	return (0);
}

int	solve_cylinder(float *t, t_vect ray_dir, t_vect ray_orig, t_shape *shape)
{
	t_vect	axis;
	t_vect	oc;
	float	delta;
	float	var[3];

	axis = shape->form.cy.normal;
	oc = sub_vect(ray_orig, shape->form.cy.base);
	var[0] = dot_product(ray_dir, ray_dir) - pow(dot_product(axis, ray_dir), 2);
	var[1] = 2 * (dot_product(ray_dir, oc) - dot_product(ray_dir, axis)
			* dot_product(oc, axis));
	var[2] = dot_product(oc, oc) - pow(dot_product(oc, axis), 2)
		- (shape->form.cy.radius * shape->form.cy.radius);
	delta = var[1] * var[1] - 4 * var[0] * var[2];
	if (delta < 0)
		return (0);
	delta = sqrt(delta);
	t[0] = (-var[1] - delta) / (2 * var[0]);
	t[1] = (-var[1] + delta) / (2 * var[0]);
	if (t[0] > 0 || t[1] > 0)
	{
		*t = fmin(t[0], t[1]);
		return (1);
	}
	return (0);
}

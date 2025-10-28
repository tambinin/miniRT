/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:30:41 by candriam          #+#    #+#             */
/*   Updated: 2025/02/10 11:06:00 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float	square(float a)
{
	float	res;

	res = a * a;
	return (res);
}

void	ft_swap(float *t1, float *t2)
{
	float	tmp;

	tmp = *t1;
	*t1 = *t2;
	*t2 = tmp;
}

float	solve_quadratic(float b, float c)
{
	float	d;
	float	t[2];

	d = (b * b) - 4 * c;
	if (d < 0)
		return (-1.0);
	d = sqrt(d);
	t[0] = (-b - d) / 2;
	t[1] = (-b + d) / 2;
	if (t[0] > t[1])
		ft_swap(&t[0], &t[1]);
	if (t[0] >= 0)
		return (t[0]);
	else if (t[1] >= 0)
		return (t[1]);
	else
		return (-1);
}

t_hit	*sphere_intersect(t_ray *ray, t_sphere *sp)
{
	t_vect	oc;
	t_hit	*hit;
	float	var[2];
	float	t;

	hit = safe_calloc();
	oc = sub_vect(ray->origin, sp->position);
	var[0] = 2 * (dot_product(oc, ray->direction));
	var[1] = dot_product(oc, oc) - sp->radius * sp->radius;
	t = solve_quadratic(var[0], var[1]);
	if (t < 0)
	{
		hit->distance = INFINITY;
		return (hit);
	}
	hit->fig = SPHERE;
	hit->form.sp = *sp;
	hit->distance = t;
	hit->point = add_vect(ray->origin, scale(ray->direction, t));
	hit->normal = normalize(sub_vect(hit->point, sp->position));
	return (hit);
}

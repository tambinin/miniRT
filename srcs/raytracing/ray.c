/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:27:23 by candriam          #+#    #+#             */
/*   Updated: 2025/02/10 09:39:57 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include <string.h>

t_ray	new_ray(t_pt origin, t_vect direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

t_pt	position(t_ray ray, float distance)
{
	t_pt	pos;

	pos = add_vect(ray.origin, scale(ray.direction, distance));
	return (pos);
}

int	is_nearest(t_hit *nearest, t_hit *stash)
{
	if (stash->distance == INFINITY && nearest->distance)
		return (0);
	if (stash->distance < nearest->distance)
		return (1);
	return (0);
}

t_hit	*shape_intersect(t_ray *ray, t_shape *shape)
{
	t_hit	*tmp_hit;

	tmp_hit = NULL;
	if (shape->fig == SPHERE)
		tmp_hit = sphere_intersect(ray, &shape->form.sp);
	else if (shape->fig == PLANE)
		tmp_hit = plane_intersect(ray, &shape->form.pl);
	else if (shape->fig == CYLINDER)
		tmp_hit = cylinder_intersect(ray, &shape->form.cy);
	return (tmp_hit);
}

t_hit	*return_hit(t_minirt *rt, t_ray *ray)
{
	t_shape	*shape;
	t_hit	*closest;
	t_hit	*tmp_hit;

	tmp_hit = NULL;
	closest = ft_calloc(sizeof(t_hit), 1);
	closest->distance = INFINITY;
	shape = rt->scene->shape;
	while (shape)
	{
		closest->pos = shape->pos;
		tmp_hit = shape_intersect(ray, shape);
		if (closest && tmp_hit->distance > 0
			&& tmp_hit->distance < closest->distance)
		{
			if (closest != tmp_hit)
				free_hit(closest);
			closest = tmp_hit;
		}
		else
			free_hit(tmp_hit);
		shape = shape->next;
	}
	return (closest);
}

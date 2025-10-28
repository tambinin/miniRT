/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:27:53 by candriam          #+#    #+#             */
/*   Updated: 2025/02/02 21:54:11 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include <string.h>

void	hit_surface(t_ray *ray, t_shape *shape, t_hit **hit)
{
	if (shape->fig == SPHERE)
		*hit = sphere_intersect(ray, &shape->form.sp);
	else if (shape->fig == PLANE)
		*hit = plane_intersect(ray, &shape->form.pl);
	else if (shape->fig == CYLINDER)
		*hit = cylinder_intersect(ray, &shape->form.cy);
}

void	save_hit(float *max_dist, t_hit **near, t_hit *tmp_hit, int *in)
{
	if (tmp_hit->distance < *max_dist)
	{
		*max_dist = tmp_hit->distance;
		if (*near)
			free_hit(*near);
		*near = tmp_hit;
		*in = 1;
	}
}

int	hit_object(t_ray *ray, t_minirt *rt, float max)
{
	int		in_shadow;
	t_shape	*obj;
	t_hit	*hit;
	t_hit	*near;

	obj = rt->scene->shape;
	in_shadow = 0;
	ray->hit = NULL;
	near = NULL;
	while (obj)
	{
		hit_surface(ray, obj, &hit);
		if (hit && hit->distance > EPSILON && hit->distance < max)
			save_hit(&max, &near, hit, &in_shadow);
		else if (hit)
			free_hit(hit);
		obj = obj->next;
	}
	if (near)
		ray->hit = near;
	return (in_shadow);
}

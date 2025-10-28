/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:30:53 by candriam          #+#    #+#             */
/*   Updated: 2025/03/14 18:04:07 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float	calculate_plane_inter(t_ray *ray, t_plane *plane)
{
	float	div;
	float	t;

	plane->normal = normalize(plane->normal);
	div = dot_product(plane->normal, ray->direction);
	if (fabs(div) < EPSILON)
		return (INFINITY);
	t = dot_product(sub_vect(plane->position, ray->origin), plane->normal)
		/ div;
	if (t < EPSILON)
		return (INFINITY);
	return (t);
}

t_hit	*plane_intersect(t_ray *ray, t_plane *plane)
{
	float	t;
	t_hit	*hit;

	hit = safe_calloc();
	t = calculate_plane_inter(ray, plane);
	if (t == INFINITY)
	{
		hit->distance = INFINITY;
		return (hit);
	}
	hit->fig = PLANE;
	hit->form.pl = *plane;
	hit->distance = t;
	hit->point = add_vect(ray->origin, scale(ray->direction, t));
	hit->point = add_vect(hit->point, scale(hit->normal, EPSILON));
	hit->normal = plane->normal;
	return (hit);
}

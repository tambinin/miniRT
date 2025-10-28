/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinders.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:31:03 by candriam          #+#    #+#             */
/*   Updated: 2025/03/14 17:38:52 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float	solve_cy_equa(t_ray *ray, t_cylinder *cy)
{
	float	var[4];
	t_vect	oc;
	float	dot[2];
	t_vect	dn;
	t_vect	oc_n;

	oc = sub_vect(ray->origin, cy->base);
	dot[0] = dot_product(ray->direction, cy->normal);
	dot[1] = dot_product(oc, cy->normal);
	dn = sub_vect(ray->direction, scale(cy->normal, dot[0]));
	oc_n = sub_vect(oc, scale(cy->normal, dot[1]));
	var[0] = dot_product(dn, dn);
	var[1] = 2 * dot_product(dn, oc_n);
	var[2] = dot_product(oc_n, oc_n) - square(cy->radius);
	var[3] = solve_second_degree(var[0], var[1], var[2]);
	return (var[3]);
}

void	proc_cy_inter(t_hit *hit, t_cylinder *cy, t_vect v)
{
	float	v_n;
	t_vect	vn_cy;

	v_n = dot_product(v, cy->normal);
	if (v_n < 0 || v_n > cy->height)
		hit->distance = INFINITY;
	else
	{
		vn_cy = scale(cy->normal, v_n);
		hit->normal = normalize(sub_vect(v, vn_cy));
		hit->color = cy->color;
	}
}

void	base_inter(t_ray *ray, t_cylinder *cy, t_hit *hit)
{
	float	t_base;
	t_vect	p_base;
	float	dot_d_n;

	dot_d_n = dot_product(ray->direction, cy->normal);
	t_base = dot_product(cy->normal, sub_vect(cy->base, ray->origin)) / dot_d_n;
	if (t_base > 0)
	{
		p_base = add_vect(ray->origin, scale(ray->direction, t_base));
		if (magnitude(sub_vect(p_base, cy->base)) <= cy->radius)
		{
			if (t_base < hit->distance)
			{
				hit->distance = t_base;
				hit->point = p_base;
				hit->normal = scale(cy->normal, -1);
				hit->color = cy->color;
			}
		}
	}
}

void	top_inter(t_ray *ray, t_cylinder *cy, t_hit *hit)
{
	t_vect	top_base;
	float	t_top;
	t_vect	p_top;
	float	dot_d_n;

	dot_d_n = dot_product(ray->direction, cy->normal);
	top_base = add_vect(cy->base, scale(cy->normal, cy->height));
	t_top = dot_product(cy->normal, sub_vect(top_base, ray->origin)) / dot_d_n;
	if (t_top > 0)
	{
		p_top = add_vect(ray->origin, scale(ray->direction, t_top));
		if (magnitude(sub_vect(p_top, top_base)) <= cy->radius)
		{
			if (t_top < hit->distance)
			{
				hit->distance = t_top;
				hit->point = p_top;
				hit->normal = cy->normal;
				hit->color = cy->color;
			}
		}
	}
}

t_hit	*cylinder_intersect(t_ray *ray, t_cylinder *cy)
{
	float	t;
	t_hit	*hit;
	t_vect	v;

	hit = safe_calloc();
	t = solve_cy_equa(ray, cy);
	if (t < 0)
	{
		hit->distance = INFINITY;
		return (hit);
	}
	hit->fig = CYLINDER;
	hit->form.cy = *cy;
	hit->distance = t;
	hit->point = add_vect(ray->origin, scale(ray->direction, t));
	v = sub_vect(hit->point, cy->base);
	proc_cy_inter(hit, cy, v);
	base_inter(ray, cy, hit);
	top_inter(ray, cy, hit);
	return (hit);
}

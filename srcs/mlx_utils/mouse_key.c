/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:04:41 by candriam          #+#    #+#             */
/*   Updated: 2025/03/14 23:33:36 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	select_object(int keycode, t_minirt *minirt)
{
	quit_move_mode(keycode, minirt);
	if (keycode == K_L)
	{
		minirt->obj_selected = NULL;
		minirt->scene->light.is_active = 1;
	}
	else if (keycode == K_C)
	{
		minirt->obj_selected = NULL;
		minirt->scene->camera.is_active = 1;
	}
	handle_tools_one(keycode, minirt);
	handle_tools_two(keycode, minirt);
}

int	setup_key(int keycode, t_minirt *minirt)
{
	select_object(keycode, minirt);
	if (minirt->obj_selected != NULL)
	{
		if (minirt->obj_selected->fig == SPHERE)
		{
			handle_sphere_move(keycode, minirt);
			resizing_sphere(keycode, minirt);
		}
		else if (minirt->obj_selected->fig == PLANE)
		{
			handle_plane_move(keycode, minirt);
			handle_plane_rotation(keycode, minirt);
		}
		else if (minirt->obj_selected->fig == CYLINDER)
		{
			handle_cylinder_move(keycode, minirt);
			handle_cy_rotation(keycode, minirt);
			resizing_cylinder(keycode, minirt);
		}
	}
	handle_zoom(keycode, minirt);
	handle_light_move(keycode, minirt);
	handle_camera_move(keycode, minirt);
	handle_camera_rotation(keycode, minirt);
	return (0);
}

float	intersect_shape(t_vect ray_dir, t_vect ray_orig, t_shape *shape)
{
	float	t;
	float	var[2];

	if (shape->fig == SPHERE)
	{
		if (solve_quad(var, ray_dir, ray_orig, shape))
		{
			t = fmin(var[0], var[1]);
			if (t > 0)
				return (t);
		}
	}
	else if (shape->fig == PLANE)
	{
		if (solve_plane(&t, ray_dir, ray_orig, shape))
			return (t);
	}
	else if (shape->fig == CYLINDER)
	{
		if (solve_cylinder(&t, ray_dir, ray_orig, shape))
			return (t);
	}
	return (INFINITY);
}

t_shape	*clicked_object(t_vect ray_direction, t_minirt *minirt)
{
	t_shape	*shape;
	t_shape	*closest;
	t_vect	ray_origin;
	float	t;
	float	min_t;

	closest = NULL;
	min_t = INFINITY;
	shape = minirt->scene->shape;
	ray_origin = minirt->scene->camera.position;
	while (shape)
	{
		t = intersect_shape(ray_direction, ray_origin, shape);
		if (t < min_t)
		{
			min_t = t;
			closest = shape;
		}
		shape = shape->next;
	}
	return (closest);
}

int	mouse_hook(int button, int x, int y, t_minirt *minirt)
{
	t_shape	*click;
	t_vect	ray_dir;

	if (button == 1)
	{
		ray_dir = compute_ray_dir(minirt->scene->camera, x, y);
		click = clicked_object(ray_dir, minirt);
		if (click != NULL)
		{
			minirt->obj_selected = click;
			click->is_active = 1;
		}
	}
	return (0);
}

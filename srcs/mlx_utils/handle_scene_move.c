/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_scene_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:11:35 by tambinin          #+#    #+#             */
/*   Updated: 2025/03/14 22:15:45 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	handle_light_move(int keycode, t_minirt *minirt)
{
	if (minirt->scene->translation.light_is_active == 0 && keycode == K_L)
	{
		quit_move_mode(keycode, minirt);
		minirt->scene->translation.light_is_active = 1;
		minirt->obj_selected = NULL;
	}
	activate_elem_axis(keycode, minirt);
	moving_light(keycode, minirt);
	quit_move_mode(keycode, minirt);
}

void	handle_zoom(int keycode, t_minirt *minirt)
{
	if (keycode == UP)
	{
		minirt->scene->camera.fov -= 0.84;
		render_alias(minirt);
	}
	if (keycode == DOWN)
	{
		minirt->scene->camera.fov += 0.84;
		render_alias(minirt);
	}
}

void	handle_camera_move(int keycode, t_minirt *minirt)
{
	if (minirt->scene->translation.cam_is_active == 0 && keycode == K_C)
	{
		minirt->scene->translation.cam_is_active = 1;
		minirt->obj_selected = NULL;
	}
	if (minirt->scene->translation.cam_is_active && keycode == K_M)
	{
		minirt->scene->translation.is_active = 1;
		minirt->scene->rotation.is_active = 0;
		minirt->obj_selected = NULL;
	}
	if (minirt->scene->translation.cam_is_active
		&& minirt->scene->translation.is_active)
	{
		activate_elem_axis(keycode, minirt);
		moving_camera(keycode, minirt);
	}
	quit_move_mode(keycode, minirt);
}

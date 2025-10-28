/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rotate_scene.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:52:22 by tambinin          #+#    #+#             */
/*   Updated: 2025/03/14 22:53:12 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	handle_camera_rotation(int keycode, t_minirt *minirt)
{
	if (minirt->scene->rotation.cam_is_active == 0 && keycode == K_C)
	{
		minirt->scene->rotation.cam_is_active = 1;
		minirt->obj_selected = NULL;
	}
	if (minirt->scene->rotation.cam_is_active && keycode == K_S)
	{
		minirt->scene->rotation.is_active = 1;
		minirt->scene->translation.is_active = 0;
		minirt->obj_selected = NULL;
	}
	if (minirt->scene->rotation.cam_is_active
		&& minirt->scene->rotation.is_active)
	{
		activate_elem_rotation(keycode, minirt);
		rotating_camera(keycode, minirt);
	}
	quit_move_mode(keycode, minirt);
}

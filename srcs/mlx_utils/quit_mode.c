/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 23:27:02 by tambinin          #+#    #+#             */
/*   Updated: 2025/03/14 23:29:03 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	handle_tools_one(int keycode, t_minirt *minirt)
{
	if (keycode == ESC)
		close_window(minirt);
}

void	handle_tools_two(int keycode, t_minirt *minirt)
{
	if (keycode == K_N)
		render_minirt(minirt);
}

void	quit_move_mode(int keycode, t_minirt *minirt)
{
	if (keycode == K_Q)
	{
		if (minirt->obj_selected)
		{
			minirt->obj_selected->rotation.is_active = 0;
			minirt->obj_selected->translation.is_active = 0;
			minirt->obj_selected->translation.axis_on[0] = 0;
			minirt->obj_selected->translation.axis_on[1] = 0;
			minirt->obj_selected->translation.axis_on[2] = 0;
		}
		minirt->scene->rotation.is_active = 0;
		minirt->scene->translation.is_active = 0;
		minirt->scene->translation.axis_on[0] = 0;
		minirt->scene->translation.axis_on[1] = 0;
		minirt->scene->translation.axis_on[2] = 0;
		minirt->scene->translation.light_is_active = 0;
		minirt->scene->translation.cam_is_active = 0;
		minirt->scene->light.is_active = 0;
		minirt->scene->camera.is_active = 0;
	}
}

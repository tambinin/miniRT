/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 21:36:39 by tambinin          #+#    #+#             */
/*   Updated: 2025/03/14 21:49:36 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	handle_sphere_move(int keycode, t_minirt *minirt)
{
	if (minirt->obj_selected == NULL)
	{
		minirt->obj_selected->translation.is_active = 0;
		minirt->obj_selected->translation.axis_on[0] = 0;
		minirt->obj_selected->translation.axis_on[1] = 0;
		minirt->obj_selected->translation.axis_on[2] = 0;
		return ;
	}
	if (minirt->obj_selected->translation.is_active == 0 && keycode == K_T)
	{
		minirt->obj_selected->translation.is_active = 1;
		minirt->obj_selected->resize.is_active_r = 0;
		minirt->obj_selected->resize.is_active_h = 0;
		minirt->obj_selected->rotation.is_active = 0;
	}
	if (minirt->obj_selected->resize.is_active_r == 0 && keycode == K_D)
	{
		minirt->obj_selected->resize.is_active_r = 1;
		minirt->obj_selected->translation.is_active = 0;
	}
	activate_axis(keycode, minirt);
	moving_sphere(keycode, minirt);
	quit_move_mode(keycode, minirt);
}

void	handle_plane_move(int keycode, t_minirt *minirt)
{
	if (minirt->obj_selected == NULL)
	{
		minirt->obj_selected->translation.is_active = 0;
		minirt->obj_selected->translation.axis_on[0] = 0;
		minirt->obj_selected->translation.axis_on[1] = 0;
		minirt->obj_selected->translation.axis_on[2] = 0;
		return ;
	}
	if (minirt->obj_selected->translation.is_active == 0 && keycode == K_T)
	{
		minirt->obj_selected->translation.is_active = 1;
		minirt->obj_selected->resize.is_active_r = 0;
		minirt->obj_selected->resize.is_active_h = 0;
		minirt->obj_selected->rotation.is_active = 0;
	}
	activate_axis(keycode, minirt);
	moving_plane(keycode, minirt);
	quit_move_mode(keycode, minirt);
}

void	handle_cylinder_move(int keycode, t_minirt *minirt)
{
	if (minirt->obj_selected == NULL)
	{
		minirt->obj_selected->translation.is_active = 0;
		minirt->obj_selected->translation.axis_on[0] = 0;
		minirt->obj_selected->translation.axis_on[1] = 0;
		minirt->obj_selected->translation.axis_on[2] = 0;
		minirt->obj_selected->rotation.is_active = 0;
		return ;
	}
	if (minirt->obj_selected->translation.is_active == 0 && keycode == K_T)
	{
		minirt->obj_selected->translation.is_active = 1;
		minirt->obj_selected->resize.is_active_r = 0;
		minirt->obj_selected->resize.is_active_h = 0;
		minirt->obj_selected->rotation.is_active = 0;
	}
	process_resizing(keycode, minirt);
	activate_axis(keycode, minirt);
	moving_cylinder(keycode, minirt);
	quit_move_mode(keycode, minirt);
}

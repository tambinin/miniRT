/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rotate_obj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:01:54 by tambinin          #+#    #+#             */
/*   Updated: 2025/03/14 22:03:50 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	handle_plane_rotation(int keycode, t_minirt *minirt)
{
	if (minirt->obj_selected == NULL)
	{
		minirt->obj_selected->rotation.is_active = 0;
		minirt->obj_selected->rotation.axis_on[0] = 0;
		minirt->obj_selected->rotation.axis_on[1] = 0;
		minirt->obj_selected->rotation.axis_on[2] = 0;
		return ;
	}
	if (minirt->obj_selected->rotation.is_active == 0 && keycode == K_R)
	{
		minirt->obj_selected->rotation.is_active = 1;
		minirt->obj_selected->translation.is_active = 0;
		minirt->obj_selected->resize.is_active_r = 0;
		minirt->obj_selected->resize.is_active_h = 0;
	}
	activate_rotate_axis(keycode, minirt);
	rotating_plane(keycode, minirt);
	quit_move_mode(keycode, minirt);
}

void	handle_cy_rotation(int keycode, t_minirt *minirt)
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
	if (minirt->obj_selected->rotation.is_active == 0 && keycode == K_R)
	{
		minirt->obj_selected->rotation.is_active = 1;
		minirt->obj_selected->translation.is_active = 0;
		minirt->obj_selected->resize.is_active_r = 0;
		minirt->obj_selected->resize.is_active_h = 0;
	}
	activate_rotate_axis(keycode, minirt);
	rotating_cylinder(keycode, minirt);
	quit_move_mode(keycode, minirt);
}

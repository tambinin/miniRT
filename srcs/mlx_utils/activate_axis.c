/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activate_axis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 23:19:10 by tambinin          #+#    #+#             */
/*   Updated: 2025/03/14 23:22:21 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	activate_axis(int keycode, t_minirt *minirt)
{
	if (minirt->obj_selected->translation.axis_on[0] == 0 && keycode == K_X)
	{
		minirt->obj_selected->translation.axis_on[1] = 0;
		minirt->obj_selected->translation.axis_on[2] = 0;
		minirt->obj_selected->translation.axis_on[0] = 1;
	}
	if (minirt->obj_selected->translation.axis_on[1] == 0 && keycode == K_Y)
	{
		minirt->obj_selected->translation.axis_on[2] = 0;
		minirt->obj_selected->translation.axis_on[0] = 0;
		minirt->obj_selected->translation.axis_on[1] = 1;
	}
	if (minirt->obj_selected->translation.axis_on[2] == 0 && keycode == K_Z)
	{
		minirt->obj_selected->translation.axis_on[0] = 0;
		minirt->obj_selected->translation.axis_on[1] = 0;
		minirt->obj_selected->translation.axis_on[2] = 1;
	}
}

void	activate_rotate_axis(int keycode, t_minirt *minirt)
{
	if (minirt->obj_selected->rotation.axis_on[0] == 0 && keycode == K_X)
	{
		minirt->obj_selected->rotation.axis_on[0] = 1;
		minirt->obj_selected->rotation.axis_on[1] = 0;
		minirt->obj_selected->rotation.axis_on[2] = 0;
	}
	if (minirt->obj_selected->rotation.axis_on[1] == 0 && keycode == K_Y)
	{
		minirt->obj_selected->rotation.axis_on[0] = 0;
		minirt->obj_selected->rotation.axis_on[1] = 1;
		minirt->obj_selected->rotation.axis_on[2] = 0;
	}
	if (minirt->obj_selected->rotation.axis_on[2] == 0 && keycode == K_Z)
	{
		minirt->obj_selected->rotation.axis_on[0] = 0;
		minirt->obj_selected->rotation.axis_on[1] = 0;
		minirt->obj_selected->rotation.axis_on[2] = 1;
	}
}

void	activate_elem_axis(int keycode, t_minirt *minirt)
{
	if (minirt->scene->translation.axis_on[0] == 0 && keycode == K_X)
	{
		minirt->scene->translation.axis_on[0] = 1;
		minirt->scene->translation.axis_on[1] = 0;
		minirt->scene->translation.axis_on[2] = 0;
	}
	else if (minirt->scene->translation.axis_on[1] == 0 && keycode == K_Y)
	{
		minirt->scene->translation.axis_on[0] = 0;
		minirt->scene->translation.axis_on[1] = 1;
		minirt->scene->translation.axis_on[2] = 0;
	}
	else if (minirt->scene->translation.axis_on[2] == 0 && keycode == K_Z)
	{
		minirt->scene->translation.axis_on[0] = 0;
		minirt->scene->translation.axis_on[1] = 0;
		minirt->scene->translation.axis_on[2] = 1;
	}
}

void	activate_elem_rotation(int keycode, t_minirt *minirt)
{
	if (keycode == K_X)
	{
		minirt->scene->rotation.axis_on[0] = 1;
		minirt->scene->rotation.axis_on[1] = 0;
		minirt->scene->rotation.axis_on[2] = 0;
		minirt->scene->rotation.angle_y = 0;
		minirt->scene->rotation.angle_z = 0;
	}
	else if (keycode == K_Y)
	{
		minirt->scene->rotation.axis_on[0] = 0;
		minirt->scene->rotation.axis_on[1] = 1;
		minirt->scene->rotation.axis_on[2] = 0;
		minirt->scene->rotation.angle_x = 0;
		minirt->scene->rotation.angle_z = 0;
	}
	else if (keycode == K_Z)
	{
		minirt->scene->rotation.axis_on[0] = 0;
		minirt->scene->rotation.axis_on[1] = 0;
		minirt->scene->rotation.axis_on[2] = 1;
		minirt->scene->rotation.angle_x = 0;
		minirt->scene->rotation.angle_y = 0;
	}
}

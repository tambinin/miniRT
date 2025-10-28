/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 21:53:26 by tambinin          #+#    #+#             */
/*   Updated: 2025/03/14 21:59:35 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	moving_sphere(int keycode, t_minirt *minirt)
{
	float	*axis;

	if (minirt->obj_selected && minirt->obj_selected->translation.is_active)
	{
		if (keycode == K_MIN || keycode == K_SUM)
		{
			axis = NULL;
			if (minirt->obj_selected->translation.axis_on[0] == 1)
				axis = &minirt->obj_selected->form.sp.position.x;
			else if (minirt->obj_selected->translation.axis_on[1] == 1)
				axis = &minirt->obj_selected->form.sp.position.y;
			else if (minirt->obj_selected->translation.axis_on[2] == 1)
				axis = &minirt->obj_selected->form.sp.position.z;
			if (axis != NULL)
			{
				if (keycode == K_MIN)
					minirt->obj_selected->translation.direction = -1;
				else if (keycode == K_SUM)
					minirt->obj_selected->translation.direction = 1;
				*axis += 0.042 * minirt->obj_selected->translation.direction;
				render_alias(minirt);
			}
		}
	}
}

void	moving_plane(int keycode, t_minirt *minirt)
{
	float	*axis;

	if (minirt->obj_selected && minirt->obj_selected->translation.is_active)
	{
		if (keycode == K_MIN || keycode == K_SUM)
		{
			axis = NULL;
			if (minirt->obj_selected->translation.axis_on[0] == 1)
				axis = &minirt->obj_selected->form.pl.position.x;
			else if (minirt->obj_selected->translation.axis_on[1] == 1)
				axis = &minirt->obj_selected->form.pl.position.y;
			else if (minirt->obj_selected->translation.axis_on[2] == 1)
				axis = &minirt->obj_selected->form.pl.position.z;
			if (axis != NULL)
			{
				if (keycode == K_MIN)
					minirt->obj_selected->translation.direction = -1;
				else if (keycode == K_SUM)
					minirt->obj_selected->translation.direction = 1;
				*axis += 0.042 * minirt->obj_selected->translation.direction;
				render_alias(minirt);
			}
		}
	}
}

void	moving_cylinder(int keycode, t_minirt *minirt)
{
	float	*axis;

	if (minirt->obj_selected && minirt->obj_selected->translation.is_active)
	{
		if (keycode == K_MIN || keycode == K_SUM)
		{
			axis = NULL;
			if (minirt->obj_selected->translation.axis_on[0] == 1)
				axis = &minirt->obj_selected->form.cy.base.x;
			else if (minirt->obj_selected->translation.axis_on[1] == 1)
				axis = &minirt->obj_selected->form.cy.base.y;
			else if (minirt->obj_selected->translation.axis_on[2] == 1)
				axis = &minirt->obj_selected->form.cy.base.z;
			if (axis != NULL)
			{
				if (keycode == K_MIN)
					minirt->obj_selected->translation.direction = -1;
				else if (keycode == K_SUM)
					minirt->obj_selected->translation.direction = 1;
				*axis += 0.042 * minirt->obj_selected->translation.direction;
				render_alias(minirt);
			}
		}
	}
}

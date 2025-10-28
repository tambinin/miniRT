/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resizing_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:08:50 by tambinin          #+#    #+#             */
/*   Updated: 2025/03/14 22:09:50 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	resizing_sphere(int keycode, t_minirt *minirt)
{
	if (minirt->obj_selected && minirt->obj_selected->resize.is_active_r == 1)
	{
		if (keycode == K_SUM)
		{
			minirt->obj_selected->form.sp.radius += 0.042;
			render_alias(minirt);
		}
		if (keycode == K_MIN)
		{
			if (minirt->obj_selected->form.sp.radius > MIN_SIZE)
				minirt->obj_selected->form.sp.radius -= 0.042;
			render_alias(minirt);
		}
	}
}

void	process_resizing(int keycode, t_minirt *minirt)
{
	if (minirt->obj_selected->resize.is_active_r == 0 && keycode == K_D)
	{
		minirt->obj_selected->resize.is_active_r = 1;
		minirt->obj_selected->resize.is_active_h = 0;
		minirt->obj_selected->translation.is_active = 0;
		minirt->obj_selected->rotation.is_active = 0;
	}
	if (minirt->obj_selected->resize.is_active_h == 0 && keycode == K_H)
	{
		minirt->obj_selected->resize.is_active_h = 1;
		minirt->obj_selected->translation.is_active = 0;
		minirt->obj_selected->resize.is_active_r = 0;
		minirt->obj_selected->rotation.is_active = 0;
	}
}

static void	resizing_height(int keycode, t_minirt *minirt)
{
	if (minirt->obj_selected->resize.is_active_h == 1)
	{
		if (keycode == K_SUM)
		{
			minirt->obj_selected->form.cy.height += 0.042;
			render_alias(minirt);
		}
		else if (keycode == K_MIN)
		{
			if (minirt->obj_selected->form.cy.height > MIN_SIZE)
			{
				minirt->obj_selected->form.cy.height -= 0.042;
				render_alias(minirt);
			}
		}
	}
}

static void	resizing_diameter(int keycode, t_minirt *minirt)
{
	if (minirt->obj_selected->resize.is_active_r == 1)
	{
		if (keycode == K_SUM)
		{
			minirt->obj_selected->form.cy.radius += 0.042;
			render_alias(minirt);
		}
		else if (keycode == K_MIN)
		{
			if (minirt->obj_selected->form.cy.radius > MIN_SIZE)
			{
				minirt->obj_selected->form.cy.radius -= 0.042;
				render_alias(minirt);
			}
		}
	}
}

void	resizing_cylinder(int keycode, t_minirt *minirt)
{
	if (minirt->obj_selected && (minirt->obj_selected->resize.is_active_r
			|| minirt->obj_selected->resize.is_active_h))
	{
		resizing_diameter(keycode, minirt);
		resizing_height(keycode, minirt);
	}
}

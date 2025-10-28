/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:05:05 by tambinin          #+#    #+#             */
/*   Updated: 2025/03/14 22:06:21 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	init_angle(int keycode, float angle_step, t_minirt *minirt)
{
	int		new_direction;

	if (keycode == K_MIN)
		new_direction = -1;
	if (keycode == K_SUM)
		new_direction = 1;
	if (new_direction != minirt->obj_selected->rotation.direction)
	{
		minirt->obj_selected->rotation.direction = new_direction;
		minirt->obj_selected->rotation.angle_x = 0.0;
		minirt->obj_selected->rotation.angle_y = 0.0;
		minirt->obj_selected->rotation.angle_z = 0.0;
	}
	angle_step += minirt->obj_selected->rotation.direction;
	if (minirt->obj_selected->rotation.axis_on[0])
		minirt->obj_selected->rotation.angle_x = angle_step;
	if (minirt->obj_selected->rotation.axis_on[1])
		minirt->obj_selected->rotation.angle_y = angle_step;
	if (minirt->obj_selected->rotation.axis_on[2])
		minirt->obj_selected->rotation.angle_z = angle_step;
}

void	rotating_plane(int keycode, t_minirt *minirt)
{
	float	angle_step;

	if (minirt->obj_selected && minirt->obj_selected->rotation.is_active)
	{
		if (keycode == K_MIN || keycode == K_SUM)
		{
			angle_step = 0.0;
			init_angle(keycode, angle_step, minirt);
			minirt->obj_selected->form.pl.normal
				= rotate_x(minirt->obj_selected->form.pl.normal,
					minirt->obj_selected->rotation.angle_x);
			minirt->obj_selected->form.pl.normal
				= rotate_y(minirt->obj_selected->form.pl.normal,
					minirt->obj_selected->rotation.angle_y);
			minirt->obj_selected->form.pl.normal
				= rotate_z(minirt->obj_selected->form.pl.normal,
					minirt->obj_selected->rotation.angle_z);
			render_alias(minirt);
		}
	}
}

void	rotation_step(int key, float angle_step, float *angle, t_minirt *minirt)
{
	int		new_direction;

	if (key == K_MIN)
		new_direction = -1;
	if (key == K_SUM)
		new_direction = 1;
	if (new_direction != minirt->obj_selected->rotation.direction)
	{
		minirt->obj_selected->rotation.direction = new_direction;
		minirt->obj_selected->rotation.angle_x = 0.0;
		minirt->obj_selected->rotation.angle_y = 0.0;
		minirt->obj_selected->rotation.angle_z = 0.0;
	}
	angle_step = minirt->obj_selected->rotation.direction;
	if (minirt->obj_selected->rotation.axis_on[0])
		angle[0] = angle_step;
	if (minirt->obj_selected->rotation.axis_on[1])
		angle[1] = angle_step;
	if (minirt->obj_selected->rotation.axis_on[2])
		angle[2] = angle_step;
}

void	process_rot(t_vect center, float *angle, t_minirt *minirt)
{
	minirt->obj_selected->form.cy.base
		= rotate_around_center(minirt->obj_selected->form.cy.base,
			center, angle);
	minirt->obj_selected->form.cy.normal
		= rotate_x(minirt->obj_selected->form.cy.normal,
			angle[0]);
	minirt->obj_selected->form.cy.normal
		= rotate_y(minirt->obj_selected->form.cy.normal,
			angle[1]);
	minirt->obj_selected->form.cy.normal
		= rotate_z(minirt->obj_selected->form.cy.normal,
			angle[2]);
}

void	rotating_cylinder(int keycode, t_minirt *minirt)
{
	t_vect	center;
	float	angle[3];
	float	angle_step;
	int		i;

	i = 0;
	while (i < 3)
	{
		angle[i] = 0.0f;
		i++;
	}
	if (minirt->obj_selected && minirt->obj_selected->rotation.is_active)
	{
		if (keycode == K_MIN || keycode == K_SUM)
		{
			angle_step = 0.0;
			rotation_step(keycode, angle_step, angle, minirt);
			center = add_vect(minirt->obj_selected->form.cy.base,
					scale(minirt->obj_selected->form.cy.normal,
						minirt->obj_selected->form.cy.height / 2.0));
			process_rot(center, angle, minirt);
			render_alias(minirt);
		}
	}
}

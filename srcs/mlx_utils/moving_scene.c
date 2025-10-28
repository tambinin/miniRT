/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:16:39 by tambinin          #+#    #+#             */
/*   Updated: 2025/03/14 22:17:48 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	moving_light(int keycode, t_minirt *minirt)
{
	float	*axis;

	if (minirt->scene->translation.light_is_active)
	{
		if (keycode == K_MIN || keycode == K_SUM)
		{
			axis = NULL;
			if (minirt->scene->translation.axis_on[0] == 1)
				axis = &minirt->scene->light.position.x;
			else if (minirt->scene->translation.axis_on[1] == 1)
				axis = &minirt->scene->light.position.y;
			else if (minirt->scene->translation.axis_on[2] == 1)
				axis = &minirt->scene->light.position.z;
			if (axis != NULL)
			{
				if (keycode == K_MIN)
					minirt->scene->translation.direction = -1;
				else if (keycode == K_SUM)
					minirt->scene->translation.direction = 1;
				*axis += 0.042 * minirt->scene->translation.direction;
				render_alias(minirt);
			}
		}
	}
}

void	moving_camera(int keycode, t_minirt *minirt)
{
	float	*axis;

	if (minirt->scene->translation.cam_is_active)
	{
		if (keycode == K_MIN || keycode == K_SUM)
		{
			axis = NULL;
			if (minirt->scene->translation.axis_on[0] == 1)
				axis = &minirt->scene->camera.position.x;
			else if (minirt->scene->translation.axis_on[1] == 1)
				axis = &minirt->scene->camera.position.y;
			else if (minirt->scene->translation.axis_on[2] == 1)
				axis = &minirt->scene->camera.position.z;
			if (axis != NULL)
			{
				if (keycode == K_MIN)
					minirt->scene->translation.direction = -1;
				else if (keycode == K_SUM)
					minirt->scene->translation.direction = 1;
				*axis += 0.042 * minirt->scene->translation.direction;
				render_alias(minirt);
			}
		}
	}
}

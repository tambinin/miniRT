/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:53:58 by tambinin          #+#    #+#             */
/*   Updated: 2025/03/14 23:49:03 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_mat	rotation_mat_axis(float angle, t_vect axis)
{
	float	mat[MAX][MAX];
	float	rad;
	t_mat	result;

	axis = normalize(axis);
	rad = angle * M_PI / 180.0;
	ft_memset(mat, 0, sizeof(mat));
	mat[0][0] = ((1 - cos(rad)) * (axis.x * axis.x) + cos(rad));
	mat[0][1] = ((1 - cos(rad)) * (axis.x * axis.y) - sin(rad) * axis.z);
	mat[0][2] = ((1 - cos(rad)) * (axis.x * axis.z) + sin(rad) * axis.y);
	mat[1][0] = ((1 - cos(rad)) * (axis.x * axis.y) + sin(rad) * axis.z);
	mat[1][1] = ((1 - cos(rad)) * (axis.y * axis.y) + cos(rad));
	mat[1][2] = ((1 - cos(rad)) * (axis.y * axis.z) - sin(rad) * axis.x);
	mat[2][0] = ((1 - cos(rad)) * (axis.x * axis.z) - sin(rad) * axis.y);
	mat[2][1] = ((1 - cos(rad)) * (axis.y * axis.z) + sin(rad) * axis.x);
	mat[2][2] = ((1 - cos(rad)) * (axis.z * axis.z) + cos(rad));
	mat[3][3] = 1;
	result = create_mat(mat, MAX);
	return (result);
}

static void	get_rotate_angle(t_minirt *rt, float *angle_x, float *angle_y)
{
	*angle_x = 0;
	*angle_y = 0;
	if (rt->scene->rotation.axis_on[0])
		*angle_x = rt->scene->rotation.direction * 1;
	if (rt->scene->rotation.axis_on[1])
		*angle_y = rt->scene->rotation.direction * -1;
}

static t_mat	processing_rot(t_minirt *rt)
{
	float	angle_x;
	float	angle_y;
	t_mat	total_rot;

	get_rotate_angle(rt, &angle_x, &angle_y);
	total_rot = identity_mat();
	cam_init_axis(&rt->scene->camera);
	if (rt->scene->rotation.axis_on[1])
		apply_rot_y(&rt->scene->camera, angle_y);
	if (rt->scene->rotation.axis_on[0])
		apply_rot_x(&rt->scene->camera, angle_x);
	rt->scene->rotation.angle_x += angle_x;
	rt->scene->rotation.angle_y += angle_y;
	rt->scene->camera.orientation = rt->scene->camera.forward;
	return (total_rot);
}

void	rotating_camera(int keycode, t_minirt *minirt)
{
	int	new_dir;

	if (!minirt->scene->rotation.cam_is_active)
		return ;
	if (keycode == K_MIN)
		new_dir = -1;
	else if (keycode == K_SUM)
		new_dir = 1;
	else
		return ;
	if (new_dir != minirt->scene->rotation.direction)
		minirt->scene->rotation.direction = new_dir;
	processing_rot(minirt);
	render_alias(minirt);
}

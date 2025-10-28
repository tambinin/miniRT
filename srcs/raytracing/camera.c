/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:28:05 by candriam          #+#    #+#             */
/*   Updated: 2025/02/03 05:37:37 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	cam_init_axis(t_camera *cam)
{
	cam->forward = cam->orientation;
	cam->world_up = new_vect(0.0, 1.0, 0.0);
	cam->right = cross_product(cam->world_up, cam->forward);
	if (magnitude(cam->right) < EPSILON)
		cam->right = new_vect(1.0, 0.0, 0.0);
	cam->right = normalize(cam->right);
	cam->up = normalize(cross_product(cam->forward, cam->right));
}

void	apply_rot_y(t_camera *cam, float angle)
{
	t_mat	rot_y;

	if (fabs(angle) <= 0.001)
		return ;
	rot_y = rotation_mat_axis(angle, cam->up);
	cam->forward = normalize(mult_mat_vect(rot_y, cam->forward));
	cam->right = cross_product(cam->world_up, cam->forward);
	if (magnitude(cam->right) < EPSILON)
		cam->right = new_vect(1.0, 0.0, 0.0);
	cam->right = normalize(cam->right);
	cam->up = normalize(cross_product(cam->forward, cam->right));
}

void	apply_rot_x(t_camera *cam, float angle)
{
	t_mat	rot_x;

	if (fabs(angle) <= 0.001)
		return ;
	rot_x = rotation_mat_axis(angle, cam->right);
	cam->forward = normalize(mult_mat_vect(rot_x, cam->forward));
	cam->up = normalize(cross_product(cam->forward, cam->right));
}

t_mat	camera_view(t_vect forward, t_vect world_up)
{
	t_mat	res;
	t_vect	right;
	t_vect	up;

	forward = normalize(forward);
	right = cross_product(world_up, forward);
	if (magnitude(right) < EPSILON)
	{
		world_up = new_vect(1.0, 0.0, 0.0);
		right = normalize(cross_product(world_up, forward));
	}
	right = normalize(right);
	up = normalize(cross_product(forward, right));
	ft_memset(&res, 0, sizeof(t_mat));
	res.mat[0][0] = -right.x;
	res.mat[1][0] = -right.y;
	res.mat[2][0] = -right.z;
	res.mat[0][1] = up.x;
	res.mat[1][1] = up.y;
	res.mat[2][1] = up.z;
	res.mat[0][2] = -forward.x;
	res.mat[1][2] = -forward.y;
	res.mat[2][2] = -forward.z;
	res.mat[3][3] = 1.0f;
	return (res);
}

t_vect	compute_ray_dir(t_camera cam, int i, int j)
{
	float	aspect;
	float	coord[2];
	float	half_fov;
	t_vect	direction;
	t_mat	cam_mat;

	aspect = (float)WIN_WIDTH / (float)WIN_HEIGHT;
	coord[0] = (2.0f * (i + 0.5f) / WIN_WIDTH - 1.0f) * aspect;
	coord[1] = 1.0f - 2.0f * (j + 0.5f) / WIN_HEIGHT;
	half_fov = tanf((cam.fov * 0.5f) * M_PI / 180.0f);
	direction.x = coord[0] * half_fov;
	direction.y = coord[1] * half_fov;
	direction.z = -1.0f;
	direction = normalize(direction);
	cam_mat = camera_view(cam.orientation, new_vect(0.0, 1.0, 0.0));
	direction = mult_mat_vect(cam_mat, direction);
	direction = normalize(direction);
	return (direction);
}

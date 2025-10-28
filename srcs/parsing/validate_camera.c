/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:42:23 by candriam          #+#    #+#             */
/*   Updated: 2025/01/30 06:56:34 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int	valid_cam_pos(char **line, t_vect *position)
{
	char	**splited;

	if (!line[1] || !is_valid_pos(line[1]))
	{
		ft_putendl_fd("Error\nInvalid Camera position in line.", 2);
		return (0);
	}
	splited = ft_split(line[1], ',');
	if (!splited || !splited[0] || !splited[1] || !splited[2])
	{
		ft_putendl_fd("Error\nInvalid camera line format", 2);
		ft_free_array(&splited);
		return (0);
	}
	position->x = ft_atof(splited[0]);
	position->y = ft_atof(splited[1]);
	position->z = ft_atof(splited[2]);
	ft_free_array(&splited);
	return (1);
}

static int	valid_cam_orient(char **line, t_vect *orientation)
{
	char	**splited;

	if (!line[2] || !is_valid_pos(line[2]) || !is_norm_vector(line[2])
		|| !is_norm(line[2]))
	{
		ft_putendl_fd("Error\nInvalid Camera orientation", 2);
		return (0);
	}
	splited = ft_split(line[2], ',');
	if (!splited || !splited[0] || !splited[1] || !splited[2])
	{
		ft_putendl_fd("Error\nInvalid camera line format", 2);
		ft_free_array(&splited);
		return (0);
	}
	orientation->x = ft_atof(splited[0]);
	orientation->y = ft_atof(splited[1]);
	orientation->z = ft_atof(splited[2]);
	ft_free_array(&splited);
	return (1);
}

static int	valid_cam_fov(char **line, float *fov)
{
	if (!line[3] || !is_valid_float(line[3]) || ft_atof(line[3]) < 0
		|| ft_atof(line[3]) > 180)
	{
		ft_putendl_fd("Error\nInvalid FOV must in (0 - 180)", 2);
		return (0);
	}
	*fov = ft_atof(line[3]);
	return (1);
}

static int	is_cam_extra(char **line)
{
	if (line[4] != NULL)
	{
		ft_putendl_fd("Error\nExtra data detected for Camera", 2);
		return (1);
	}
	return (0);
}

int	is_valid_camera(t_minirt *minirt, char **line)
{
	t_camera	cameras;

	ft_bzero(&cameras, sizeof(t_camera));
	if (!valid_cam_pos(line, &cameras.position) || !valid_cam_orient(line,
			&cameras.orientation) || !valid_cam_fov(line, &cameras.fov)
		|| is_cam_extra(line))
		return (0);
	cameras.id = 'C';
	cameras.initial_pos = cameras.position;
	cameras.initial_orient = cameras.orientation;
	minirt->scene->camera = cameras;
	return (1);
}

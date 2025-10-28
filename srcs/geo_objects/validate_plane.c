/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:43:54 by candriam          #+#    #+#             */
/*   Updated: 2025/03/14 17:52:01 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int	assign_position(char **line, t_vect *position)
{
	char	**splited;

	if (line[1] == NULL || is_empty(line[1]))
	{
		ft_putendl_fd("Error\nMissing position for object", 2);
		return (0);
	}
	if (!is_valid_pos(line[1]))
	{
		ft_putendl_fd("Error\nInvalid position format (x, y, z)", 2);
		return (0);
	}
	splited = ft_split(line[1], ',');
	if (splited == NULL || ft_arr_len(splited) != 3)
	{
		ft_putendl_fd("Error\nInvalid position for object", 2);
		ft_free_array(&splited);
		return (0);
	}
	position->x = ft_atof(splited[0]);
	position->y = ft_atof(splited[1]);
	position->z = ft_atof(splited[2]);
	ft_free_array(&splited);
	return (1);
}

static int	assign_normal(char **line, t_vect *normal)
{
	char	**splited;

	if (!line[2] || !is_norm_vector(line[2]) || !is_norm(line[2]))
	{
		ft_putendl_fd("Error\nInvalid plane orientation", 2);
		return (0);
	}
	splited = ft_split(line[2], ',');
	if (splited == NULL || ft_arr_len(splited) != 3)
	{
		ft_putendl_fd("Error\nInvalid normal format", 2);
		ft_free_array(&splited);
		return (0);
	}
	normal->x = ft_atof(splited[0]);
	normal->y = ft_atof(splited[1]);
	normal->z = ft_atof(splited[2]);
	ft_free_array(&splited);
	return (1);
}

static int	assign_color(char **line, t_col *color)
{
	char	**splited;

	if (!is_valid_color(line[3]))
	{
		ft_putendl_fd("Error\nPlane color must be in [0 - 255]", 2);
		return (0);
	}
	splited = ft_split(line[3], ',');
	if (splited == NULL || ft_arr_len(splited) != 3)
	{
		ft_putendl_fd("Error\nInvalid color format", 2);
		ft_free_array(&splited);
		return (0);
	}
	color->red = ft_atof(splited[0]);
	color->green = ft_atof(splited[1]);
	color->blue = ft_atof(splited[2]);
	ft_free_array(&splited);
	return (1);
}

int	create_plane(t_plane *new_plane, t_minirt *minirt, char **line)
{
	ft_bzero(new_plane, sizeof(t_plane));
	if (extra_data_plane(line) || !assign_position(line, &new_plane->position)
		|| !assign_color(line, &new_plane->color)
		|| !assign_normal(line, &new_plane->normal))
	{
		minirt->err++;
		return (0);
	}
	new_plane->id = "pl";
	return (1);
}

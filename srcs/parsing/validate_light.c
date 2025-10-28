/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:42:52 by candriam          #+#    #+#             */
/*   Updated: 2025/01/08 16:50:52 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include <stddef.h>

static int	assign_position(char **line, t_vect *position)
{
	char	**splited;
	size_t	len;

	if (!line[1])
	{
		ft_putendl_fd("Error\nInvalid line format", 2);
		return (0);
	}
	len = ft_strlen(line[1]);
	splited = ft_split(line[1], ',');
	if ((len > 0 && line[1][len - 1] == ',') || (ft_arr_len(splited) != 3))
	{
		ft_putendl_fd("Error\nInvalid position format", 2);
		return (0);
	}
	if (!splited || !splited[0] || !splited[1] || !splited[2])
	{
		ft_putendl_fd("Error\nInvalid position format", 2);
		return (0);
	}
	position->x = ft_atof(splited[0]);
	position->y = ft_atof(splited[1]);
	position->z = ft_atof(splited[2]);
	ft_free_array(&splited);
	return (1);
}

static int	assign_color(char **line, t_col *color)
{
	char	**splited;

	if (!line[3])
	{
		ft_putendl_fd("Error\nInvalid line format", 2);
		return (0);
	}
	splited = ft_split(line[3], ',');
	if (!splited || !splited[0] || !splited[1] || !splited[2])
	{
		ft_putendl_fd("Error\nInvalid color format", 2);
		return (0);
	}
	color->red = ft_atof(splited[0]);
	color->green = ft_atof(splited[1]);
	color->blue = ft_atof(splited[2]);
	ft_free_array(&splited);
	return (1);
}

static int	valid_light_component(char **line)
{
	if (!is_valid_pos(line[1]))
	{
		ft_putendl_fd("Error\nInvalid Light position in line.", 2);
		return (0);
	}
	if (!is_valid_float(line[2]) || ft_atof(line[2]) < 0.0
		|| ft_atof(line[2]) > 1.0)
	{
		ft_putendl_fd("Error\nLight intensity must in (0.0 - 1.0)", 2);
		return (0);
	}
	if (!is_valid_color(line[3]))
	{
		ft_putendl_fd("Error\nLight color must in [0 - 255]", STDERR_FILENO);
		return (0);
	}
	return (1);
}

static int	extra_data(char **line)
{
	if (line[4] != NULL)
	{
		ft_putendl_fd("Error\nExtra data detected for Light", 2);
		return (1);
	}
	return (0);
}

int	is_valid_light(t_minirt *minirt, char **line)
{
	t_light	light;

	ft_bzero(&light, sizeof(t_light));
	if (!valid_light_component(line) || !assign_color(line, &light.color)
		|| !assign_position(line, &light.position) || extra_data(line))
		return (0);
	light.id = 'L';
	light.intensity = ft_atof(line[2]);
	light.position = add_vect(light.position, scale(light.position, EPSILON));
	minirt->scene->light = light;
	return (1);
}

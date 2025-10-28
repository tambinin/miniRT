/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_ambient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:43:23 by candriam          #+#    #+#             */
/*   Updated: 2025/01/08 16:51:53 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int	assign_color(char **line, t_col *color)
{
	char	**splited;

	if (!line[2])
	{
		ft_putendl_fd("Error\nInvalid color line format", 2);
		return (0);
	}
	splited = ft_split(line[2], ',');
	if (!splited || !splited[0] || !splited[1] || !splited[2])
	{
		ft_putendl_fd("Error\nInvalid color line format", 2);
		ft_free_array(&splited);
		return (0);
	}
	color->red = ft_atof(splited[0]);
	color->green = ft_atof(splited[1]);
	color->blue = ft_atof(splited[2]);
	ft_free_array(&splited);
	return (1);
}

static int	valid_ambient_comp(char **line)
{
	if (!is_valid_float(line[1]) || ft_atof(line[1]) < 0.0
		|| ft_atof(line[1]) > 1.0)
	{
		ft_putendl_fd("Error\nInvalid ambient ratio in line.", STDERR_FILENO);
		return (0);
	}
	if (!is_valid_color(line[2]))
	{
		ft_putendl_fd("Error\nColor must in [0 - 255]", STDERR_FILENO);
		return (0);
	}
	return (1);
}

static int	extra_data(char **line)
{
	if (line[3] != NULL)
	{
		ft_putendl_fd("Error\nExtra data detected for Ambient", 2);
		return (1);
	}
	return (0);
}

int	is_valid_ambient(char **line, t_minirt *minirt)
{
	t_ambient	ambient;

	ft_bzero(&ambient, sizeof(t_ambient));
	if (!minirt->scene)
		return (0);
	if (!line || !line[1] || !line[2])
		return (0);
	if (!assign_color(line, &ambient.color) || !valid_ambient_comp(line)
		|| extra_data(line))
		return (0);
	ambient.ratio = ft_atof(line[1]);
	ambient.id = 'A';
	minirt->scene->ambient = ambient;
	return (1);
}

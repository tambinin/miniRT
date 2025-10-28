/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:44:55 by candriam          #+#    #+#             */
/*   Updated: 2025/03/14 17:50:58 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int	assign_color(char **line, t_col *color)
{
	char	**splited;

	if (check_coma(line[5], ',') != 2)
	{
		ft_putendl_fd("Error\nInvalid color line format", 2);
		return (0);
	}
	if (line[5] == NULL || !is_valid_color(line[5]))
	{
		ft_putendl_fd("Error\nCylinder color must be in [0 - 255]", 2);
		return (0);
	}
	splited = ft_split(line[5], ',');
	if (!splited || !splited[0] || !splited[1] || !splited[2])
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

static int	assign_normal(char **line, t_vect *normal)
{
	char	**splited;

	if (check_coma(line[2], ',') != 2)
	{
		ft_putendl_fd("Error\nInvalid cylinder normal", 2);
		return (0);
	}
	if (!line[2] || !is_valid_pos(line[2]) || !is_norm_vector(line[2])
		|| !is_norm(line[2]))
	{
		ft_putendl_fd("Error\nInvalid cylinder normal", 2);
		return (0);
	}
	splited = ft_split(line[2], ',');
	if (!splited || !splited[0] || !splited[1] || !splited[2])
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

static int	assign_base(char **line, t_vect *base)
{
	char	**splited;

	if (check_coma(line[1], ',') != 2)
	{
		ft_putendl_fd("Error\nInvalid base position format", 2);
		return (0);
	}
	splited = ft_split(line[1], ',');
	if (!splited || !splited[0] || !splited[1] || !splited[2])
	{
		ft_putendl_fd("Error\nInvalid base position format", 2);
		ft_free_array(&splited);
		return (0);
	}
	base->x = ft_atof(splited[0]);
	base->y = ft_atof(splited[1]);
	base->z = ft_atof(splited[2]);
	ft_free_array(&splited);
	if (base->x < -1000 || base->x > 1000 || base->y < -1000 || base->y > 1000
		|| base->z < -1000 || base->z > 1000)
	{
		ft_putendl_fd("Error\nBase position out of bounds [-1000, 1000]", 2);
		return (0);
	}
	return (1);
}

static int	valid_radius(char **line, float *radius, float *height)
{
	if (line[3] == NULL || !is_valid_float(line[3]) || ft_atof(line[3]) <= 0)
	{
		ft_putendl_fd("Error\nInvalid cylinder radius (a > 0)", 2);
		return (0);
	}
	*radius = ft_atof(line[3]) / 2;
	if (line[4] == NULL || !is_valid_float(line[4]) || ft_atof(line[4]) <= 0)
	{
		ft_putendl_fd("Error\nInvalid cylinder height (a > 0)", 2);
		return (0);
	}
	*height = ft_atof(line[4]);
	return (1);
}

t_cylinder	create_cylinder(t_minirt *minirt, char **line)
{
	t_cylinder	new_cylinder;

	ft_bzero(&new_cylinder, sizeof(t_cylinder));
	new_cylinder.id = "cy";
	if (!assign_base(line, &new_cylinder.base) || !assign_normal(line,
			&new_cylinder.normal) || !assign_color(line, &new_cylinder.color)
		|| !valid_radius(line, &new_cylinder.radius, &new_cylinder.height))
	{
		minirt->err++;
	}
	return (new_cylinder);
}

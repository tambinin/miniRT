/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:44:20 by candriam          #+#    #+#             */
/*   Updated: 2025/02/02 22:30:33 by tambinin         ###   ########.fr       */
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
	if (check_coma(line[1], ',') != 2 || !is_valid_pos(line[1]))
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

static int	valid_radius(char **line, float *radius)
{
	if (line[2] == NULL || !is_valid_float(line[2]) || ft_atof(line[2]) <= 0)
	{
		ft_putendl_fd("Error\nInvalid sphere radius (a > 0)", 2);
		return (0);
	}
	*radius = ft_atof(line[2]) / 2;
	return (1);
}

static int	assign_color(char **line, t_col *color)
{
	char	**splited;

	if (check_coma(line[3], ',') != 2)
	{
		ft_putendl_fd("Error\nInvalid sphere color format", 2);
		return (0);
	}
	if (!line[3] || !is_valid_color(line[3]))
	{
		ft_putendl_fd("Error\nSphere color must be in [0 - 255]", 2);
		return (0);
	}
	splited = ft_split(line[3], ',');
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

t_sphere	create_sphere(t_minirt *minirt, char **line)
{
	t_sphere	new_sphere;

	ft_bzero(&new_sphere, sizeof(t_sphere));
	if (extra_data_sphere(line) || !assign_position(line, &new_sphere.position)
		|| !assign_color(line, &new_sphere.color) || !valid_radius(line,
			&new_sphere.radius))
	{
		minirt->err++;
	}
	new_sphere.id = "sp";
	return (new_sphere);
}

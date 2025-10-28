/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:47:38 by candriam          #+#    #+#             */
/*   Updated: 2025/03/14 17:45:32 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	valid_set(char *set, int is_float, float min_value, char *msg)
{
	if (set == NULL || (is_float && !is_valid_float(set))
		|| ft_atof(set) <= min_value)
	{
		ft_putendl_fd(msg, 2);
		return (0);
	}
	return (1);
}

int	valid_cylinder_comp(char **line)
{
	if (line[1] == NULL || is_empty(line[1]))
	{
		ft_putendl_fd("Error: Missing position for object", 2);
		return (0);
	}
	if (!is_valid_pos(line[1]))
	{
		ft_putendl_fd("Error: Invalid position format (x, y, z)", 2);
		return (0);
	}
	if (!is_valid_pos(line[2]) || !is_norm_vector(line[2]))
	{
		ft_putendl_fd("Error: Invalid cylinder orientation", 2);
		return (0);
	}
	if (!valid_set(line[3], 1, 0, "Error: Invalid radius for cylinder")
		|| !valid_set(line[4], 1, 0, "Error: Invalid height for cylinder"))
		return (0);
	if (line[5] == NULL || !is_valid_color(line[5]))
	{
		ft_putendl_fd("Error: Invalid color for cylinder [1 - 255]", 2);
		return (0);
	}
	return (1);
}

int	extra_data_cylinder(char **line)
{
	if (line[6])
	{
		ft_putendl_fd("Error: Extra data detected for cylinder", 2);
		return (1);
	}
	return (0);
}

int	extra_data_sphere(char **line)
{
	if (line[4] != NULL)
	{
		ft_putendl_fd("Error: Extra data detected for sphere", 2);
		return (1);
	}
	return (0);
}

int	extra_data_plane(char **line)
{
	if (line[4] != NULL)
	{
		ft_putendl_fd("Error: Extra data detected for plane", 2);
		return (1);
	}
	return (0);
}

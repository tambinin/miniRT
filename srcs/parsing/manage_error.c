/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:02:51 by candriam          #+#    #+#             */
/*   Updated: 2025/01/08 10:16:31 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	validate_scene(t_minirt *minirt)
{
	if (minirt->nbr_ambient == 0)
	{
		ft_putendl_fd("Error\nScene must have exactly one 'A' (Ambient) ", 2);
		return (0);
	}
	if (minirt->nbr_camera == 0)
	{
		ft_putendl_fd("Error\nScene must have exactly one 'C' (Camera) ", 2);
		return (0);
	}
	if (minirt->nbr_light == 0)
	{
		ft_putendl_fd("Error\nScene must have exactly one 'L' (Light) ", 2);
		return (0);
	}
	return (1);
}

int	valid_compo(char id, char expect, int *nbr_total, const char *name)
{
	if (id == expect)
	{
		(*nbr_total)++;
		if (*nbr_total > 1)
		{
			ft_printf("Error\nDuplicate component (%s) detected.\n", name);
			return (DUP);
		}
		return (1);
	}
	return (ERR);
}

int	process_object(t_minirt *rt, char *id)
{
	if (ft_strncmp(id, "pl", 2) == 0)
	{
		rt->nbr_planes++;
		return (rt->nbr_planes);
	}
	else if (ft_strncmp(id, "sp", 2) == 0)
	{
		rt->nbr_spheres++;
		return (rt->nbr_spheres);
	}
	else if (ft_strncmp(id, "cy", 2) == 0)
	{
		rt->nbr_cylinders++;
		return (rt->nbr_cylinders);
	}
	else
	{
		ft_printf("Error\nUnknown object type '%s'\n", id);
		return (ERR);
	}
}

int	is_valid_scene(t_minirt *minirt)
{
	t_type	id;
	int		result;

	id = is_type(minirt);
	if (id == CMT)
		return (CMT);
	if (id < 0 || id >= MAX_ID)
		return (NOT_ID);
	if (id == A || id == C || id == L)
	{
		if (id == A)
			result = valid_compo(id, A, &minirt->nbr_ambient, "Ambient");
		else if (id == C)
			result = valid_compo(id, C, &minirt->nbr_camera, "Camera");
		else
			result = valid_compo(id, L, &minirt->nbr_light, "Light");
		if (result == DUP)
			return (0);
		return (result);
	}
	result = process_object(minirt, minirt->array[0]);
	if (result != ERR)
		return (result);
	ft_printf("Error\nUnknown object or component '%s'\n", minirt->scene[0]);
	return (ERR);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:15:27 by candriam          #+#    #+#             */
/*   Updated: 2025/01/08 10:16:16 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	is_valid_extension(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	return (len <= 3 || ft_strcmp(filename + len - 3, ".rt") == 0);
}

int	is_duplicate(int total, char *msg)
{
	if (total > 1)
	{
		ft_putendl_fd(msg, 2);
		return (1);
	}
	return (0);
}

int	is_mand_id(char *args, char id)
{
	if (args == NULL)
		return (0);
	if (*args != id)
		return (0);
	args++;
	return (1);
}

int	is_id(char *args, char *id)
{
	if (is_mand_id(args, id[0]))
	{
		args++;
		if (is_mand_id(args, id[1]))
			return (1);
		args--;
		return (0);
	}
	return (0);
}

t_type	is_type(t_minirt *minirt)
{
	if (is_mand_id(minirt->array[0], 'A') && ft_strlen(minirt->array[0]) == 1)
		return (A);
	if (is_mand_id(minirt->array[0], 'C') && ft_strlen(minirt->array[0]) == 1)
		return (C);
	if (is_mand_id(minirt->array[0], 'L') && ft_strlen(minirt->array[0]) == 1)
		return (L);
	if (is_id(minirt->array[0], "pl") && ft_strlen(minirt->array[0]) == 2)
		return (PL);
	if (is_id(minirt->array[0], "sp") && ft_strlen(minirt->array[0]) == 2)
		return (SP);
	if (is_id(minirt->array[0], "cy") && ft_strlen(minirt->array[0]) == 2)
		return (CY);
	if (is_mand_id(minirt->array[0], '#'))
		return (CMT);
	return (ERR);
}

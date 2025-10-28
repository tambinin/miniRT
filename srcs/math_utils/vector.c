/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:29:03 by candriam          #+#    #+#             */
/*   Updated: 2025/01/24 10:06:50 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vect	add_vect(t_vect a, t_vect b)
{
	t_vect	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	return (result);
}

t_vect	sub_vect(t_vect a, t_vect b)
{
	t_vect	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	return (result);
}

t_vect	scale(t_vect a, float nbr)
{
	t_vect	result;

	result.x = a.x * nbr;
	result.y = a.y * nbr;
	result.z = a.z * nbr;
	return (result);
}

t_vect	div_vect(t_vect a, float nbr)
{
	t_vect	result;

	if (nbr == 0)
	{
		result.x = 0;
		result.y = 0;
		result.z = 0;
	}
	else
	{
		result.x = a.x / nbr;
		result.y = a.y / nbr;
		result.z = a.z / nbr;
	}
	return (result);
}

t_vect	to_neg_vect(t_vect a)
{
	t_vect	result;

	result.x = a.x * -1;
	result.y = a.y * -1;
	result.z = a.z * -1;
	return (result);
}

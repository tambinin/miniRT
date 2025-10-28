/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:29:59 by candriam          #+#    #+#             */
/*   Updated: 2025/03/14 18:20:06 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float	clamp_color(float color, float min, float max)
{
	if ((color) < min)
		return (min);
	if ((color) > max)
		return (max);
	return (color);
}

t_col	convert_color(t_col color, float div)
{
	color.red = color.red / div;
	color.green = color.green / div;
	color.blue = color.blue / div;
	return (color);
}

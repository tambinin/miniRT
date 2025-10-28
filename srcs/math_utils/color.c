/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:30:28 by candriam          #+#    #+#             */
/*   Updated: 2025/01/26 18:18:25 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_col	new_color(float r, float g, float b)
{
	t_col	color;

	color.red = clamp_color(r, 0.0, 1.0);
	color.green = clamp_color(g, 0.0, 1.0);
	color.blue = clamp_color(b, 0.0, 1.0);
	return (color);
}

t_col	add_color(t_col a, t_col b)
{
	t_col	res;

	res.red = fmin(a.red + b.red, 255.0);
	res.green = fmin(a.green + b.green, 255.0);
	res.blue = fmin(a.blue + b.blue, 255.0);
	return (res);
}

t_col	sub_color(t_col a, t_col b)
{
	t_col	res;

	res.red = a.red - b.red;
	res.green = a.green - b.green;
	res.blue = a.blue - b.blue;
	return (res);
}

t_col	scale_color(float k, t_col a)
{
	t_col	res;

	res.red = a.red * k;
	res.green = a.green * k;
	res.blue = a.blue * k;
	return (res);
}

t_col	color_product(t_col a, t_col b)
{
	t_col	res;

	res.red = (a.red * b.red);
	res.green = (a.green * b.green);
	res.blue = (a.blue * b.blue);
	return (res);
}

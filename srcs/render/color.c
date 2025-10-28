/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:09:33 by candriam          #+#    #+#             */
/*   Updated: 2025/03/11 15:30:01 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_col	put_color(t_hit *hit)
{
	t_col	bg;

	bg = new_color(0.0, 0.0, 0.0);
	if (hit->fig == SPHERE)
		hit->color = hit->form.sp.color;
	else if (hit->fig == PLANE)
		hit->color = hit->form.pl.color;
	else if (hit->fig == CYLINDER)
		hit->color = hit->form.cy.color;
	else
		hit->color = bg;
	return (hit->color);
}

int	col_to_int(t_col color)
{
	int	red;
	int	green;
	int	blue;

	red = color.red + 0.5;
	green = color.green + 0.5;
	blue = color.blue + 0.5;
	return (red << 16 | green << 8 | blue);
}

void	write_color(int x, int y, t_col color, t_minirt rt)
{
	char	*pixel;
	int		rgb;

	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return ;
	pixel = rt.set->img_data + (y * rt.set->line_len) + (x * (rt.set->bpp / 8));
	rgb = col_to_int(color);
	*(unsigned int *)pixel = rgb;
}

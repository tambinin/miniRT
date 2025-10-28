/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:26:17 by candriam          #+#    #+#             */
/*   Updated: 2025/01/24 10:08:45 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	init_image(t_minirt *rt, t_set *set)
{
	rt->set->image = mlx_new_image(set->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!rt->set->image)
	{
		mlx_destroy_window(set->mlx, set->win);
		mlx_destroy_display(set->mlx);
		free(rt->set->mlx);
		return (false);
	}
	rt->set->img_data = mlx_get_data_addr(set->image, &set->bpp, &set->line_len,
			&set->endian);
	if (!rt->set->img_data)
	{
		mlx_destroy_image(set->mlx, set->image);
		mlx_destroy_window(set->mlx, set->win);
		return (false);
	}
	return (true);
}

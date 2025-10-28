/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:12:18 by candriam          #+#    #+#             */
/*   Updated: 2025/02/10 08:30:28 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	init_mlx(t_minirt *rt)
{
	t_set	*set;

	set = malloc(sizeof(t_set));
	rt->set = set;
	rt->set->mlx = mlx_init();
	if (!rt->set->mlx)
	{
		if (!rt)
			return (1);
		if (rt->set)
			clean_win_display(rt->set);
		free(rt->set);
		rt->set = NULL;
	}
	rt->set->win = mlx_new_window(set->mlx, WIN_WIDTH, WIN_HEIGHT, TITLE);
	if (!rt->set->win)
	{
		clean_minirt(rt);
		return (1);
	}
	if (!init_image(rt, set))
		return (1);
	return (0);
}

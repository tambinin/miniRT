/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:01:30 by candriam          #+#    #+#             */
/*   Updated: 2025/03/14 15:58:44 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	clean_win_display(t_set *set)
{
	if (set->image)
	{
		printf("Destroying image...\n");
		mlx_destroy_image(set->mlx, set->image);
		set->image = NULL;
	}
	if (set->win)
	{
		mlx_destroy_window(set->mlx, set->win);
		set->win = NULL;
	}
	if (set->mlx)
	{
		mlx_destroy_display(set->mlx);
		free(set->mlx);
		set->mlx = NULL;
	}
}

void	free_scene(t_scene *sc)
{
	t_shape	*obj;

	while (sc->shape)
	{
		obj = sc->shape->next;
		free(sc->shape);
		sc->shape = obj;
	}
	free(sc);
	sc = NULL;
}

void	clean_minirt_struct(t_minirt *minirt)
{
	if (!minirt)
		return ;
	if (minirt->set)
		clean_win_display(minirt->set);
	free(minirt->set);
	minirt->set = NULL;
	if (minirt->scene)
		free_scene(minirt->scene);
}

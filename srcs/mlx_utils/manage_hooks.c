/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:15:22 by candriam          #+#    #+#             */
/*   Updated: 2025/02/10 09:28:15 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	setup_hooks(t_minirt *minirt)
{
	mlx_key_hook(minirt->set->win, setup_key, minirt);
	mlx_mouse_hook(minirt->set->win, mouse_hook, minirt);
	mlx_hook(minirt->set->win, 17, 0, close_window, minirt);
}

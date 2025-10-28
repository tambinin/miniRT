/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 09:39:32 by candriam          #+#    #+#             */
/*   Updated: 2025/03/16 15:16:34 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	main(int argc, char **argv)
{
	t_minirt	minirt;

	ft_bzero(&minirt, sizeof(t_minirt));
	minirt.array = NULL;
	if (main_check(&minirt, argc, argv[1]) != EXIT_SUCCESS)
	{
		clean_minirt(&minirt);
		return (EXIT_FAILURE);
	}
	if (init_mlx(&minirt) != EXIT_SUCCESS)
	{
		free(minirt.scene);
		return (EXIT_FAILURE);
	}
	setup_hooks(&minirt);
	render_minirt(&minirt);
	key_use();
	mlx_loop(minirt.set->mlx);
	return (EXIT_SUCCESS);
}

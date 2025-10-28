/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 09:39:45 by candriam          #+#    #+#             */
/*   Updated: 2025/03/16 15:27:27 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	main_check(t_minirt *minirt, int argc, char *filename)
{
	if (argc != 2)
	{
		puterror("Usage: ./miniRT <file_scene.rt>");
		return (EXIT_FAILURE);
	}
	minirt->scene = malloc(sizeof(t_scene));
	if (!minirt->scene)
	{
		ft_putendl_fd("allocation failed\n", 2);
		return (EXIT_FAILURE);
	}
	ft_memset(minirt->scene, 0, sizeof(t_scene));
	if (!file_exist(filename) || !valid_line(minirt, filename))
	{
		free(minirt->scene->shape);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	key_use(void)
{
	instruction_one();
	instruction_two();
}

void	instruction_one(void)
{
	ft_printf("\t\t\t\t----------|man miniRT|----------\n");
	ft_printf("\nImportant: \n");
	ft_printf("\tObject : all form or shape could be pointed by the cursor \n\t\
Element: camera and light\n\tOn move the scene will be pixelized, but D0N'T P4NIC!\
just use 'N' key to reset view\n");
	ft_printf("\n\tFor object only, before using 'Translation' \
or 'Rotation' mode, select one object with mouse left click.\n\
\tFor element only, before using 'Translation' or 'Rotation' mode, \
choose one element to select in the scene.\n");
	ft_printf("\n\t\t** To select 'element' in the scene **\n");
	ft_printf("Key use: \n");
	ft_printf("\t'C' : to select Camera element.\n");
	ft_printf("\t'L' : to select Light element.\n");
	ft_printf("\n\tYou must quit with 'Q' key on the keyboard \
before changing move mode or object or element.\n");
	ft_printf("\n\t\t** Move mode for 'object' in the scene **\n");
	ft_printf("Key use: \n");
	ft_printf("\t'T' : to activate Translation mode \
for any object in the scene.\n");
	ft_printf("\t'R' : to activate Rotation mode \
for any object in the scene.\n");
}

void	instruction_two(void)
{
	ft_printf("\n\t\t** Activate or changing axis \
(available for all move mode) **\n");
	ft_printf("Key use: \n");
	ft_printf("\t'X' : to activate X axis.\n");
	ft_printf("\t'Y' : to activate Y axis.\n");
	ft_printf("\t'Z' : to activate Z axis.\n");
	ft_printf("\n\t\t** Moving on selected axis \
(available for all move mode) **\n");
	ft_printf("Key use: \n");
	ft_printf("\t'-' : to start moving on the negative direction.\n");
	ft_printf("\t'+' : to start moving on the positive direction.\n");
	ft_printf("\n\t\t** Move mode for 'element' in the scene **\n");
	ft_printf("Key use: \n");
	ft_printf("\t'M' : to activate Translation mode \
for 'Camera'.\n");
	ft_printf("\t'S' : to activate Rotation mode \
for 'Camera'.\n");
	ft_printf("\n\t\t** Applying zoom **\n");
	ft_printf("Key use: \n");
	ft_printf("\t'↑' : to start zooming in.\n");
	ft_printf("\t'↓' : to start zooming out.\n\n");
	ft_printf("\t\t\t\t----------|man miniRT|----------\n");
}

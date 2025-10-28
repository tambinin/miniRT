/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:50:39 by candriam          #+#    #+#             */
/*   Updated: 2025/03/14 16:02:37 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	clear_buffer(int fd)
{
	char	*line;

	line = "";
	close(fd);
	while (line)
	{
		line = get_next_line(fd);
		free(line);
	}
	return (false);
}

void	clean_resources(t_minirt *minirt)
{
	if (!minirt)
		return ;
	if (minirt->line)
		free(minirt->line);
	clean_minirt_struct(minirt);
}

void	clean_minirt(t_minirt *minirt)
{
	if (minirt->scene)
		free(minirt->scene);
	if (minirt->line)
		free(minirt->line);
	if (minirt->array != NULL)
		ft_free_array(&minirt->array);
}

void	free_hit(t_hit *hit)
{
	if (hit)
		free(hit);
	hit = NULL;
}

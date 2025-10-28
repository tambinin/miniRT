/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 09:42:45 by candriam          #+#    #+#             */
/*   Updated: 2025/01/30 06:34:02 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../includes/minirt.h"

int	check_scene(t_minirt *minirt, t_type *id, int *i)
{
	if (!is_valid_element(minirt, minirt->array, id)
		|| ((*id == PL || *id == SP || *id == CY)
			&& (!is_valid_object(minirt, minirt->array, *id, *i))))
	{
		free_objects(minirt);
		return (0);
	}
	return (1);
}

int	validate_line_format(t_minirt *minirt)
{
	int		i;
	t_type	id;

	i = 0;
	if (!minirt || !minirt->array || !minirt->array[0])
		return (0);
	id = is_type(minirt);
	if (!minirt->array[0] || is_empty(minirt->array[0]))
		return (1);
	if (id == CMT)
		return (1);
	if (id == ERR)
	{
		ft_printf("Error\nInvalid id detected ('%s')\n", minirt->array[0]);
		return (0);
	}
	if (minirt->array[1] == NULL || is_empty(minirt->array[1]))
	{
		ft_printf("Error\nMissing information for '%s'\n", minirt->array[0]);
		return (0);
	}
	if (!check_scene(minirt, &id, &i))
		return (0);
	return (1);
}

int	process_line(t_minirt *minirt)
{
	minirt->trimmed = ft_strtrim(minirt->line, "\n");
	if (!minirt->trimmed || !*(minirt->trimmed))
	{
		free_ret(minirt->trimmed);
		return (0);
	}
	minirt->array = split_line(minirt->trimmed);
	free_ret(minirt->trimmed);
	if (!minirt->array)
		return (0);
	if (!validate_line_format(minirt) || check_comment(minirt->array)
		|| is_valid_scene(minirt) == ERR)
	{
		ft_free_array(&minirt->array);
		free_scenes(minirt->scene);
		free_objects(minirt);
		return (0);
	}
	ft_free_array(&minirt->array);
	return (1);
}

int	valid_line_loop(t_minirt *minirt, int fd)
{
	char	*parsed_line;

	minirt->line = get_next_line(fd);
	while (minirt->line)
	{
		parsed_line = parse_comment(minirt->line);
		free(minirt->line);
		minirt->line = parsed_line;
		if (!minirt->line || is_empty(minirt->line))
		{
			free(minirt->line);
			minirt->line = get_next_line(fd);
			continue ;
		}
		if (!process_line(minirt))
		{
			minirt->err++;
			return (0);
		}
		free(minirt->line);
		minirt->line = get_next_line(fd);
	}
	if (minirt->err > 0)
		return (0);
	return (1);
}

int	valid_line(t_minirt *minirt, const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\ncan't open file or %s does not exist\n", filename);
		return (0);
	}
	if (valid_line_loop(minirt, fd) == 0)
	{
		clear_buffer(fd);
		close(fd);
		return (0);
	}
	close(fd);
	return (validate_scene(minirt));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 08:01:05 by candriam          #+#    #+#             */
/*   Updated: 2025/01/08 09:49:41 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	substitute_to_spaces(char *str, char delimeter)
{
	while (*str)
	{
		if (*str == '\t' || *str == delimeter)
			*str = ' ';
		str++;
	}
}

char	**split_line(char *input)
{
	char	**args;

	if (!input)
		return (NULL);
	substitute_to_spaces(input, '\n');
	args = ft_split(input, ' ');
	return (args);
}

char	*parse_comment(char *line)
{
	char	*clean_line;
	char	*start;
	char	*trimmed;
	size_t	len;

	if (!line)
		return (NULL);
	start = ft_strchr(line, '#');
	if (start)
		len = start - line;
	else
		len = ft_strlen(line);
	clean_line = ft_strndup(line, len);
	if (!clean_line)
		return (NULL);
	clean_line[len] = '\0';
	trimmed = ft_strtrim(clean_line, " ");
	free(clean_line);
	return (trimmed);
}

int	is_valid_element(t_minirt *minirt, char **scene, t_type *id)
{
	if ((*id == A) && !is_valid_ambient(scene, minirt))
		return (0);
	else if ((*id == L) && !is_valid_light(minirt, scene))
		return (0);
	else if ((*id == C) && !is_valid_camera(minirt, scene))
		return (0);
	return (1);
}

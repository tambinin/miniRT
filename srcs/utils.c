/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 09:39:51 by candriam          #+#    #+#             */
/*   Updated: 2025/01/08 09:52:36 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	file_exist(const char *filename)
{
	int	fd;

	if (!is_valid_extension(filename))
	{
		puterror("Error: Invalid file extension.");
		return (0);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		puterror("Error: File not found.");
		return (0);
	}
	close(fd);
	return (1);
}

int	check_comment(char **scene)
{
	int	i;
	int	j;

	i = 0;
	while (scene[i] != NULL)
	{
		if (is_empty(scene[i]) || scene[i][0] == '#')
		{
			i++;
			continue ;
		}
		j = i + 1;
		while (scene[j] != NULL)
		{
			if (is_empty(scene[j]) || scene[j][0] == '#')
			{
				j++;
				continue ;
			}
			j++;
		}
		i++;
	}
	return (0);
}

bool	is_empty(const char *str)
{
	while (*str)
	{
		if (!ft_isspace(*str))
			return (false);
		str++;
	}
	return (true);
}

int	ft_arr_len(char **arr)
{
	int	len;

	len = 0;
	while (*arr)
	{
		len++;
		arr++;
	}
	return (len);
}

t_hit	*safe_calloc(void)
{
	t_hit	*new;

	new = ft_calloc(sizeof(t_hit), 1);
	if (!new)
	{
		ft_putendl_fd("allocation failed", 2);
		return (NULL);
	}
	return (new);
}

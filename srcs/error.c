/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:51:38 by candriam          #+#    #+#             */
/*   Updated: 2025/01/08 09:52:30 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	puterror(char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	return (1);
}

size_t	check_coma(char const *s, char c)
{
	size_t	i;
	size_t	nb_strs;

	i = 0;
	nb_strs = 0;
	if (!s[0])
		return (0);
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] && s[i] == c)
			{
				i++;
				nb_strs++;
			}
		}
		else
			i++;
	}
	return (nb_strs);
}

void	exit_error(t_minirt *rt)
{
	clean_minirt(rt);
	clean_resources(rt);
	free(rt);
	exit(EXIT_FAILURE);
}

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		ft_putendl_fd("Error: memory allocation failed", STDERR_FILENO);
		return (NULL);
	}
	return (ptr);
}

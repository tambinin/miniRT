/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arrays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:25:17 by candriam          #+#    #+#             */
/*   Updated: 2025/01/08 09:28:06 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	ft_free_array(char ***argv)
{
	int	pos;

	if (!argv || !*argv)
		return ;
	pos = 0;
	while ((*argv)[pos])
	{
		free((*argv)[pos]);
		(*argv)[pos] = NULL;
		pos++;
	}
	free(*argv);
	*argv = NULL;
}

void	free_double_pointer(void **str)
{
	void	**stash;

	if (str)
	{
		stash = str;
		while (*stash)
		{
			free(*stash);
			*stash = NULL;
			stash++;
		}
		free(str);
	}
}

int	free_ret(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	return (0);
}

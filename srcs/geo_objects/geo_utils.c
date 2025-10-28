/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:46:33 by candriam          #+#    #+#             */
/*   Updated: 2025/03/14 17:42:58 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	is_norm_vector(char *str)
{
	char	**xyz;
	float	v[3];

	xyz = ft_split(str, ',');
	v[0] = ft_atof(xyz[0]);
	v[1] = ft_atof(xyz[1]);
	v[2] = ft_atof(xyz[2]);
	ft_free_array(&xyz);
	return ((v[0] * v[0] + v[1] * v[1] + v[2] * v[2]) <= 1.0f);
}

void	append_object(t_shape **lst, t_shape *new)
{
	t_shape	*temp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

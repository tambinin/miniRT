/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:28:09 by candriam          #+#    #+#             */
/*   Updated: 2025/02/10 09:03:18 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	free_objects(t_minirt *rt)
{
	t_shape	*obj;

	rt = NULL;
	if (!rt || !rt->scene || !rt->scene->shape)
		return ;
	while (rt->scene->shape)
	{
		obj = rt->scene->shape->next;
		free(rt->scene->shape);
		rt->scene->shape = obj;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:45:30 by candriam          #+#    #+#             */
/*   Updated: 2025/01/08 09:45:55 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../../includes/minirt.h"

void	free_scenes(t_scene *sc)
{
	t_shape	*obj;

	while (sc->shape)
	{
		obj = sc->shape->next;
		free(sc->shape);
		sc->shape = obj;
	}
	sc = NULL;
}

int	manage_error(t_minirt *minirt, t_shape *obj, int *on_success)
{
	if (!on_success || minirt->err > 0)
	{
		free(obj);
		free_scenes(minirt->scene);
		return (0);
	}
	return (1);
}

int	is_valid_object(t_minirt *minirt, char **line, t_type id, int pos)
{
	t_shape	*obj;

	minirt->on_success = 1;
	obj = ft_calloc(sizeof(t_shape), 1);
	if (id == SP)
	{
		obj->fig = SPHERE;
		obj->form.sp = create_sphere(minirt, line);
	}
	else if (id == PL)
	{
		obj->fig = PLANE;
		minirt->on_success = create_plane(&obj->form.pl, minirt, line);
	}
	else if (id == CY)
	{
		obj->fig = CYLINDER;
		obj->form.cy = create_cylinder(minirt, line);
	}
	if (!manage_error(minirt, obj, &minirt->on_success))
		return (0);
	obj->pos = pos;
	obj->next = NULL;
	append_object(&minirt->scene->shape, obj);
	return (pos + 1);
}

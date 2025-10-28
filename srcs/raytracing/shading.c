/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:27:06 by candriam          #+#    #+#             */
/*   Updated: 2024/12/29 12:27:20 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_col	shadow(t_col color, float intensity)
{
	t_col	shadow_color;

	shadow_color.red = color.red * (1 - intensity);
	shadow_color.green = color.green * (1 - intensity);
	shadow_color.blue = color.blue * (1 - intensity);
	return (shadow_color);
}

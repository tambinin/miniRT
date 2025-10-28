/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:27:38 by candriam          #+#    #+#             */
/*   Updated: 2025/02/10 09:23:14 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_col	clamping_color(t_col color)
{
	color.red = fmin(color.red, 255.0);
	color.green = fmin(color.green, 255.0);
	color.blue = fmin(color.blue, 255.0);
	return (color);
}

t_col	ambient_light(t_ambient ambient, t_col color)
{
	t_col	amb_col;

	amb_col = scale_color(ambient.ratio, ambient.color);
	amb_col = color_product(amb_col, color);
	amb_col = convert_color(amb_col, 255.0);
	return (amb_col);
}

t_col	diffuse_light(t_light *light, t_hit *hit, t_col color)
{
	double	ldn;
	double	factor;
	t_vect	light_dir;
	t_col	diff_col;

	light_dir = sub_vect(light->position, hit->point);
	light_dir = normalize(light_dir);
	ldn = dot_product(hit->normal, light_dir);
	factor = fmax(0.0, ldn);
	factor = factor * light->intensity;
	diff_col = scale_color(factor, hit->color);
	diff_col = clamping_color(diff_col);
	color = add_color(color, diff_col);
	color = clamping_color(color);
	return (color);
}

t_col	put_light(t_minirt *rt, t_scene *sc, t_hit *hit, t_col color)
{
	t_ray	ray;
	t_col	final_color;
	int		is_shade;
	double	distance;

	is_shade = 0;
	final_color = ambient_light(sc->ambient, color);
	ray.origin = hit->point;
	ray.direction = normalize(sub_vect(sc->light.position, ray.origin));
	distance = length(&ray.origin, &sc->light.position);
	is_shade = hit_object(&ray, rt, distance);
	if (distance > EPSILON && is_shade)
		final_color = shadow(final_color, 0.1);
	else
		final_color = diffuse_light(&sc->light, hit, final_color);
	final_color = clamping_color(final_color);
	free_hit(hit);
	free_hit(ray.hit);
	return (final_color);
}

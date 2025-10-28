/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:25:42 by candriam          #+#    #+#             */
/*   Updated: 2025/02/10 09:48:44 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	process_render(t_minirt *rt, t_col final_color, int *x, int *y)
{
	int	offset[2];

	offset[1] = 0;
	while (offset[1] < USE)
	{
		offset[0] = 0;
		while (offset[0] < USE)
		{
			if ((*x + offset[0]) < WIN_WIDTH && (*y + offset[1]) < WIN_HEIGHT)
				write_color((*x + offset[0]), (*y + offset[1]), final_color,
					*rt);
			offset[0]++;
		}
		offset[1]++;
	}
}

void	render_alias(t_minirt *rt)
{
	int		pos[2];
	t_col	final_color;
	t_ray	ray;
	t_vect	dir;

	pos[1] = 0;
	while (pos[1] < WIN_HEIGHT)
	{
		pos[0] = 0;
		while (pos[0] < WIN_WIDTH)
		{
			dir = compute_ray_dir(rt->scene->camera, pos[0], pos[1]);
			ray = new_ray(rt->scene->camera.position, dir);
			ray.hit = return_hit(rt, &ray);
			final_color = put_color(ray.hit);
			final_color = put_light(rt, rt->scene, ray.hit, final_color);
			process_render(rt, final_color, &pos[0], &pos[1]);
			pos[0] += USE;
		}
		pos[1] += USE;
	}
	mlx_put_image_to_window(rt->set->mlx, rt->set->win, rt->set->image, 0, 0);
}

void	render_minirt(t_minirt *rt)
{
	int		x;
	int		y;
	t_col	final_color;
	t_ray	ray;
	t_vect	dir;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			dir = compute_ray_dir(rt->scene->camera, x, y);
			ray = new_ray(rt->scene->camera.position, dir);
			ray.hit = return_hit(rt, &ray);
			final_color = put_color(ray.hit);
			final_color = put_light(rt, rt->scene, ray.hit, final_color);
			write_color(x, y, final_color, *rt);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(rt->set->mlx, rt->set->win, rt->set->image, 0, 0);
}

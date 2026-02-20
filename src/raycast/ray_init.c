/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:20:22 by fsousa            #+#    #+#             */
/*   Updated: 2026/02/19 17:21:16 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	abs_d(double v)
{
	if (v < 0.0)
		return (-v);
	return (v);
}

static void	init_step_x(t_ray *r, t_world *w)
{
	if (r->raydir_x < 0.0)
	{
		r->step_x = -1;
		r->side_x = (w->px - r->map_x) * r->delta_x;
	}
	else
	{
		r->step_x = 1;
		r->side_x = (r->map_x + 1.0 - w->px) * r->delta_x;
	}
}

static void	init_step_y(t_ray *r, t_world *w)
{
	if (r->raydir_y < 0.0)
	{
		r->step_y = -1;
		r->side_y = (w->py - r->map_y) * r->delta_y;
	}
	else
	{
		r->step_y = 1;
		r->side_y = (r->map_y + 1.0 - w->py) * r->delta_y;
	}
}

void	ray_init(t_ray *r, t_game *g, int x)
{
	t_world	*w;

	w = &g->world;
	r->x = x;
	r->camera_x = 2.0 * x / (double)g->eng.frame.w - 1.0;
	r->raydir_x = w->dir_x + w->plane_x * r->camera_x;
	r->raydir_y = w->dir_y + w->plane_y * r->camera_x;
	r->map_x = (int)w->px;
	r->map_y = (int)w->py;
	if (r->raydir_x == 0.0)
		r->delta_x = 1e30;
	else
		r->delta_x = abs_d(1.0 / r->raydir_x);
	if (r->raydir_y == 0.0)
		r->delta_y = 1e30;
	else
		r->delta_y = abs_d(1.0 / r->raydir_y);
	init_step_x(r, w);
	init_step_y(r, w);
}

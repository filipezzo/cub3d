/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_project.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:21:56 by fsousa            #+#    #+#             */
/*   Updated: 2026/02/20 14:11:19 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	perp_dist(t_ray *r, t_world *w)
{
	double	d;

	if (r->side == 0)
		d = (r->map_x - w->px + (1 - r->step_x) / 2.0) / r->raydir_x;
	else
		d = (r->map_y - w->py + (1 - r->step_y) / 2.0) / r->raydir_y;
	if (d < 0.0001)
		d = 0.0001;
	return (d);
}

static void	set_tex_x(t_ray *r, t_game *g, double wall_x)
{
	int	tw;

	tw = g->tex[r->tex_id].img.w;
	r->tex_x = (int)(wall_x * (double)tw);
	if (r->side == 0 && r->step_x == 1)
		r->tex_x = tw - r->tex_x - 1;
	if (r->side == 1 && r->step_y == -1)
		r->tex_x = tw - r->tex_x - 1;
}

void	ray_project(t_ray *r, t_game *g)
{
	t_world	*w;
	double	wall_x;

	w = &g->world;
	r->perp = perp_dist(r, w);
	r->line_h = (int)(g->eng.frame.h / r->perp);
	r->draw0 = -r->line_h / 2 + g->eng.frame.h / 2;
	r->draw1 = r->line_h / 2 + g->eng.frame.h / 2;
	if (r->draw0 < 0)
		r->draw0 = 0;
	if (r->draw1 >= g->eng.frame.h)
		r->draw1 = g->eng.frame.h - 1;
	r->tex_id = ray_tex_id(r);
	if (r->side == 0)
		wall_x = w->py + r->perp * r->raydir_y;
	else
		wall_x = w->px + r->perp * r->raydir_x;
	wall_x -= floor(wall_x);
	set_tex_x(r, g, wall_x);
	r->tex_step = (double)g->tex[r->tex_id].img.h / (double)r->line_h;
	r->tex_pos = (r->draw0 - g->eng.frame.h / 2 + r->line_h / 2) * r->tex_step;
}

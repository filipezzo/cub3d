/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:48:00 by fsousa            #+#    #+#             */
/*   Updated: 2026/02/18 17:50:44 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	abs_d(double v)
{
	if (v < 0.0)
		return (-v);
	return (v);
}

static void	set_delta(double r[7])
{
	if (r[1] == 0.0)
		r[3] = 1e30;
	else
		r[3] = abs_d(1.0 / r[1]);
	if (r[2] == 0.0)
		r[4] = 1e30;
	else
		r[4] = abs_d(1.0 / r[2]);
}

static void	set_steps(double r[7], int m[4])
{
	if (r[1] < 0.0)
		m[2] = -1;
	else
		m[2] = 1;
	if (r[2] < 0.0)
		m[3] = -1;
	else
		m[3] = 1;
}

static void	set_side_dists(t_world *w, double r[7], int m[4])
{
	if (r[1] < 0.0)
		r[5] = (w->px - (double)m[0]) * r[3];
	else
		r[5] = ((double)m[0] + 1.0 - w->px) * r[3];
	if (r[2] < 0.0)
		r[6] = (w->py - (double)m[1]) * r[4];
	else
		r[6] = ((double)m[1] + 1.0 - w->py) * r[4];
}

void	ray_setup(t_game *g, int x, double r[7], int m[4])
{
	t_engine	*e;
	t_world		*w;

	e = &g->eng;
	w = &g->world;
	r[0] = 2.0 * x / (double)e->frame.w - 1.0;
	r[1] = w->dir_x + w->plane_x * r[0];
	r[2] = w->dir_y + w->plane_y * r[0];
	m[0] = (int)w->px;
	m[1] = (int)w->py;
	set_delta(r);
	set_steps(r, m);
	set_side_dists(w, r, m);
}

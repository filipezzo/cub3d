/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:34:42 by fsousa            #+#    #+#             */
/*   Updated: 2026/02/20 16:07:36 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	cell_ok(t_world *w, double x, double y)
{
	int	ix;
	int	iy;

	ix = (int)x;
	iy = (int)y;
	if (ix < 0 || iy < 0 || ix >= w->w || iy >= w->h)
		return (0);
	return (w->grid[iy][ix] != '1');
}

static int	sign_d(double v)
{
	if (v > 0.0)
		return (1);
	if (v < 0.0)
		return (-1);
	return (0);
}

static void	try_move(t_world *w, double nx, double ny, double old[2])
{
	int	sx;
	int	sy;

	sx = sign_d(nx - old[0]);
	sy = sign_d(ny - old[1]);
	if (sx == 0)
	{
		if (cell_ok(w, nx, old[1]))
			w->px = nx;
	}
	else if (cell_ok(w, nx + (sx * COL_PAD), old[1]))
		w->px = nx;
	if (sy == 0)
	{
		if (cell_ok(w, w->px, ny))
			w->py = ny;
	}
	else if (cell_ok(w, w->px, ny + (sy * COL_PAD)))
		w->py = ny;
}

static void	rotate_view(t_world *w, double ang)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = w->dir_x;
	old_plane_x = w->plane_x;
	w->dir_x = w->dir_x * cos(ang) - w->dir_y * sin(ang);
	w->dir_y = old_dir_x * sin(ang) + w->dir_y * cos(ang);
	w->plane_x = w->plane_x * cos(ang) - w->plane_y * sin(ang);
	w->plane_y = old_plane_x * sin(ang) + w->plane_y * cos(ang);
}

void	player_update(t_game *g)
{
	t_world	*w;
	t_input	*in;
	double	v[2];
	double	len;
	double	old[2];

	w = &g->world;
	in = &g->in;
	if (in->left)
		rotate_view(w, -ROT_SPEED);
	if (in->right)
		rotate_view(w, ROT_SPEED);
	build_move_vec(v, w, in);
	len = sqrt(v[0] * v[0] + v[1] * v[1]);
	if (len > 0.0)
	{
		v[0] /= len;
		v[1] /= len;
		old[0] = w->px;
		old[1] = w->py;
		try_move(w, w->px + v[0] * MOVE_SPEED, w->py + v[1] * MOVE_SPEED, old);
	}
}

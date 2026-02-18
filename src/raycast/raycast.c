/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:22:41 by fsousa            #+#    #+#             */
/*   Updated: 2026/02/18 19:32:06 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static uint32_t	shade(uint32_t c)
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;

	r = (c >> 16) & 0xFF;
	g = (c >> 8) & 0xFF;
	b = c & 0xFF;
	r /= 2;
	g /= 2;
	b /= 2;
	return ((r << 16) | (g << 8) | b);
}

static int	ray_dda(t_world *w, double r[7], int m[4])
{
	int	side;

	side = 0;
	while (1)
	{
		if (r[5] < r[6])
		{
			r[5] += r[3];
			m[0] += m[2];
			side = 0;
		}
		else
		{
			r[6] += r[4];
			m[1] += m[3];
			side = 1;
		}
		if (m[0] < 0 || m[1] < 0 || m[0] >= w->w || m[1] >= w->h)
			return (-1);
		if (w->grid[m[1]][m[0]] == '1')
			return (side);
	}
}

static double	perp_dist(t_world *w, double r[7], int m[4], int side)
{
	double	d;

	if (side == 0)
		d = (m[0] - w->px + (1 - m[2]) / 2.0) / r[1];
	else
		d = (m[1] - w->py + (1 - m[3]) / 2.0) / r[2];
	if (d < 0.0001)
		d = 0.0001;
	return (d);
}

static void	draw_column(t_game *g, int x, int side, double d)
{
	int			h;
	int			y0;
	int			y1;
	uint32_t	c;

	h = (int)(g->eng.frame.h / d);
	y0 = -h / 2 + g->eng.frame.h / 2;
	y1 = h / 2 + g->eng.frame.h / 2;
	c = g->world.wall_rgb;
	if (side == 1)
		c = shade(c);
	draw_vline(&g->eng.frame, x, y0, y1, c);
}

void	raycast_walls(t_game *g)
{
	int		x;
	int		side;
	int		m[4];
	double	r[7];
	double	d;

	if (!g)
		return ;
	x = 0;
	while (x < g->eng.frame.w)
	{
		ray_setup(g, x, r, m);
		side = ray_dda(&g->world, r, m);
		if (side >= 0)
		{
			d = perp_dist(&g->world, r, m, side);
			draw_column(g, x, side, d);
		}
		x++;
	}
}

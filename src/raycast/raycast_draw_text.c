/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_draw_text.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:30:29 by fsousa            #+#    #+#             */
/*   Updated: 2026/02/20 14:11:46 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	clamp_int(int v, int lo, int hi)
{
	if (v < lo)
		return (lo);
	if (v > hi)
		return (hi);
	return (v);
}

int	tex_x_from_hit(t_game *g, double r[7], int m[4], double d)
{
	double	wall_x;
	int		tex_x;
	int		side;

	side = g->world.__side_tmp;
	if (side == 0)
		wall_x = g->world.py + d * r[2];
	else
		wall_x = g->world.px + d * r[1];
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)g->tex[g->world.__tex_tmp].img.w);
	if (side == 0 && m[2] == 1)
		tex_x = g->tex[g->world.__tex_tmp].img.w - tex_x - 1;
	if (side == 1 && m[3] == -1)
		tex_x = g->tex[g->world.__tex_tmp].img.w - tex_x - 1;
	return (tex_x);
}

void	draw_tex_column(t_game *g, int x, int a[4], double b[4])
{
	int			y;
	int			ty;
	uint32_t	c;
	t_data		*t;

	t = &g->tex[a[2]].img;
	y = a[0];
	while (y <= a[1])
	{
		ty = (int)b[0];
		ty = clamp_int(ty, 0, t->h - 1);
		c = tex_get_pixel(t, a[3], ty);
		put_pixel(&g->eng.frame, x, y, c);
		b[0] += b[1];
		y++;
	}
}

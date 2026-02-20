/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:23:12 by fsousa            #+#    #+#             */
/*   Updated: 2026/02/19 17:46:26 by fsousa           ###   ########.fr       */
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

void	ray_draw_column(t_game *g, t_ray *r)
{
	int			y;
	int			ty;
	uint32_t	c;
	t_data		*t;

	t = &g->tex[r->tex_id].img;
	y = r->draw0;
	while (y <= r->draw1)
	{
		ty = (int)r->tex_pos;
		ty = clamp_int(ty, 0, t->h - 1);
		c = tex_get_pixel(t, r->tex_x, ty);
		put_pixel(&g->eng.frame, r->x, y, c);
		r->tex_pos += r->tex_step;
		y++;
	}
}

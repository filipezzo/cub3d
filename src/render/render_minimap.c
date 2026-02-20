/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 15:49:46 by fsousa            #+#    #+#             */
/*   Updated: 2026/02/20 15:50:48 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	mm_draw_grid(t_game *g, t_mm *m)
{
	t_rect	r;

	m->y = 0;
	while (m->y < g->world.h)
	{
		m->x = 0;
		while (m->x < g->world.w)
		{
			r = (t_rect){m->x * TILE, m->y * TILE, TILE, TILE, 0x00202020};
			if (g->world.grid[m->y][m->x] == '1')
				r.color = 0x00FFFFFF;
			draw_rect(&g->eng.frame, r);
			m->x++;
		}
		m->y++;
	}
}

static void	mm_draw_player(t_game *g, t_mm *m)
{
	t_rect	p;
	t_line	l;

	m->px = (int)(g->world.px * TILE);
	m->py = (int)(g->world.py * TILE);
	p = (t_rect){m->px - 2, m->py - 2, 5, 5, 0x00FF0000};
	draw_rect(&g->eng.frame, p);
	l = (t_line){m->px, m->py, (int)(m->px + g->world.dir_x * (TILE * 2)),
		(int)(m->py + g->world.dir_y * (TILE * 2)), 0x00FF0000};
	draw_line(&g->eng.frame, l);
}

void	render_minimap(t_game *game)
{
	t_mm	m;

	mm_draw_grid(game, &m);
	mm_draw_player(game, &m);
}

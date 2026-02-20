/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 12:33:27 by fsousa            #+#    #+#             */
/*   Updated: 2026/02/20 14:44:16 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static void	draw_rect(t_data *img, int x0, int y0, int w, int h, uint32_t color)
{
	int x, y;
	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			put_pixel(img, x0 + x, y0 + y, color);
			x++;
		}
		y++;
	}
}

static void	draw_line(t_data *img, int x0, int y0, int x1, int y1,
		uint32_t color)
{
	double	dx;
	double	dy;
	double	steps;
	double	x;
	double	y;
	double	x_inc;
	double	y_inc;
	int		i;

	dx = (double)(x1 - x0);
	dy = (double)(y1 - y0);
	steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
	x = x0;
	y = y0;
	if (steps == 0)
	{
		put_pixel(img, x0, y0, color);
		return ;
	}
	x_inc = dx / steps;
	y_inc = dy / steps;
	i = 0;
	while (i <= (int)steps)
	{
		put_pixel(img, (int)x, (int)y, color);
		x += x_inc;
		y += y_inc;
		i++;
	}
}

void	render_minimap(t_game *game)
{
	int x, y;
	int px, py;
	int dx, dy;
	
	y = 0;
	while (y < game->world.h)
	{
		x = 0;
		while (x < game->world.w)
		{
			if (game->world.grid[y][x] == '1')
				draw_rect(&game->eng.frame, x * TILE, y * TILE, TILE, TILE,
					0x00FFFFFF);
			else
				draw_rect(&game->eng.frame, x * TILE, y * TILE, TILE, TILE,
					0x00202020);
			x++;
		}
		y++;
	}
	px = (int)(game->world.px * TILE);
	py = (int)(game->world.py * TILE);
	draw_rect(&game->eng.frame, px - 2, py - 2, 5, 5, 0x00FF0000);
	dx = (int)(px + game->world.dir_x * (TILE * 2));
	dy = (int)(py + game->world.dir_y * (TILE * 2));
	draw_line(&game->eng.frame, px, py, dx, dy, 0x00FF0000);
}

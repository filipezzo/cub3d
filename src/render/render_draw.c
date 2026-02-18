/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:40:22 by fsousa            #+#    #+#             */
/*   Updated: 2026/02/18 18:23:12 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_vline(t_data *img, int x, int y0, int y1, uint32_t color)
{
	int	y;

	if (!img || x < 0 || x >= img->w)
		return ;
	if (y0 < 0)
		y0 = 0;
	if (y1 >= img->h)
		y1 = img->h - 1;
	y = y0;
	while (y <= y1)
	{
		put_pixel(img, x, y, color);
		y++;
	}
}

void	draw_floor_ceil(t_engine *e, t_world *w)
{
	int	x;
	int	y;

	if (!e || !w)
		return ;
	y = 0;
	while (y < e->frame.h)
	{
		x = 0;
		while (x < e->frame.w)
		{
			if (y < e->frame.h / 2)
				put_pixel(&e->frame, x, y, w->ceil_rgb);
			else
				put_pixel(&e->frame, x, y, w->floor_rgb);
			x++;
		}
		y++;
	}
}

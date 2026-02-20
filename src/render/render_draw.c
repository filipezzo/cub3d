/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:40:22 by fsousa            #+#    #+#             */
/*   Updated: 2026/02/20 16:01:48 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

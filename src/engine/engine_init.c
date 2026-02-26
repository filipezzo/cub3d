/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:58:58 by fsousa            #+#    #+#             */
/*   Updated: 2026/02/18 16:02:27 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	engine_init(t_engine *e, int w, int h, const char *title)
{
	e->mlx = mlx_init();
	if (!e->mlx)
		return (FALSE);
	e->win = mlx_new_window(e->mlx, w, h, (char *)title);
	if (!e->win)
		return (FALSE);
	e->frame.img = mlx_new_image(e->mlx, w, h);
	if (!e->frame.img)
		return (FALSE);
	e->frame.addr = mlx_get_data_addr(e->frame.img, &e->frame.bits_per_pixel,
			&e->frame.line_length, &e->frame.endian);
	if (!e->frame.addr)
		return (FALSE);
	e->win_w = w;
	e->win_h = h;
	e->frame.h = h;
	e->frame.w = w;
	e->running = TRUE;
	return (TRUE);
}

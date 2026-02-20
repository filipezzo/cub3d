/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 15:48:28 by fsousa            #+#    #+#             */
/*   Updated: 2026/02/20 16:18:19 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rect(t_data *img, t_rect r)
{
	int	x;
	int	y;

	y = 0;
	while (y < r.h)
	{
		x = 0;
		while (x < r.w)
		{
			put_pixel(img, r.x + x, r.y + y, r.color);
			x++;
		}
		y++;
	}
}

static t_dda	dda_init(t_line l)
{
	t_dda	s;

	s.dx = (double)(l.x1 - l.x0);
	s.dy = (double)(l.y1 - l.y0);
	s.steps = fabs(s.dx);
	if (fabs(s.dy) > s.steps)
		s.steps = fabs(s.dy);
	s.x = l.x0;
	s.y = l.y0;
	s.x_inc = 0;
	s.y_inc = 0;
	if (s.steps != 0)
	{
		s.x_inc = s.dx / s.steps;
		s.y_inc = s.dy / s.steps;
	}
	return (s);
}

void	draw_line(t_data *img, t_line l)
{
	t_dda	s;
	int		i;

	s = dda_init(l);
	if (s.steps == 0)
	{
		put_pixel(img, l.x0, l.y0, l.color);
		return ;
	}
	i = 0;
	while (i <= (int)s.steps)
	{
		put_pixel(img, (int)s.x, (int)s.y, l.color);
		s.x += s.x_inc;
		s.y += s.y_inc;
		i++;
	}
}

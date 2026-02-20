/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_dda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:21:26 by fsousa            #+#    #+#             */
/*   Updated: 2026/02/20 14:11:20 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	in_bounds(t_world *w, int x, int y)
{
	if (x < 0 || y < 0)
		return (0);
	if (x >= w->w || y >= w->h)
		return (0);
	return (1);
}

int	ray_dda(t_ray *r, t_world *w)
{
	while (1)
	{
		if (r->side_x < r->side_y)
		{
			r->side_x += r->delta_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_y += r->delta_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (!in_bounds(w, r->map_x, r->map_y))
			return (0);
		if (w->grid[r->map_y][r->map_x] == '1')
			return (1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:22:41 by fsousa            #+#    #+#             */
/*   Updated: 2026/02/20 14:12:00 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast_walls(t_game *g)
{
	t_ray	r;
	int		x;

	if (!g)
		return ;
	x = 0;
	while (x < g->eng.frame.w)
	{
		ray_init(&r, g, x);
		if (ray_dda(&r, &g->world))
		{
			ray_project(&r, g);
			ray_draw_column(g, &r);
		}
		x++;
	}
}

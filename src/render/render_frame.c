/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:07:38 by fsousa            #+#    #+#             */
/*   Updated: 2026/02/20 14:38:49 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_frame(t_game *g)
{
	if (!g)
		return ;
	draw_floor_ceil(&g->eng, &g->world);
	raycast_walls(g);
	render_minimap(g);
}

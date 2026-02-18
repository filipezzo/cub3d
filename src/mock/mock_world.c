/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:32:52 by fsousa            #+#    #+#             */
/*   Updated: 2026/02/18 19:39:19 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	world_fake(t_world *out)
{
	static char *arr[] = {"11111", "10001", "10001", "10001", "10001", "11111",
		NULL};

	out->grid = arr;
	out->w = 5;
	out->h = 6;
	out->px = 2.5;
	out->py = 3.5;
	out->dir_x = 0.0;
	out->dir_y = -1.0;
	out->plane_x = 0.66;
	out->plane_y = 0.0;
	out->floor_rgb = 0x00606060;
	out->ceil_rgb = 0x00202020;
	out->wall_rgb = 0x000000FF;
	out->tex_path[TEX_N] = NULL;
	out->tex_path[TEX_S] = NULL;
	out->tex_path[TEX_W] = NULL;
	out->tex_path[TEX_E] = NULL;
}
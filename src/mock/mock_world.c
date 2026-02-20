/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:32:52 by fsousa            #+#    #+#             */
/*   Updated: 2026/02/20 16:21:51 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	world_fake(t_world *out)
{
	static char	*arr[] = {
		"1111111111",
		"1000000001",
		"1000010001",
		"1001000101",
		"1000010001",
		"1111111111",
		NULL
	};

	out->grid = arr;
	out->w = 10;
	out->h = 6;
	out->px = 2.5;
	out->py = 3.5;
	out->dir_x = 0.0;
	out->dir_y = -1.0;
	out->plane_x = 0.66;
	out->plane_y = 0.0;
	out->floor_rgb = 0x00BDB39B;
	out->ceil_rgb = 0x00101424;
	out->wall_rgb = 0x00FF00FF;
	out->tex_path[TEX_N] = "../assets/textures/north.xpm";
	out->tex_path[TEX_S] = "../assets/textures/south.xpm";
	out->tex_path[TEX_W] = "../assets/textures/west.xpm";
	out->tex_path[TEX_E] = "../assets/textures/east.xpm";
}

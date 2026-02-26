/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:24:57 by fsousa            #+#    #+#             */
/*   Updated: 2026/02/19 17:48:01 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	load_one(t_game *g, int id, char *path)
{
	t_data	*img;
	int		w;
	int		h;

	img = &g->tex[id].img;
	img->img = mlx_xpm_file_to_image(g->eng.mlx, path, &w, &h);
	if (!img->img)
		return (0);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
		return (0);
	img->w = w;
	img->h = h;
	return (1);
}

int	textures_load(t_game *g)
{
	int	i;

	i = 0;
	while (i < TEX_COUNT)
	{
		if (!g->world.tex_path[i])
			return (0);
		if (!load_one(g, i, g->world.tex_path[i]))
			return (0);
		i++;
	}
	return (1);
}

void	textures_destroy(t_game *g)
{
	int	i;

	i = 0;
	while (i < TEX_COUNT)
	{
		if (g->tex[i].img.img)
		{
			mlx_destroy_image(g->eng.mlx, g->tex[i].img.img);
			g->tex[i].img.img = NULL;
		}
		i++;
	}
}

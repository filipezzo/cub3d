/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:45:02 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/13 15:58:07 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	load_texture(t_engine *engine, t_data *tex, char *path)
{
	int	fd;

	if (!tex || !path)
		return (FALSE);
	fd = 0;
	path = ft_strtrim(path, " \t\n");
	if (!validate_fpath(path, ".xpm", &fd))
	{
		safe_close_fd(fd);
		exit(EXIT_FAILURE);
	}
	safe_close_fd(fd);
	tex->img = mlx_xpm_file_to_image(engine->mlx, path, &tex->w, &tex->h);
	if (!tex->img)
	{
		perr("Failed to load texture");
		return (FALSE);
	}
	tex->addr = mlx_get_data_addr(
		tex->img,
		&tex->bits_per_pixel,
		&tex->line_length,
		&tex->endian);
	return (TRUE);
}

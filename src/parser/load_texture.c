/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:45:02 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/19 10:39:13 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	load_texture(t_engine *engine, t_data *tex, char *path)
{
	int	fd;

	if (!tex || !path)
		return (FALSE);
	path = ft_strtrim(path, " \t\n");
	fd = validate_fpath(path, ".xpm");
	if (fd == -1)
		exit(EXIT_FAILURE);
	safe_close_fd(fd);
	tex->img = mlx_xpm_file_to_image(engine->mlx, path, &tex->w, &tex->h);
	if (!tex->img)
		return (perr_failed("Failed to MLX load texture"));
	tex->addr = mlx_get_data_addr(
		tex->img,
		&tex->bits_per_pixel,
		&tex->line_length,
		&tex->endian);
	if (!tex->addr)
		return (perr_failed("Failed to get MLX texture address"));
	return (TRUE);
}

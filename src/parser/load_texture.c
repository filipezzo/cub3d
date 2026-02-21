/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:45:02 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/20 20:09:25 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	load_texture(t_world *world, int tgt, char *path)
{
	int	fd;

	if (!path)
		return (FALSE);
	fd = validate_fpath(path, ".xpm");
	if (fd == -1)
		exit(EXIT_FAILURE);
	safe_close_fd(fd);
	world->tex_path[tgt] = path;
	return (TRUE);
}

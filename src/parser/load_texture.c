/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:45:02 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/21 00:53:00 by mhidani          ###   ########.fr       */
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
	world->tex_path[tgt] = ft_strdup(path);
	return (TRUE);
}

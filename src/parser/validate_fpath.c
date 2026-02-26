/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_fpath.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:31:07 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/19 16:08:56 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bool	isext(char *file, char *ext);

int	validate_fpath(char *fpath, char *ext)
{
	int	fd;

	if (!fpath || !ext)
		return (FALSE);
	if (!isext(fpath, ext))
	{
		perr("The file extension provided is invalid");
		return (-1);
	}
	fd = open(fpath, O_RDONLY);
	if (fd == -1)
		perr("Could not find the map file");
	return (fd);
}

static t_bool	isext(char *file, char *ext)
{
	size_t	extension_size;
	size_t	to_target;

	if (!file || !ext)
		return (FALSE);
	extension_size = ft_strlen(ext);
	to_target = ft_strlen(file) - extension_size;
	return (ft_strncmp(file + to_target, ext, extension_size) == 0);
}

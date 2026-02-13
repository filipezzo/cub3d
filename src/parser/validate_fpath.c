/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_fpath.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:31:07 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/13 15:36:40 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	validate_fpath(char *fpath, char *ext, int *fd)
{
	if (!fpath || !ext)
		return (FALSE);
	if (!isext(fpath, ext))
	{
		perr("The file extension provided is invalid");
		return (FALSE);
	}
	*fd = open(fpath, O_RDONLY);
	if (fd == -1)
	{
		perr("Could not find the map file");
		return (FALSE);
	}
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isext.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 20:16:36 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/13 14:15:30 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	isext(char *file, char *ext)
{
	size_t	extension_size;
	size_t	to_target;

	if (!file || !ext)
		return (FALSE);
	extension_size = ft_strlen(ext);
	to_target = ft_strlen(file) - extension_size;
	return (ft_strncmp(file + to_target, ext, extension_size) == 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_ext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 20:16:36 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/11 20:20:53 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	is_valid_ext(char *file, char *ext)
{
	size_t	ext_size;
	size_t	to_target;

	if (!file || !ext)
		return (FALSE);
	ext_size = ft_strlen(ext);
	to_target = ft_strlen(file) - ext_size;
	return (ft_strncmp(file + to_target, ext, ext_size) == 0);
}

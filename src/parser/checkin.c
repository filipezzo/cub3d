/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:21:42 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/11 20:19:55 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	checkin(char *map)
{
	int	fd;
	
	if (!map || !is_valid_ext(map, ".cub"))
		return (-1);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_putstr_fd("Could not find the map file\n", STDERR_FILENO); // TODO: create a error function
	return (fd); // TODO: remember to close this fd
}

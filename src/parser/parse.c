/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:07:42 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/12 12:18:38 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_world	parse(char *fpath)
{
	t_world	world;
	char	**input;
	int		fd;

	if (!fpath)
	{
		printf("[error] no path the map file was provided\n"); // TODO: create the func message error
		exit(EXIT_FAILURE);
	}
	fd = checkin(fpath);
	if (fd == -1)
		exit(EXIT_FAILURE);
	// TODO: implement 👇
	// TODO: input = read_input(fd)
	// TODO: parse_header(&world, input)
	// TODO: parse_map(&world, input)
	return (world);
}

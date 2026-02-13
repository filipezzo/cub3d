/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:07:42 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/13 14:18:22 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_dlist	*read_input(int fd);
static void		parse_header(t_world *world, t_dlist *lines);
static void		parse_map(t_world *world, t_dlist *lines);

void	parse(char *fpath, t_world *world)
{
	t_dlist	*lines;
	int		fd;

	if (!fpath || !*fpath)
		perr_exit("No path the map file was provided", EXIT_FAILURE);
	if (!isext(fpath, ".cub"))
		perr_exit("The file extension provided is invalid", EXIT_FAILURE);
	fd = open(fpath, O_RDONLY);
	if (fd == -1)
		perr_exit("Could not find the map file", EXIT_FAILURE);
	lines = read_input(fd);
	// TODO: implement 👇
	// TODO: parse_header(&world, input)
	// TODO: parse_map(&world, input)
	ft_destroy_dlist(lines);
}

static t_dlist	*read_input(int fd)
{
	t_dlist	*lines;
	char	*line;

	lines = ft_new_dlist();
	if (!lines)
		perr_exit("Construction the map line list failed", EXIT_FAILURE);
	line = ft_get_next_line(fd);
	while (line)
	{
		ft_add_nd_dlist(lines, line, free);
		line = ft_get_next_line(fd);
	}
	return (lines);
}

static void	parse_header(t_world *world, t_dlist *lines)
{}

static void	parse_map(t_world *world, t_dlist *lines)
{}


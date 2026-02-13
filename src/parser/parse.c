/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:07:42 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/13 15:49:42 by mhidani          ###   ########.fr       */
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
	if (!validate_fpath(fpath, ".cub", &fd))
	{
		safe_close_fd(fd);
		exit(EXIT_FAILURE);
	}
	safe_close_fd(fd);
	lines = read_input(fd);
	// TODO: implement 👇
	parse_header(&world, lines);
	parse_map(&world, lines);
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


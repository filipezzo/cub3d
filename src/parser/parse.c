/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:07:42 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/14 01:52:42 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_dlist	*read_input(int fd);
static void		parse_header(t_engine *engine, t_world *world, t_dlist *lines);
static void		parse_map(t_engine *engine, t_world *world, t_dlist *lines);

void	parse(char *fpath, t_engine *engine, t_world *world)
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
	parse_header(engine, world, lines);
	parse_map(engine, world, lines);
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

static void	parse_header(t_engine *engine, t_world *world, t_dlist *lines)
{
	t_bnode	*node;
	t_bool	cardinal[4];

	ft_memset(cardinal, 0, 4);
	node = lines->head;
	while (node)
	{
		if (!cardinal[0] && ft_strncmp(node->data, NORTH_TGT, 3) == 0)
			cardinal[0] = load_texture(engine, world->texs.n, node->data);
		else if (!cardinal[1] && ft_strncmp(node->data, SOUTH_TGT, 3) == 0)
			cardinal[1] = load_texture(engine, world->texs.s, node->data);
		else if (!cardinal[2] && ft_strncmp(node->data, WEST_TGT, 3) == 0)
			cardinal[2] = load_texture(engine, world->texs.w, node->data);
		else if (!cardinal[3] && ft_strncmp(node->data, EAST_TGT, 3) == 0)
			cardinal[3] = load_texture(engine, world->texs.e, node->data);
		else if (ft_strncmp(node->data, "C", 1) == 0)
			world->ceil_rgb = parse_rgb(node->data);
		else if (ft_strncmp(node->data, "F", 1) == 0)
			world->floor_rgb = parse_rgb(node->data);
		node = node->right;
	}
}

static void	parse_map(t_engine *engine, t_world *world, t_dlist *lines)
{
	t_bnode	*node;

	node = lines->tail;
	while (node)
	{
		// TODO: implements parse map
		node = node->left;
	}
}

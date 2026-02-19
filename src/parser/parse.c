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
static t_bool	parse_header(t_engine *engine, t_world *world, t_dlist *raw);
static t_bool	parse_map(t_engine *engine, t_world *world, t_dlist *raw);

void	parse(char *fpath, t_engine *engine, t_world *world)
{
	t_dlist	*raw;
	int		fd;
	char	chk[2];

	if (!fpath || !*fpath)
		perr_exit("No path the map file was provided", EXIT_FAILURE);
	fd = validate_fpath(fpath, ".cub");
	if (fd == -1)
		exit(EXIT_FAILURE);
	raw = read_input(fd);
	chk[0] = parse_header(engine, world, raw);
	chk[1] = parse_map(engine, world, raw);
	ft_destroy_dlist(raw);
	if (!(chk[0] & chk[1]))
	{
		destroy_world(world); // TODO: implements
		perr_exit("The file Cub3D map is invalid", EXIT_FAILURE);
	}
}

static t_dlist	*read_input(int fd)
{
	t_dlist	*raw;
	char	*line;

	raw = ft_new_dlist();
	if (!raw)
		perr_exit("Construction the list lines raw map failed", EXIT_FAILURE);
	line = ft_get_next_line(fd);
	while (line)
	{
		ft_add_nd_dlist(raw, ft_strtrim(line, "\n"), free);
		free(line);
		line = ft_get_next_line(fd);
	}
	safe_close_fd(fd);
	return (raw);
}

static void	parse_header(t_engine *engine, t_world *world, t_dlist *lines)
{
	t_bnode	*node;
	t_bool	cardinal[4];

	ft_memset(cardinal, 0, 4);
	node = lines->head;
	while (node)
	{
		if (!chk[0] && ft_strncmp(node->data, NORTH_TGT, 3) == 0)
			chk[0] = load_texture(engine, world->texs.n, node->data);
		else if (!chk[1] && ft_strncmp(node->data, SOUTH_TGT, 3) == 0)
			chk[1] = load_texture(engine, world->texs.s, node->data);
		else if (!chk[2] && ft_strncmp(node->data, WEST_TGT, 3) == 0)
			chk[2] = load_texture(engine, world->texs.w, node->data);
		else if (!chk[3] && ft_strncmp(node->data, EAST_TGT, 3) == 0)
			chk[3] = load_texture(engine, world->texs.e, node->data);
		else if (ft_strncmp(node->data, CEIL_TGT, 2) == 0)
			chk[4] = load_color(node->data, &world->ceil_rgb);
		else if (ft_strncmp(node->data, FLOOR_TGT, 2) == 0)
			chk[5] = load_color(node->data, &world->floor_rgb);
		node = node->right;
	}
	if (ft_indexof_dlist(raw, node) > ft_indexof_dlist(raw, get_start_map(raw)))
		return (perr_failed("The header map is not valid"));
	return (chk[0] & chk[1] & chk[2] & chk[3] & chk[4] & chk[5]);
}

static t_bool	parse_map(t_engine *engine, t_world *world, t_dlist *raw)
{
	t_bnode	*node;

	node = get_start_map(raw);
	count_map_size(world, node);
	new_rawmap(world, node);
	if (!analize_map(world))
		return (perr_failed("The map is not valid"));
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:07:42 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/20 21:44:04 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_dlist	*read_input(int fd);
static t_bool	parse_header(t_world *world, t_dlist *raw);
static t_bool	parse_map(t_world *world, t_dlist *raw);

void	parse(char *fpath, t_world *world)
{
	t_dlist	*raw;
	int		fd;
	char	chk[3];

	if (!fpath || !*fpath)
		perr_exit("No path the map file was provided", EXIT_FAILURE);
	fd = validate_fpath(fpath, ".cub");
	if (fd == -1)
		exit(EXIT_FAILURE);
	raw = read_input(fd);
	ft_memset(chk, 0, 3);
	chk[0] = parse_header(world, raw);
	chk[1] = parse_map(world, raw);
	ft_destroy_dlist(raw);
	if (!(chk[0] & chk[1]))
	{
		destroy_cmtx_rev(world->grid, world->h);
		perr_exit("The file Cub3D map is invalid", EXIT_FAILURE);
	}
}

static t_dlist	*read_input(int fd)
{
	t_dlist	*raw;
	char	*aux;
	char	*line;

	raw = ft_new_dlist();
	if (!raw)
		perr_exit("Construction the list lines raw map failed", EXIT_FAILURE);
	line = ft_get_next_line(fd);
	while (line)
	{
		aux = ft_strtrim(line, "\n");
		if (ft_strlen(aux) > 0)
			ft_add_nd_dlist(raw, aux, free);
		else
			free(aux);
		free(line);
		line = ft_get_next_line(fd);
	}
	safe_close_fd(fd);
	return (raw);
}

static t_bool	parse_header(t_world *world, t_dlist *raw)
{
	t_bnode	*node;
	char	chk[7];

	ft_memset(chk, FALSE, 7);
	node = raw->head;
	while (node && !(chk[0] & chk[1] & chk[2] & chk[3] & chk[4] & chk[5]))
	{
		if (!chk[0] && ft_strncmp(node->data, NORTH_TGT, 3) == 0)
			chk[0] = load_texture(world, TEX_N, node->data + 3);
		else if (!chk[1] && ft_strncmp(node->data, SOUTH_TGT, 3) == 0)
			chk[1] = load_texture(world, TEX_S, node->data + 3);
		else if (!chk[2] && ft_strncmp(node->data, WEST_TGT, 3) == 0)
			chk[2] = load_texture(world, TEX_W, node->data + 3);
		else if (!chk[3] && ft_strncmp(node->data, EAST_TGT, 3) == 0)
			chk[3] = load_texture(world, TEX_E, node->data + 3);
		else if (ft_strncmp(node->data, CEIL_TGT, 2) == 0)
			chk[4] = load_color(&world->ceil_rgb, node->data + 2);
		else if (ft_strncmp(node->data, FLOOR_TGT, 2) == 0)
			chk[5] = load_color(&world->floor_rgb, node->data + 2);
		node = node->right;
	}
	if (ft_getidx_dlist(raw, node) > ft_getidx_dlist(raw, get_start_map(raw)))
		return (perr_failed("The header map is not valid"));
	return (chk[0] & chk[1] & chk[2] & chk[3] & chk[4] & chk[5]);
}

static t_bool	parse_map(t_world *world, t_dlist *raw)
{
	t_bnode	*node;

	node = get_start_map(raw);
	count_map_size(world, node);
	new_rawmap(world, node);
	if (!analize_map(world))
		return (perr_failed("The map is not valid"));
	return (TRUE);
}

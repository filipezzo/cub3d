/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_parse_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:04:58 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/20 21:48:29 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bnode	*get_start_map(t_dlist *lines)
{
	t_bnode	*node;
	char	*pvt;

	if (!lines)
		return (NULL);
	node = lines->head;
	while (node)
	{
		pvt = (char *)node->data;
		while (*pvt == 32)
			pvt++;
		if (*pvt == 49)
			return (node);
		node = node->right;
	}
	return (NULL);
}

void	count_map_size(t_world *world, t_bnode *node)
{
	int	width;
	int	height;
	int	len;

	width = 0;
	height = 0;
	while (node)
	{
		len = ft_strlen(node->data);
		if (len > width)
			width = len;
		height++;
		node = node->right;
	}
	world->w = width;
	world->h = height;
}

void	new_rawmap(t_world *world, t_bnode *node)
{
	int	i;

	world->grid = ft_calloc(world->h, sizeof(char *));
	if (!world->grid)
	{
		perr("grid memory allocation failed");
		return ;
	}
	i = 0;
	while (i < (world->h) && node)
	{
		world->grid[i] = ft_strdup(node->data);
		if (!world->grid[i])
		{
			perr("get grid row failed");
			destroy_cmtx_rev(world->grid, i);
			return ;
		}
		set_player_pos(world, i);
		node = node->right;
		i++;
	}
}

void	set_player_pos(t_world *world, int x)
{
	int		y;
	char	tgt;

	y = 0;
	while (world->grid[x][y])
	{
		tgt = world->grid[x][y];
		if (tgt && (tgt == 'N' || tgt == 'S' || tgt == 'E' || tgt == 'W'))
		{
			world->px = x + 0.5;
			world->py = y + 0.5;
			set_player_dir(world, tgt);
			world->grid[x][y] = 'P';
			break ;
		}
		y++;
	}
}

void	set_player_dir(t_world *world, char tgt)
{
	if (tgt == 'N')
		set_vec2(0, -1, &world->dir_x, &world->dir_y);
	else if (tgt == 'S')
		set_vec2(0, 1, &world->dir_x, &world->dir_y);
	else if (tgt == 'E')
		set_vec2(1, 0, &world->dir_x, &world->dir_y);
	else if (tgt == 'W')
		set_vec2(-1, 0, &world->dir_x, &world->dir_y);
	//world->plane_x = -world->dir_y * world->fov;
	//world->plane_y = world->dir_x * world->fov;
}

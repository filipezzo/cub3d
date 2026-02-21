/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analize_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:20:47 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/21 10:58:35 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char		*normalize_line_rawmap(char *line, size_t n);
static void		normalize_rawmap(t_world *world);
static void		find_player(t_world *world, int *y, int *x);
static t_bool	flood_and_fill(t_world *world, char **map, int y, int x);

t_bool	analize_map(t_world *world)
{
	t_bool	is_valid;
	char	**map;
	int		x;
	int		y;

	x = 0;
	y = 0;
	normalize_rawmap(world);
	find_player(world, &y, &x);
	map = dupmap(world);
	is_valid = flood_and_fill(world, map, y, x);
	destroy_cmtx_rev(map, world->h);
	return (is_valid);
}

static char	*normalize_line_rawmap(char *line, size_t n)
{
	char	*new;
	size_t	i;
	size_t	len;

	if (!line || n == 0)
		return (NULL);
	len = ft_strlen(line);
	if (len >= n)
		return (ft_strdup(line));
	new = ft_calloc(n + 1, sizeof(char));
	if (!new)
	{
		perr("It was not possible to recalculate part of the map");
		return (NULL);
	}
	i = 0;
	while (i < n)
	{
		if (i < len)
			new[i] = line[i];
		else
			new[i] = 32;
		i++;
	}
	return (new);
}

static void		normalize_rawmap(t_world *world)
{
	int		x;
	int		size;
	char	*aux;

	x = 0;
	while (x < world->h)
	{
		size = ft_strlen(world->grid[x]);
		if (size < world->w)
		{
			aux = normalize_line_rawmap(world->grid[x], (size_t)world->w);
			if (!aux)
			{
				destroy_cmtx_rev(world->grid, world->h);
				perr_exit("Normalization of the Raw Map failed", EXIT_FAILURE);
			}
			free(world->grid[x]);
			world->grid[x] = aux;
		}
		x++;
	}
}

static void	find_player(t_world *world, int *y, int *x)
{
	if (!world->grid)
		return ;
	while (*y < world->h)
	{
		*x = 0;
		while (*x < world->w)
		{
			if (world->grid[*y][*x] == 'P')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

static t_bool	flood_and_fill(t_world *world, char **map, int y, int x)
{
	if (x < 0 || y < 0 || x >= world->w || y >= world->h)
		return (FALSE);
	if (map[y][x] == ' ')
		return (FALSE);
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (TRUE);
	map[y][x] = 'V';
	if (!flood_and_fill(world, map, y, x + 1))
		return (FALSE);
	if (!flood_and_fill(world, map, y, x - 1))
		return (FALSE);
	if (!flood_and_fill(world, map, y + 1, x))
		return (FALSE);
	if (!flood_and_fill(world, map, y - 1, x))
		return (FALSE);
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analize_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:20:47 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/20 21:42:03 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char		*normalize_line_rawmap(char *line, int n);
static void		normalize_rawmap(t_world *world);
static t_bool	flood_and_fill(t_world *world, char **map, int x, int y);

t_bool	analize_map(t_world *world)
{
	t_bool	is_valid;

	normalize_rawmap(world);
	is_valid = flood_and_fill(world, world->grid, 0, 0);
	return (is_valid);
}

static char	*normalize_line_rawmap(char *line, int n)
{
	int		i;
	char	*new;

	if (!line || n == 0 || (line && ft_strlen(line) >= (size_t)n))
		return (NULL);
	new = ft_calloc(n + 1, sizeof(char));
	if (!new)
	{
		perr("It was not possible to recalculate part of the map");
		return (NULL);
	}
	i = 0;
	while (i < n)
	{
		if (line[i])
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
			aux = normalize_line_rawmap(world->grid[x], world->w);
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

static t_bool	flood_and_fill(t_world *world, char **map, int x, int y)
{
	if (x < 0 || y < 0 || x >= world->w || y >= world->h)
		return (FALSE);

	if (map[x][y] == '1' || map[x][y] == 'V')
		return (TRUE);

	if (map[x][y] == ' ')
		return (FALSE);
	map[x][y] = 'V';
	flood_and_fill(world, map, x + 1, y);
	flood_and_fill(world, map, x - 1, y);
	flood_and_fill(world, map, x, y + 1);
	flood_and_fill(world, map, x, y - 1);
	return (TRUE);
}

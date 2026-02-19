/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analize_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:20:47 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/19 15:59:36 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	find_normal_rawmap(t_world *world);
static char		*normalize_line_rawmap(char *line, size_t n);
static void		normalize_rawmap(t_world *world);
static t_bool	flood_and_fill(t_world *world, char **map, int x, int y);

t_bool	analize_map(t_world *world)
{
	t_bool	is_valid;

	normalize_rawmap(world);
	is_valid = flood_and_fill(world, world->grid, 0, 0);
	return (is_valid);
}

static size_t	find_normal_rawmap(t_world *world)
{
	size_t	x;
	size_t	aux;
	size_t	max;

	x = 0;
	max = 0;
	while (x < world->h)
	{
		aux = ft_strlen(world->grid[x]);
		if (aux > max)
			max = aux;
		x++;
	}
	return (max);
}

static char	*normalize_line_rawmap(char *line, size_t n)
{
	size_t	i;
	char	*new;

	if (!line || n == 0 || (line && ft_strlen(line) >= n))
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
	size_t	x;
	size_t	size;
	size_t	normal;
	char	*aux;

	x = 0;
	normal = find_normal_rawmap(world);
	while (x < (world->h))
	{
		size = ft_strlen(world->grid[x]);
		if (size < normal)
		{
			aux = normalize_line_rawmap(world->grid[x], normal);
			if (!aux)
			{
				destroy_world(world); // TODO: implements
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

    if (map[y][x] == '1' || map[y][x] == 'V')
		return (TRUE);

    if (map[y][x] == ' ')
        return (FALSE);

    map[y][x] = 'V';
    flood_fill(map, x+1, y, world);
    flood_fill(map, x-1, y, world);
    flood_fill(map, x, y+1, world);
    flood_fill(map, x, y-1, world);
	return (TRUE);
}

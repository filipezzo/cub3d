/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dupmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 22:38:35 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/20 22:41:52 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**dupmap(t_world *world)
{
	char	**new;
	int		i;

	if (!world || !world->grid)
		return (NULL);
	new = ft_calloc(world->h, sizeof(char *));
	if (!new)
		return (NULL);
	i = 0;
	while (i < world->h)
	{
		new[i] = ft_strdup(world->grid[i]);
		i++;
	}
	return (new);
}

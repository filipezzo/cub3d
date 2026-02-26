/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_shutdown.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:27:18 by fsousa            #+#    #+#             */
/*   Updated: 2026/02/20 14:31:34 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_shutdown(t_game *g)
{
	if (!g)
		return ;
	textures_destroy(g);
	engine_shutdown(&g->eng);
}

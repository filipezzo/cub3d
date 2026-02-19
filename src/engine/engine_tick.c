/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_tick.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 12:34:25 by fsousa            #+#    #+#             */
/*   Updated: 2026/02/18 16:04:32 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	engine_tick(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (!game)
		return (0);
	if (!game->eng.running)
	{
		engine_shutdown(&game->eng);
		exit(0);
	}
	player_update(game);
	render_minimap(game);
	mlx_put_image_to_window(game->eng.mlx, game->eng.win, game->eng.frame.img,
		0, 0);
	return (0);
}

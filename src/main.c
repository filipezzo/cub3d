/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:00:55 by fsousa            #+#    #+#             */
/*   Updated: 2026/02/20 16:02:11 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_game	game;

	ft_bzero(&game, sizeof(game));
	world_fake(&game.world);
	if (!engine_init(&game.eng, GAME_WIDTH, GAME_HEIGHT, "cub3d"))
		return (1);
	if (!textures_load(&game))
	{
		ft_putstr_fd("Error: textures_load failed", 2);
		engine_shutdown(&game.eng);
		return (1);
	}
	engine_register_hooks(&game);
	mlx_loop(game.eng.mlx);
	return (0);
}

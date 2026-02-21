/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:00:55 by fsousa            #+#    #+#             */
/*   Updated: 2026/02/20 20:15:37 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		pinfo("The information entered is invalid. Please enter only the map");
		return (EXIT_SUCCESS);
	}
	ft_bzero(&game, sizeof(game));
	//world_fake(&game.world);
	parse(argv[1], &game.world);
	if (!engine_init(&game.eng, GAME_WIDTH, GAME_HEIGHT, "cub3d"))
		return (EXIT_FAILURE);
	if (!textures_load(&game))
	{
		ft_putstr_fd("Error: textures_load failed", 2);
		engine_shutdown(&game.eng);
		return (EXIT_FAILURE);
	}
	engine_register_hooks(&game);
	mlx_loop(game.eng.mlx);
	return (EXIT_SUCCESS);
}

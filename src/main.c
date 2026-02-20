/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:00:55 by fsousa            #+#    #+#             */
/*   Updated: 2026/02/19 20:25:34 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
	{
		pinfo("The information entered is invalid. Please enter only the map");
		return (EXIT_SUCCESS);
	}
	ft_bzero(&game, sizeof(game));
	parse(argv[1], &game.eng, &game.world);
	if (!engine_init(&game.eng, GAME_WIDTH, GAME_HEIGHT, "cub3d"))
		return (EXIT_FAILURE);
	engine_register_hooks(&game);

	mlx_loop(game.eng.mlx);
	return (EXIT_SUCCESS);
}

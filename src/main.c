/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:00:55 by fsousa            #+#    #+#             */
/*   Updated: 2026/02/05 18:07:11 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(void)
{
    t_world world;
    t_engine engine;
    world_fake(&world);
    printf("posicao do player: x: %f, y:%f\n", world.px, world.py);
    engine_init(&engine, GAME_WIDTH, GAME_HEIGHT, "cub3d");
    engine_register_hooks(&engine);
    // draw_test(&engine);
    // mlx_put_image_to_window(engine.mlx, engine.win, engine.frame.img, 0, 0);
    // dev
    mlx_loop(engine.mlx);
    return 0;
}
#include "cub3d.h"

int engine_tick(void *param)
{
     t_game *game;

    game = (t_game *)param;
    if (!game)
        return (0);
    if (!game->eng.running)
    {
        engine_shutdown(&game->eng);
        exit(0);
    }
    draw_test(&game->eng);
    mlx_put_image_to_window(game->eng.mlx, game->eng.win, game->eng.frame.img, 0, 0);
    return (0);
}
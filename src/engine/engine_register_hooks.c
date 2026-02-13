#include "cub3d.h"

void engine_register_hooks(t_game *game)
{
    mlx_hook(game->eng.win, 2, 1L << 0, on_key_press,game);
      mlx_hook(game->eng.win, 3, 1L << 1, on_key_release,game);
    mlx_hook(game->eng.win, 17, 0, on_destroy, game);
    mlx_loop_hook(game->eng.mlx, engine_tick, game);
}
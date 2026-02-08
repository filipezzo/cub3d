#include "cub3d.h"

void engine_register_hooks(t_engine *e)
{
    mlx_hook(e->win, 2, 1L << 0, on_key_press, e);
    mlx_hook(e->win, 17, 0, on_destroy, e);
    mlx_loop_hook(e->mlx, engine_tick, e);
}
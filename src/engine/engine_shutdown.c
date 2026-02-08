#include "cub3d.h"

void engine_shutdown(t_engine *e)
{
    if (e->frame.img)
    {
        mlx_destroy_image(e->mlx, e->frame.img);
        e->frame.img = NULL;
    }
    if (e->win)
    {
        mlx_destroy_window(e->mlx, e->win);
        e->win = NULL;
    }
    if (e->mlx)
    {
        mlx_destroy_display(e->mlx);
        free(e->mlx);
        e->mlx = NULL;
    }
}
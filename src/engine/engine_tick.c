#include "cub3d.h"

int engine_tick(void *param)
{
    t_engine *e;

    e = (t_engine *)param;
    if (!e)
        return (0);
    if (!e->running)
    {
        engine_shutdown(e);
        exit(0);
    }
    draw_test(e);
    mlx_put_image_to_window(e->mlx, e->win, e->frame.img, 0, 0);
    return (0);
}
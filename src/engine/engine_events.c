#include "cub3d.h"

int on_key_press(int keycode, void *param)
{
    t_engine *e;

    e = (t_engine *)param;
    if (!e)
        return (0);
    if (keycode == KEY_ESC)
        e->running = FALSE;
    return (0);
}

int on_destroy(void *param)
{
    t_engine *e;

    e = (t_engine *)param;
    if (!e)
        return (0);
    e->running = FALSE;
    return 0;
}
#include "cub3d.h"

int on_key_press(int keycode, void *param)
{
    t_game *game;

    game = (t_game *)param;
    if (!game)
        return (0);
    if (keycode == KEY_ESC)
        game->eng.running = FALSE;
    else if (keycode == KEY_W)
        game->in.w = TRUE;
    else if (keycode == KEY_A)
        game->in.a = TRUE;
    else if (keycode == KEY_S)
        game->in.s = TRUE;
    else if (keycode == KEY_D)
        game->in.d = TRUE;
    else if (keycode == KEY_ARROW_LEFT)
        game->in.left = TRUE;  
    else if (keycode == KEY_ARROW_RIGHT)
        game->in.right = TRUE;  
    return (0);
}

int on_key_release(int keycode, void *param)
{
    t_game *game;

    game = (t_game *)param;
    if (!game)
        return (0);
    if (keycode == KEY_W)
        game->in.w = FALSE;
    else if (keycode == KEY_A)
        game->in.a = FALSE;
    else if (keycode == KEY_S)
        game->in.s = FALSE;
    else if (keycode == KEY_D)
        game->in.d = FALSE;
    else if (keycode == KEY_ARROW_LEFT)
        game->in.left = FALSE;  
    else if (keycode == KEY_ARROW_RIGHT)
        game->in.right = FALSE;  
    return (0);
}

int on_destroy(void *param)
{
    t_game *game;

    game = (t_game *)param;
    if (!game)
        return (0);
    game->eng.running = FALSE;
    return (0);
}
#include "cub3d.h"

void draw_test(t_engine *e)
{
    int x;
    int y;

    y = 0;
    while (y < e->frame.h)
    {
        x = 0;
        while (x < e->frame.w)
        {
            if (y < e->frame.h / 2)
                put_pixel(&e->frame, x, y, 0x00FF0000);
            else
                put_pixel(&e->frame, x, y, 0x0000FF00);
            x++;
        }
        y++;
    }
}
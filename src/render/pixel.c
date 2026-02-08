#include "cub3d.h"

void put_pixel(t_data *img, int x, int y, uint32_t color)
{
    char *dst;

    if (!img || !img->addr)
        return;
    if (x < 0 || y < 0 || x >= img->w || y >= img->h)
        return;
    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(uint32_t *)dst = color;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 10:59:17 by fsousa            #+#    #+#             */
/*   Updated: 2026/02/12 17:58:50 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include "../libs/mlx/mlx.h"
#include <math.h>
#include <stdint.h>

#define KEY_ESC 65307
#define KEY_ARROW_LEFT  65361
#define KEY_ARROW_RIGHT 65363
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define TEX_N 0
#define TEX_S 1
#define TEX_W 2
#define TEX_E 3
#define TEX_COUNT 4
#define GAME_WIDTH 720
#define GAME_HEIGHT 400
#define MOVE 0.05;
#define ROT 0.04;

typedef struct s_world
{
    // nosso mapa - LEMBRE-SE QUE O Y CRESCE PARA BAIXO
    char **grid;
    // dimensoes do mapa (n col e n rows)
    int w;
    int h;
    // posicao do player
    double px;
    double py;
    // direçao (dir) - para onde o player olha (VETOR)
    double dir_x;
    double dir_y;
    // vetor do plano da câmera (segredo pro FOV)
    double plane_x;
    double plane_y;
    // cores do chao e teto
    uint32_t floor_rgb;
    uint32_t ceil_rgb;
    // array de 4 strings para as texturas N/S/W/E
    char *tex_path[TEX_COUNT];

} t_world; // MAPA + PLAYER + VISUALS.

typedef struct s_data
{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
    int w;
    int h;
} t_data;

typedef struct s_engine
{
    void *mlx;
    void *win;
    int win_w;
    int win_h;
    t_data frame;
    t_bool running;
} t_engine;

typedef struct s_input
{
 t_bool w;
 t_bool a;
 t_bool s;
 t_bool d;
 t_bool left;
 t_bool right;
} t_input;

typedef struct s_game
{
	t_engine eng;
	t_world  world;
	t_input  in;
}	t_game;

void world_fake(t_world *out);
void put_pixel(t_data *img, int x, int y, uint32_t color);
void draw_test(t_engine *e);
int engine_init(t_engine *e, int w, int h, const char *title);
int engine_tick(void *param);
void engine_shutdown(t_engine *e);
void engine_register_hooks(t_game *game);
int on_key_press(int keycode, void *param);
int on_key_release(int keycode, void *param);
int on_destroy(void *param);

#endif
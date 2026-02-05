/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 10:59:17 by fsousa            #+#    #+#             */
/*   Updated: 2026/02/05 18:03:15 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include "../libs/mlx/mlx.h"
#include <stdint.h>


# define TEX_N 0
# define TEX_S 1
# define TEX_W 2
# define TEX_E 3
# define TEX_COUNT 4
# define GAME_WIDTH 320
# define GAME_HEIGHT 200

typedef struct s_world
{
     //nosso mapa - LEMBRE-SE QUE O Y CRESCE PARA BAIXO
    char **grid;
    //dimensoes do mapa (n col e n rows)
    int w;
    int h;
    //posicao do player
    double px;
    double py;
    //direçao (dir) - para onde o player olha (VETOR)
    double dir_x;
    double dir_y;
    // vetor do plano da câmera (segredo pro FOV)
    double plane_x;
    double plane_y;
    //cores do chao e teto
    uint32_t floor_rgb;
    uint32_t ceil_rgb;
    //array de 4 strings para as texturas N/S/W/E
    char *tex_path[TEX_COUNT];

} t_world; //MAPA + PLAYER + VISUALS.

void world_fake(t_world *out);


#endif
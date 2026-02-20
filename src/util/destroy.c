/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 23:10:22 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/20 01:31:18 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_world(t_engine *engine, t_world *world)
{
	destroy_cmtx_rev(world->grid, world->h);
	mlx_destroy_image(engine->mlx, world->texs.n->img);
	mlx_destroy_image(engine->mlx, world->texs.s->img);
	mlx_destroy_image(engine->mlx, world->texs.e->img);
	mlx_destroy_image(engine->mlx, world->texs.w->img);
	ft_memset(world, 0, sizeof(t_world));
}

void	destroy_engine(t_engine *engine)
{
	mlx_destroy_window(engine->mlx, engine->win);
	mlx_destroy_display(engine->mlx);
}

void	cleanup(t_engine *engine, t_world *world)
{
	destroy_world(engine, world);
	destroy_engine(engine);
}

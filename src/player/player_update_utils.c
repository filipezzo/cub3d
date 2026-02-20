/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:41:15 by fsousa            #+#    #+#             */
/*   Updated: 2026/02/20 14:41:30 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	build_move_vec(double v[2], t_world *w, t_input *in)
{
	v[0] = 0.0;
	v[1] = 0.0;
	if (in->w && !in->s)
	{
		v[0] += w->dir_x;
		v[1] += w->dir_y;
	}
	else if (in->s && !in->w)
	{
		v[0] -= w->dir_x;
		v[1] -= w->dir_y;
	}
	if (in->d && !in->a)
	{
		v[0] += -w->dir_y;
		v[1] += w->dir_x;
	}
	else if (in->a && !in->d)
	{
		v[0] -= -w->dir_y;
		v[1] -= w->dir_x;
	}
}

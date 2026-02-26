/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:30:00 by fsousa            #+#    #+#             */
/*   Updated: 2026/02/20 12:49:25 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t	tex_get_pixel(t_data *img, int x, int y)
{
	char	*dst;

	if (!img || !img->addr)
		return (0);
	if (x < 0 || y < 0 || x >= img->w || y >= img->h)
		return (0);
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(uint32_t *)dst);
}

int	ray_tex_id(t_ray *r)
{
	if (r->side == 0)
	{
		if (r->step_x == 1)
			return (TEX_E);
		return (TEX_W);
	}
	if (r->step_y == 1)
		return (TEX_S);
	return (TEX_N);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_cmtx_rev.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:17:56 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/20 22:55:17 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_cmtx_rev(char **cmtx, int i)
{
	if (!cmtx || i < 0)
		return ;
	while (i > 0)
	{
		if (cmtx[i - 1])
			free(cmtx[i - 1]);
		i--;
	}
	free(cmtx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pinfo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:51:42 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/19 20:07:10 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pinfo(const char *msg)
{
	if (!msg || !*msg)
		return ;
	ft_putstr_fd("[info] ", STDOUT_FILENO);
	ft_putstr_fd(msg, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
}

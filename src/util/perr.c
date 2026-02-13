/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 13:34:16 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/13 13:37:02 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	perr(char *msg)
{
	ft_putstr_fd("[error] ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

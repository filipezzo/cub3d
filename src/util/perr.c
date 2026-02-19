/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 13:34:16 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/19 15:49:11 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	perr(const char *msg)
{
	ft_putstr_fd("[error] ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

t_bool	perr_failed(const char *msg)
{
	perr(msg);
	return (FALSE);
}

void	perr_exit(const char *msg, int status_code)
{
	perr(msg);
	exit(status_code);
}

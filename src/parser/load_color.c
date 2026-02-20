/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:42:58 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/20 01:35:30 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		get_color(char **pvt);
static t_bool	is_valid_colors(int red, int green, int blue);

t_bool	load_color(const char *str, uint32_t *color)
{
	int		red;
	int		green;
	int		blue;
	char	*pvt;

	*color = 0U;
	if (!str)
		return (perr_failed("No color was specified"));
	pvt = (char *)str;
	red = get_color(&pvt);
	green = get_color(&pvt);
	blue = get_color(&pvt);
	if (!is_valid_colors(red, green, blue))
		return (perr_failed("The colors entered are invalid"));
	*color = (uint32_t)(red << 16 | green << 8 | blue);
	return (TRUE);
}

static int	get_color(char **pvt)
{
	int	color;

	if (!pvt || !*pvt || !**pvt)
		return (-1);
	color = -1;
	while (**pvt && (ft_isspace(**pvt) || **pvt == 44))
		(*pvt)++;
	if (!ft_isdigit(**pvt))
		return (-1);
	color = ft_atoi(*pvt);
	while (**pvt && ft_isdigit(**pvt))
		(*pvt)++;
	return (color);
}

static t_bool	is_valid_colors(int red, int green, int blue)
{
	if ((red | green | blue) & ~0xFF)
		return (FALSE);
	return (TRUE);
}

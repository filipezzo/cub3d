/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:42:58 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/12 12:00:07 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		get_color(char **pvt);
static t_bool	is_valid_colors(int red, int green, int blue);

uint32_t	parse_rgb(const char *str)
{
	int		red;
	int		green;
	int		blue;
	char	*pvt;

	if (!str)
		return (0U);
	pvt = str;
	red = get_color(&pvt);
	green = get_color(&pvt);
	blue = get_color(&pvt);
	if (!is_valid_colors(red, green, blue))
		return (0U);
	return ((uint32_t)(red << 16 | green << 8 | blue));
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
	return (-1);
}

static t_bool	is_valid_colors(int red, int green, int blue)
{
	if ((red | green | blue) & ~0xFF)
		return (FALSE);
	return (TRUE);
}

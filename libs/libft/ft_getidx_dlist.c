/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getidx_dlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 01:42:55 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/20 01:52:08 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_getidx_dlist(t_dlist *list, t_bnode *node)
{
	size_t	i;
	t_bnode	*aux;

	if (!list || !node)
		return (0);
	i = 0;
	aux = list->head;
	while (aux && aux->data != node->data)
	{
		i++;
		aux = aux->right;
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grab_item.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 04:03:19 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/29 22:36:08 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_grab_item(t_data *data, int item_idx)
{
	t_tile	tile;

	tile = data->items[item_idx];
	if (tile.type)
		return ;
	data->items[item_idx].type = 1;
	data->items_collected++;
	if (data->items_collected == data->items_count)
		ft_open_portal(data);
}

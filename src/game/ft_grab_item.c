/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grab_item.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 04:03:19 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/28 11:00:28 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_grab_item(t_data *data, int item_idx)
{
	t_tile	tile;
	t_vec2	pos;

	tile = data->items[item_idx];
	if (tile.type)
		return ;
	data->items[item_idx].type = 1;
	data->items_collected++;
	if (data->items_collected == data->items_count)
	{
		data->can_exit = TRUE;
		pos = (t_vec2){0, 0};
		while (pos.y < data->map_height)
		{
			pos.x = 0;
			while (pos.x < data->map_width)
			{
				if (data->map[pos.y][pos.x].type == TYPE_EXIT)
				{
					data->map[pos.y][pos.x].asset_idx = 7;
					data->map[pos.y][pos.x].has_changed = TRUE;
				}
				pos.x++;
			}
			pos.y++;
		}
	}
}

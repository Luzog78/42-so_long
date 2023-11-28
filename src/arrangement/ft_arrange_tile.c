/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrange_tile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 06:29:59 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/28 11:12:19 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_arrange_tile(t_data *data, t_vec2 point)
{
	char	type;

	data->map[point.y][point.x].item_idx = -1;
	type = data->map[point.y][point.x].type;
	if (type == TYPE_WALL)
		data->map[point.y][point.x].asset_idx = ft_arrange_wall(data, point);
	else if (type == TYPE_ITEM)
	{
		data->map[point.y][point.x].asset_idx = 0;
		data->map[point.y][point.x].item_idx = data->items_collected;
		data->items[data->items_collected].asset_idx = 3;
		data->items[data->items_collected].curr_frame = 0;
		data->items[data->items_collected].has_changed = TRUE;
		data->items_collected++;
	}
	else if (type == TYPE_ENTRY)
		data->map[point.y][point.x].asset_idx = 4;
	else if (type == TYPE_EXIT)
		data->map[point.y][point.x].asset_idx = 6;
	else
		data->map[point.y][point.x].asset_idx = 0;
	data->map[point.y][point.x].curr_frame = 0;
	data->map[point.y][point.x].has_changed = TRUE;
}

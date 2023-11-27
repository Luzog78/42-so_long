/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrange_tile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 06:29:59 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/27 06:23:33 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_arrange_tile(t_data *data, t_vec2 point)
{
	char	type;

	type = data->map[point.y][point.x].type;
	if (type == TYPE_WALL)
		data->map[point.y][point.x].asset_idx = 0;
	else if (type == TYPE_ITEM)
	{
		data->map[point.y][point.x].asset_idx = 1;
		data->map[point.y][point.x].item_idx = data->items_collected;
		data->items[data->items_collected].asset_idx = 2;
		data->items[data->items_collected].curr_frame = 0;
		data->items[data->items_collected].has_changed = TRUE;
		data->items_collected++;
	}
	else if (type == TYPE_EXIT)
		data->map[point.y][point.x].asset_idx = 3;
	else
		data->map[point.y][point.x].asset_idx = 1;
	data->map[point.y][point.x].curr_frame = 0;
	data->map[point.y][point.x].has_changed = TRUE;
}

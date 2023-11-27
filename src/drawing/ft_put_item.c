/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_item.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 03:10:32 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/27 03:53:50 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_item(t_data *data, t_vec2 point, int item_tile_idx)
{
	t_tile	tile;
	t_frame	frame;

	tile = data->items[item_tile_idx];
	frame = data->assets[tile.asset_idx].frames[tile.curr_frame];
	ft_put_blend_frame(data, &frame,
		(t_vec2){point.x * TILE_SIZE, point.y * TILE_SIZE}, (t_vec2){0, 0});
}

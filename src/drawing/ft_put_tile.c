/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_tile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 06:20:23 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/27 04:06:21 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_tile(t_data *data, t_vec2 point)
{
	t_tile	tile;
	t_frame	frame;

	tile = data->map[point.y][point.x];
	if (!tile.has_changed)
		return ;
	frame = data->assets[tile.asset_idx].frames[tile.curr_frame];
	mlx_put_image_to_window(data->mlx, data->mlx_win, frame.img,
		point.x * TILE_SIZE, point.y * TILE_SIZE);
	data->map[point.y][point.x].has_changed = FALSE;
	if (tile.type == TYPE_ITEM)
		ft_put_item(data, point, tile.item_idx);
}

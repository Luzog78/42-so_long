/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_mob.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 06:49:40 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/27 12:56:34 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	ft_move_mob(t_data *data, t_mob *mob)
{
	t_vec2	new_pos;
	t_tile	tile;

	mob->tile.has_changed = TRUE;
	new_pos = mob->pos;
	data->map[new_pos.y][new_pos.x].has_changed = TRUE;
	if (mob->dir == DIR_UP)
		new_pos.y--;
	else if (mob->dir == DIR_DOWN)
		new_pos.y++;
	else if (mob->dir == DIR_LEFT)
		new_pos.x--;
	else if (mob->dir == DIR_RIGHT)
		new_pos.x++;
	if (new_pos.x < 0 || new_pos.x >= data->map_width
		|| new_pos.y < 0 || new_pos.y >= data->map_height)
		return (FALSE);
	tile = data->map[new_pos.y][new_pos.x];
	if (tile.type == TYPE_WALL)
		return (FALSE);
	if (tile.type == TYPE_ITEM)
		data->map[new_pos.y][new_pos.x].has_changed = TRUE;
	mob->smoothing.end = new_pos;
	mob->smoothing.vec = (t_vec2){(new_pos.x - mob->pos.x) * TILE_SIZE,
		(new_pos.y - mob->pos.y) * TILE_SIZE};
	mob->smoothing.tile1 = &data->map[mob->pos.y][mob->pos.x];
	mob->smoothing.tile2 = &data->map[new_pos.y][new_pos.x];
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 01:58:03 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/28 11:02:33 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_end_smoothing(t_data *data, t_vec2 new_pos, t_tile tile);

void	ft_move_player(t_data *data, t_direction direction)
{
	t_vec2	new_pos;
	t_tile	tile;

	if (!data->can_move)
		return ;
	data->player_direction = direction;
	data->player_tile.has_changed = TRUE;
	new_pos = data->player;
	data->map[new_pos.y][new_pos.x].has_changed = TRUE;
	if (direction == DIR_UP)
		new_pos.y--;
	else if (direction == DIR_DOWN)
		new_pos.y++;
	else if (direction == DIR_LEFT)
		new_pos.x--;
	else if (direction == DIR_RIGHT)
		new_pos.x++;
	if (new_pos.x < 0 || new_pos.x >= data->map_width
		|| new_pos.y < 0 || new_pos.y >= data->map_height)
		return ;
	tile = data->map[new_pos.y][new_pos.x];
	if (tile.type == TYPE_WALL)
		return ;
	ft_end_smoothing(data, new_pos, tile);
}

static void	ft_end_smoothing(t_data *data, t_vec2 new_pos, t_tile tile)
{
	data->moves++;
	data->can_move = FALSE;
	data->smoothing.end = new_pos;
	data->smoothing.vec = (t_vec2){(new_pos.x - data->player.x) * TILE_SIZE,
		(new_pos.y - data->player.y) * TILE_SIZE};
	data->smoothing.tile1 = &data->map[data->player.y][data->player.x];
	data->smoothing.tile2 = &data->map[new_pos.y][new_pos.x];
}

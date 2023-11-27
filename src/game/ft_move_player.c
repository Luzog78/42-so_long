/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 01:58:03 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/27 05:21:42 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_player(t_data *data, t_direction direction)
{
	t_vec2	new_pos;
	t_tile	tile;

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
	if (tile.type == TYPE_ITEM)
	{
		ft_grab_item(data, tile.item_idx);
		data->map[new_pos.y][new_pos.x].has_changed = TRUE;
	}
	if (tile.type == TYPE_EXIT && data->can_exit)
		ft_game_quit(data);
	data->player = new_pos;
	data->moves++;
}

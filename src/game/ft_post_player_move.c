/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_post_player_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 07:56:45 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/29 17:33:14 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_post_player_move(t_data *data)
{
	t_mob	*mob;

	data->player = data->smoothing.end;
	if (data->smoothing.tile2->type == TYPE_ITEM)
	{
		ft_grab_item(data, data->smoothing.tile2->item_idx);
		data->map[data->player.y][data->player.x].has_changed = TRUE;
	}
	if (data->smoothing.tile2->type == TYPE_EXIT && data->can_exit)
		ft_game_quit(data);
	mob = data->mobs;
	while (mob)
	{
		if (mob->pos.x == data->player.x
			&& mob->pos.y == data->player.y)
			ft_game_quit(data);
		mob = mob->next;
	}
	data->player_tile.curr_frame = 0;
	data->can_move = TRUE;
	ft_put_score(data);
	write(1, "Moves: ", 7);
	ft_put_ull(data->moves);
	write(1, "\n", 1);
}

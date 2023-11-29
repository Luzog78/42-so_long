/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 07:14:05 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/29 07:41:27 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_game_loop(t_data *data)
{
	t_mob	*mob;
	t_vec2	pos;
	t_tile	*tile;

	if (data->frames % 200 == 0)
	{
		if (data->smoothing.vec.x != 0 || data->smoothing.vec.y != 0)
		{
			ft_smooth_player_move(data, 1);
			if (data->frames % 300 == 0)
				data->player_tile.curr_frame = (data->player_tile.curr_frame + 1)
					% data->player_assets[data->player_direction].tot_frames;
		}
		mob = data->mobs;
		while (mob)
		{
			if (mob->smoothing.vec.x != 0 || mob->smoothing.vec.y != 0)
			{
				ft_smooth_mob_move(data, mob, 1);
				if (data->frames % 300 == 0)
					mob->tile.curr_frame = (mob->tile.curr_frame + 1)
						% data->assets[mob->tile.asset_idx + mob->dir].tot_frames;
			}
			mob = mob->next;
		}
	}
	if (data->frames % 5000 == 0 && data->frames != 0)
	{
		pos = (t_vec2){0, 0};
		while (pos.y < data->map_height)
		{
			pos.x = 0;
			while (pos.x < data->map_width)
			{
				tile = &data->map[pos.y][pos.x];
				if (data->assets[tile->asset_idx].tot_frames > 1)
				{
					tile->curr_frame = (tile->curr_frame + 1)
						% data->assets[tile->asset_idx].tot_frames;
					tile->has_changed = TRUE;
				}
				if (tile->item_idx != -1 && !data->items[tile->item_idx].type)
				{
					tile->has_changed = TRUE;
					tile = &data->items[tile->item_idx];
					if (data->assets[tile->asset_idx].tot_frames > 1)
					{
						tile->curr_frame = (tile->curr_frame + 1)
							% data->assets[tile->asset_idx].tot_frames;
						tile->has_changed = TRUE;
					}
				}
				pos.x++;
			}
			pos.y++;
		}
	}
	if (data->frames % 25000 == 0 && data->frames != 0)
		ft_move_mobs(data);
	ft_put_tiles(data);
	ft_put_mobs(data);
	ft_put_player(data);
	if (data->frames % 100 == 0)
		ft_put_score(data);
	data->frames++;
	printf("frames: %llu\n", data->frames);
	return (0);
}

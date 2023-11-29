/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 07:14:05 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/30 00:14:20 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_handle_smoothing(t_data *data);
static void	ft_handle_common_animations(t_data *data, t_tile *tile);
static void	ft_handle_items_animations(t_data *data, t_tile *tile);
static void	ft_handle_mob_overlapping(t_data *data, t_tile *tile, t_vec2 pos);

int	ft_game_loop(t_data *data)
{
	t_vec2	pos;

	if (data->frames == 1)
		ft_put_score(data);
	ft_handle_smoothing(data);
	if (data->frames % (60 * FRAME_RATE) == 0 && data->frames != 0)
	{
		pos.y = -1;
		while (++pos.y < data->map_height)
		{
			pos.x = -1;
			while (++pos.x < data->map_width)
			{
				ft_handle_common_animations(data, &data->map[pos.y][pos.x]);
				ft_handle_items_animations(data, &data->map[pos.y][pos.x]);
				ft_handle_mob_overlapping(data, &data->map[pos.y][pos.x], pos);
			}
		}
	}
	if (data->frames % (115 * FRAME_RATE) == 0 && data->frames != 0)
		ft_move_mobs(data);
	ft_put_tiles(data);
	ft_put_mobs(data);
	ft_put_player(data);
	return (data->frames++);
}

static void	ft_handle_smoothing(t_data *dt)
{
	t_mob	*mob;

	if (dt->frames % (2 * FRAME_RATE) == 0)
	{
		if (dt->smoothing.vec.x != 0 || dt->smoothing.vec.y != 0)
		{
			ft_smooth_player_move(dt, 2);
			if (dt->frames % (6 * FRAME_RATE) == 0)
				dt->player_tile.curr_frame = (dt->player_tile.curr_frame + 1)
					% dt->player_assets[dt->player_direction].tot_frames;
		}
		mob = dt->mobs;
		while (mob)
		{
			if (mob->smoothing.vec.x != 0 || mob->smoothing.vec.y != 0)
			{
				ft_smooth_mob_move(dt, mob, 2);
				if (dt->frames % (6 * FRAME_RATE) == 0)
					mob->tile.curr_frame = (mob->tile.curr_frame + 1)
						% dt->assets[mob->tile.asset_idx + mob->dir].tot_frames;
			}
			mob = mob->next;
		}
	}
}

static void	ft_handle_common_animations(t_data *data, t_tile *tile)
{
	if (data->assets[tile->asset_idx].tot_frames > 1)
	{
		tile->curr_frame = (tile->curr_frame + 1)
			% data->assets[tile->asset_idx].tot_frames;
		tile->has_changed = TRUE;
	}
}

static void	ft_handle_items_animations(t_data *data, t_tile *tile)
{
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
}

static void	ft_handle_mob_overlapping(t_data *data, t_tile *tile, t_vec2 pos)
{
	t_mob	*mob;

	if (tile->has_changed)
	{
		mob = data->mobs;
		while (mob)
		{
			if (mob->pos.x == pos.x && mob->pos.y == pos.y)
				mob->tile.has_changed = TRUE;
			mob = mob->next;
		}
	}
}

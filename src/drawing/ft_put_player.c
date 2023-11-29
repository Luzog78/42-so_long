/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 06:20:23 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/29 22:35:38 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_vec2	ft_get_ptn_win(t_vec2 point, t_data *data);

void	ft_put_player(t_data *data)
{
	t_tile	tile;
	t_frame	frame;
	t_vec2	point;
	t_vec2	ptn_win;

	tile = data->player_tile;
	if (!tile.has_changed)
		return ;
	frame = data->player_assets[data->player_direction].frames[tile.curr_frame];
	point = data->player;
	ptn_win = ft_get_ptn_win(point, data);
	ft_put_blend_frame(data, &frame, ptn_win,
		(t_vec2){(TILE_SIZE - PLAYER_SIZE) / 2, (TILE_SIZE - PLAYER_SIZE) / 2});
	data->player_tile.has_changed = FALSE;
}

static t_vec2	ft_get_ptn_win(t_vec2 point, t_data *data)
{
	t_vec2	ptn_win;

	ptn_win = (t_vec2){point.x * TILE_SIZE, point.y * TILE_SIZE};
	if (data->smoothing.vec.x != 0 || data->smoothing.vec.y != 0)
	{
		if (data->smoothing.vec.x < 0)
			ptn_win.x -= TILE_SIZE + data->smoothing.vec.x;
		else if (data->smoothing.vec.x > 0)
			ptn_win.x += TILE_SIZE - data->smoothing.vec.x;
		if (data->smoothing.vec.y < 0)
			ptn_win.y -= TILE_SIZE + data->smoothing.vec.y;
		else if (data->smoothing.vec.y > 0)
			ptn_win.y += TILE_SIZE - data->smoothing.vec.y;
	}
	return (ptn_win);
}

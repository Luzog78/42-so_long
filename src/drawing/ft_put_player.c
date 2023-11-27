/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 06:20:23 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/27 08:52:52 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_player(t_data *data)
{
	t_tile	tile;
	t_frame	frame;
	t_vec2	point;
	t_tile	base;
	t_vec2	ptn_win;

	tile = data->player_tile;
	if (!tile.has_changed)
		return ;
	frame = data->player_assets[data->player_direction].frames[tile.curr_frame];
	point = data->player;
	base = data->map[point.y][point.x];
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
	ft_put_blend_frame(data, &frame,
		ptn_win,
		(t_vec2){(TILE_SIZE - PLAYER_SIZE) / 2, (TILE_SIZE - PLAYER_SIZE) / 2});
	data->player_tile.has_changed = FALSE;
}

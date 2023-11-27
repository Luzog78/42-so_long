/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 06:20:23 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/27 03:46:13 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_player(t_data *data)
{
	t_tile	tile;
	t_frame	frame;
	t_vec2	point;
	t_tile	base;

	if (!tile.has_changed)
		return ;
	tile = data->player_tile;
	frame = data->player_assets[data->player_direction].frames[tile.curr_frame];
	point = data->player;
	base = data->map[point.y][point.x];
	ft_put_blend_frame(data, &frame,
		(t_vec2){point.x * TILE_SIZE, point.y * TILE_SIZE},
		(t_vec2){(TILE_SIZE - PLAYER_SIZE) / 2, (TILE_SIZE - PLAYER_SIZE) / 2});
	data->player_tile.has_changed = FALSE;
}

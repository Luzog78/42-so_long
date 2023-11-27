/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_mob.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 06:38:53 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/27 06:42:57 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_mob(t_data *data, t_mob *mob)
{
	t_tile	tile;
	t_frame	frame;
	t_vec2	point;
	t_tile	base;

	tile = mob->tile;
	if (!tile.has_changed)
		return ;
	frame = data->assets[tile.asset_idx + mob->dir].frames[tile.curr_frame];
	point = mob->pos;
	base = data->map[point.y][point.x];
	ft_put_blend_frame(data, &frame,
		(t_vec2){point.x * TILE_SIZE, point.y * TILE_SIZE},
		(t_vec2){(TILE_SIZE - MOB_SIZE) / 2, (TILE_SIZE - MOB_SIZE) / 2});
	mob->tile.has_changed = FALSE;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_mob.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 06:38:53 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/29 22:35:18 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_vec2	ft_get_ptn_win(t_vec2 point, t_mob *mob);

void	ft_put_mob(t_data *data, t_mob *mob)
{
	t_tile	tile;
	t_frame	frame;
	t_vec2	point;
	t_vec2	ptn_win;

	tile = mob->tile;
	if (!tile.has_changed)
		return ;
	frame = data->assets[tile.asset_idx + mob->dir].frames[tile.curr_frame];
	point = mob->pos;
	ptn_win = ft_get_ptn_win(point, mob);
	ft_put_blend_frame(data, &frame, ptn_win,
		(t_vec2){(TILE_SIZE - MOB_SIZE) / 2, (TILE_SIZE - MOB_SIZE) / 2});
	mob->tile.has_changed = FALSE;
}

static t_vec2	ft_get_ptn_win(t_vec2 point, t_mob *mob)
{
	t_vec2	ptn_win;

	ptn_win = (t_vec2){point.x * TILE_SIZE, point.y * TILE_SIZE};
	if (mob->smoothing.vec.x != 0 || mob->smoothing.vec.y != 0)
	{
		if (mob->smoothing.vec.x < 0)
			ptn_win.x -= TILE_SIZE + mob->smoothing.vec.x;
		else if (mob->smoothing.vec.x > 0)
			ptn_win.x += TILE_SIZE - mob->smoothing.vec.x;
		if (mob->smoothing.vec.y < 0)
			ptn_win.y -= TILE_SIZE + mob->smoothing.vec.y;
		else if (mob->smoothing.vec.y > 0)
			ptn_win.y += TILE_SIZE - mob->smoothing.vec.y;
	}
	return (ptn_win);
}

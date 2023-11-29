/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_post_mob_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:02:20 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/30 00:19:28 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_post_mob_move(t_data *data, t_mob *mob)
{
	if ((mob->pos.x == data->player.x
			&& mob->pos.y == data->player.y)
		|| (mob->smoothing.end.x == data->player.x
			&& mob->smoothing.end.y == data->player.y))
		ft_game_loose(data);
	mob->pos = mob->smoothing.end;
	mob->tile.curr_frame = 0;
}

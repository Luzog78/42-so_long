/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_post_player_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 07:56:45 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/27 12:53:52 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_post_player_move(t_data *data)
{
	t_mob	*mob;

	data->player = data->smoothing.end;
	mob = data->mobs;
	while (mob)
	{
		if (mob->pos.x == data->player.x
			&& mob->pos.y == data->player.y)
			ft_game_quit(data);
		mob = mob->next;
	}
	data->can_move = TRUE;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 07:14:05 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/27 15:13:24 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_game_loop(t_data *data)
{
	t_mob	*mob;

	if (data->frames % 300 == 0)
	{
		if (data->smoothing.vec.x != 0 || data->smoothing.vec.y != 0)
			ft_smooth_player_move(data, 4);
		mob = data->mobs;
		while (mob)
		{
			if (mob->smoothing.vec.x != 0 || mob->smoothing.vec.y != 0)
				ft_smooth_mob_move(data, mob, 4);
			mob = mob->next;
		}
	}
	if (data->frames % 30000 == 0 && data->frames != 0)
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

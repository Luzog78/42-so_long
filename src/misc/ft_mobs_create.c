/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mobs_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 06:14:50 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/29 18:16:50 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mob	*ft_mobs_create(t_data *data, t_vec2 pos, t_mob_type type, int asset)
{
	t_mob	*mob;

	mob = malloc(sizeof(t_mob));
	if (!mob)
	{
		ft_error(data, "Error: Malloc failed\n");
		ft_game_quit(data);
	}
	mob->type = type;
	mob->pos = pos;
	mob->dir = DIR_DOWN;
	mob->health = 1;
	mob->tile.asset_idx = asset;
	mob->tile.curr_frame = 0;
	mob->tile.has_changed = TRUE;
	mob->smoothing.vec = (t_vec2){0, 0};
	mob->smoothing.tile1 = NULL;
	mob->smoothing.tile2 = NULL;
	mob->next = NULL;
	return (mob);
}

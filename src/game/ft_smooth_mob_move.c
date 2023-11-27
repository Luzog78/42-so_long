/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smooth_mob_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:00:17 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/27 21:18:06 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_smooth_mob_move(t_data *data, t_mob *mob, int amount)
{
	t_vec2	new_pos;

	if (mob->smoothing.vec.x < 0)
		new_pos.x = mob->smoothing.vec.x + amount;
	else if (mob->smoothing.vec.x > 0)
		new_pos.x = mob->smoothing.vec.x - amount;
	else
		new_pos.x = 0;
	if (mob->smoothing.vec.y < 0)
		new_pos.y = mob->smoothing.vec.y + amount;
	else if (mob->smoothing.vec.y > 0)
		new_pos.y = mob->smoothing.vec.y - amount;
	else
		new_pos.y = 0;
	mob->smoothing.vec = new_pos;
	mob->smoothing.tile1->has_changed = TRUE;
	mob->smoothing.tile2->has_changed = TRUE;
	mob->tile.has_changed = TRUE;
	if (new_pos.x == 0 && new_pos.y == 0)
		ft_post_mob_move(data, mob);
}

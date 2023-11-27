/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smooth_player_move.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 08:05:26 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/27 12:53:52 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_smooth_player_move(t_data *data, int amount)
{
	t_vec2	new_pos;

	if (data->smoothing.vec.x < 0)
		new_pos.x = data->smoothing.vec.x + amount;
	else if (data->smoothing.vec.x > 0)
		new_pos.x = data->smoothing.vec.x - amount;
	else
		new_pos.x = 0;
	if (data->smoothing.vec.y < 0)
		new_pos.y = data->smoothing.vec.y + amount;
	else if (data->smoothing.vec.y > 0)
		new_pos.y = data->smoothing.vec.y - amount;
	else
		new_pos.y = 0;
	data->smoothing.vec = new_pos;
	data->smoothing.tile1->has_changed = TRUE;
	data->smoothing.tile2->has_changed = TRUE;
	data->player_tile.has_changed = TRUE;
	if (new_pos.x == 0 && new_pos.y == 0)
		ft_post_player_move(data);
}

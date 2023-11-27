/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:45:23 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/27 08:54:22 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_data_init(t_data *data)
{
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->assets = NULL;
	data->map = NULL;
	data->map_width = -1;
	data->map_height = 0;
	data->player = (t_vec2){0, 0};
	data->player_direction = DIR_DOWN;
	data->player_assets = NULL;
	data->player_tile.curr_frame = 0;
	data->player_tile.has_changed = TRUE;
	data->smoothing.vec = (t_vec2){0, 0};
	data->can_move = TRUE;
	data->items = NULL;
	data->items_collected = 0;
	data->items_count = 0;
	data->mobs = NULL;
	data->entry = (t_vec2){-1, -1};
	data->exit = (t_vec2){-1, -1};
	data->can_exit = FALSE;
	data->moves = 0;
	data->frames = 0;
}

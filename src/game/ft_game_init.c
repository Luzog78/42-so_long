/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:53:21 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/29 23:55:22 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_game_init(t_data *data)
{
	data->items = ft_calloc(data->items_count, sizeof(t_tile));
	if (!data->items)
		return (ft_error(data, "Error\nCan't allocate memory for items\n"));
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->map_width * TILE_SIZE,
			data->map_height * TILE_SIZE, NAME);
	data->player = data->entry;
	data->player_tile.has_changed = TRUE;
	mlx_do_key_autorepeaton(data->mlx);
	mlx_loop_hook(data->mlx, &ft_game_loop, data);
	mlx_hook(data->mlx_win, ON_DESTROY, 0L, &ft_game_quit, data);
	mlx_hook(data->mlx_win, ON_KEYDOWN, MASK_KEY_PRESS, &ft_game_keydown, data);
	return (0);
}

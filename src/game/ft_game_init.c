/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:53:21 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/24 11:02:21 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_game_init(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, NAME);

	mlx_loop_hook(data->mlx, &ft_game_loop, data);
	mlx_hook(data->mlx_win, ON_DESTROY, 0L, &ft_game_quit, data);
	mlx_hook(data->mlx_win, ON_KEYDOWN, MASK_KEY_PRESS, &ft_game_keydown, data);
}

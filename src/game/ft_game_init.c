/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:53:21 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/22 10:03:38 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_game_init(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, NAME);
	data->frame.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->frame.addr = mlx_get_data_addr(
		data->frame.img, &data->frame.bits_per_pixel,
		&data->frame.width, &data->frame.endian);
	mlx_loop_hook(data->mlx, &ft_game_loop, data);
	mlx_hook(data->mlx_win, ON_DESTROY, 0L, &ft_game_quit, data);
	mlx_hook(data->mlx_win, ON_KEYDOWN, MASK_KEY_PRESS, &ft_game_keydown, data);
}
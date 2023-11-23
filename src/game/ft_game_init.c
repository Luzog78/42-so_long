/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:53:21 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/23 19:09:49 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_game_init(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, NAME);
	data->frame.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->frame.height = HEIGHT;
	data->frame.addr = mlx_get_data_addr(
		data->frame.img, &data->frame.bits_per_pixel,
		&data->frame.width, &data->frame.endian);
	data->img.img = mlx_xpm_file_to_image(data->mlx, "./ru.xpm", &data->img.width, &data->img.height);
	data->img.addr = mlx_get_data_addr(
		data->img.img, &data->img.bits_per_pixel,
		&data->img.width, &data->img.endian);
	mlx_loop_hook(data->mlx, &ft_game_loop, data);
	mlx_hook(data->mlx_win, ON_DESTROY, 0L, &ft_game_quit, data);
	mlx_hook(data->mlx_win, ON_KEYDOWN, MASK_KEY_PRESS, &ft_game_keydown, data);

	data->color = ft_blend(0xaa000000, 0xffff0000);
	// printf("color: %#.8x\n", data->color);
}
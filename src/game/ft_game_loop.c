/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 07:14:05 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/23 21:55:02 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	ft_game_loop(t_data *data)
{
	t_vec2 point;

	ft_draw_raw_rect(&data->frame, (t_vec2){0, 0}, (t_vec2){WIDTH, HEIGHT}, 0xFF000000);
	point = (t_vec2){(data->frames / 10) % (WIDTH - 50), (data->frames / 10) % (HEIGHT - 50)};
	// mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
	ft_draw_frame(&data->frame, &data->img, (t_vec2){0, 0});
	ft_draw_rect(&data->frame, point, (t_vec2){50, 50}, ft_color_progression(data->frames % 5000, 5000));
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->frame.img, 0, 0);
	data->frames++;
	printf("frames: %llu\n", data->frames);
	return (0);
}

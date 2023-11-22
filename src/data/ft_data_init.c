/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:45:23 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/22 10:25:50 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_data_init(t_data *data)
{
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->frame.img = NULL;
	data->frame.addr = NULL;
	data->frame.bits_per_pixel = 0;
	data->frame.width = 0;
	data->frame.endian = 0;
	data->map = NULL;
	data->map_width = 0;
	data->map_height = 0;
	data->player = (t_vec2){0, 0};
	data->can_move = FALSE;
	data->mobs = NULL;
	data->enter = (t_vec2){0, 0};
	data->exit = (t_vec2){0, 0};
	data->can_exit = FALSE;
	data->moves = 0;
	data->frames = 0;
}

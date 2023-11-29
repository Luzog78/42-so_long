/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:52:08 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/29 23:53:23 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_frame(t_data *data, t_frame *drawing, t_vec2 point)
{
	t_vec2	pos;
	char	*dst;

	pos.y = 0;
	while (pos.y < drawing->height)
	{
		pos.x = 0;
		while (pos.x < drawing->width)
		{
			if (point.x + pos.x >= 0 && point.y + pos.y >= 0
				&& point.x + pos.x < data->map_width * TILE_SIZE
				&& point.y + pos.y < data->map_height * TILE_SIZE)
			{
				dst = drawing->addr + (pos.y * drawing->line_size
						+ pos.x * (drawing->bits_per_pixel / 8));
				if ((*(t_ui *) dst) >> 24)
					mlx_pixel_put(data->mlx, data->mlx_win, point.x + pos.x,
						point.y + pos.y, *(t_ui *) dst);
			}
			pos.x++;
		}
		pos.y++;
	}
}

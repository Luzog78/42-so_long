/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_blend_frame.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:52:08 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/29 23:51:10 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_blend_frame(t_data *data, t_frame *drawing,
			t_vec2 point_win, t_vec2 point_offset)
{
	t_vec2	pos;
	char	*dst;
	t_ui	color;

	pos.y = 0;
	while (pos.y < drawing->height)
	{
		pos.x = 0;
		while (pos.x < drawing->width)
		{
			dst = drawing->addr + (pos.y * drawing->line_size
					+ pos.x * (drawing->bits_per_pixel / 8));
			color = *(t_ui *) dst;
			ft_put_blend_pixel(data, (t_vec2){pos.x + point_win.x,
				pos.y + point_win.y}, point_offset, color);
			pos.x++;
		}
		pos.y++;
	}
}

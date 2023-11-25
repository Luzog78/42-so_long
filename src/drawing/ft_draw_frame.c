/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_frame.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:52:08 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/24 00:00:36 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_frame(t_frame *base, t_frame *drawing, t_vec2 point)
{
	t_vec2	pos;
	char	*dst;

	pos.y = 0;
	while (pos.y < drawing->height)
	{
		pos.x = 0;
		while (pos.x < drawing->width)
		{
			if (point.x + pos.x >= 0 && point.x + pos.x < base->width
				&& point.y + pos.y >= 0 && point.y + pos.y < base->height)
			{
				dst = drawing->addr + (pos.y * drawing->width
						+ pos.x * (drawing->bits_per_pixel / 8));
				ft_draw_pixel(base, (t_vec2){point.x + pos.x, point.y + pos.y},
					*(t_ui *) dst);
			}
			pos.x++;
		}
		pos.y++;
	}
}

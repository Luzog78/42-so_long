/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_blend_rect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 07:08:47 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/24 00:03:50 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_blend_rect(t_frame *frame, t_vec2 start,
	t_vec2 size, t_ui color)
{
	int	x;
	int	y;
	int	maxx;
	int	maxy;
	int	minx;

	maxy = ft_max(start.y, start.y + size.y);
	maxx = ft_max(start.x, start.x + size.x);
	minx = ft_min(start.x, start.x + size.x);
	y = ft_min(start.y, start.y + size.y);
	while (y < maxy)
	{
		x = minx;
		while (x < maxx)
		{
			ft_draw_blend_pixel(frame, (t_vec2){x, y}, color);
			x++;
		}
		y++;
	}
}

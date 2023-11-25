/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_blend_pixel.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 06:53:34 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/24 09:43:28 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_blend_pixel(t_frame *frame, t_vec2 point, t_ui color)
{
	char	*dst;
	t_ui	base_color;
	int		color_alpha;
	
	color_alpha = color >> 24;
	if (color >> 24 == 0)
		return ;
	dst = frame->addr + (point.y * frame->line_size
			+ point.x * (frame->bits_per_pixel / 8));
	base_color = *(t_ui *) dst;
	*(t_ui *) dst = ft_blend(color, base_color);
}

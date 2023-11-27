/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 06:53:34 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/27 14:56:54 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_pixel(t_frame *frame, t_vec2 point, t_ui color)
{
	char	*dst;

	dst = frame->addr + (point.y * frame->line_size
			+ point.x * (frame->bits_per_pixel / 8));
	*(t_ui *) dst = color;
}

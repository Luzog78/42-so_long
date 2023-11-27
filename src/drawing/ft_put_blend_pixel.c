/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_blend_pixel.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 06:53:34 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/27 14:56:42 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_blend_pixel(t_data *data, t_vec2 point_win,
			t_vec2 point_offset, t_ui color)
{
	t_tile	base;
	t_frame	*base_frame;
	char	*base_dst;
	t_ui	base_color;
	int		color_alpha;

	base = data->map[point_win.y / TILE_SIZE][point_win.x / TILE_SIZE];
	base_frame = &data->assets[base.asset_idx].frames[base.curr_frame];
	color_alpha = color >> 24;
	if (color_alpha == 0)
		return ;
	base_dst = base_frame->addr + (point_offset.y * base_frame->line_size
			+ point_offset.x * (base_frame->bits_per_pixel / 8));
	base_color = *(t_ui *) base_dst;
	mlx_pixel_put(data->mlx, data->mlx_win, point_win.x + point_offset.x,
		point_win.y + point_offset.y, ft_blend(color, base_color));
}

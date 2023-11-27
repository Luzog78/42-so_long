/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrange_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 06:29:28 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/27 03:38:25 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_arrange_map(t_data *data)
{
	t_vec2	point;

	point.y = 0;
	while (point.y < data->map_height)
	{
		point.x = 0;
		while (point.x < data->map_width)
		{
			ft_arrange_tile(data, point);
			point.x++;
		}
		point.y++;
	}
	data->items_collected = 0;
}

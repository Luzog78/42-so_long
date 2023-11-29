/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_portal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:37:25 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/29 17:38:48 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	ft_open_portal(t_data *data)
{
	t_vec2	pos;

	data->can_exit = TRUE;
	pos = (t_vec2){0, 0};
	while (pos.y < data->map_height)
	{
		pos.x = 0;
		while (pos.x < data->map_width)
		{
			if (data->map[pos.y][pos.x].type == TYPE_EXIT)
			{
				data->map[pos.y][pos.x].asset_idx = 7;
				data->map[pos.y][pos.x].has_changed = TRUE;
			}
			pos.x++;
		}
		pos.y++;
	}
}

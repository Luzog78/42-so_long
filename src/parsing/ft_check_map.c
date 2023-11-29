/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:37:50 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/29 23:33:22 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map(t_data *data)
{
	t_vec2	pos;

	if (data->map_width < 3 || data->map_height < 3)
		return (ft_error(data, "Error\nMap is too small\n"));
	if (data->entry.x == -1)
		return (ft_error(data, "Error\nNo entry point\n"));
	if (data->exit.x == -1)
		return (ft_error(data, "Error\nNo exit point\n"));
	if (data->items_count == 0)
		return (ft_error(data, "Error\nNo collectibles\n"));
	pos = (t_vec2){0, 0};
	while (pos.y < data->map_height)
	{
		pos.x = 0;
		while (pos.x < data->map_width)
		{
			if ((pos.x == 0 || pos.y == 0 || pos.x == data->map_width - 1
					|| pos.y == data->map_height - 1)
				&& data->map[pos.y][pos.x].type != TYPE_WALL)
				return (ft_error(data, "Error\nMap is not closed\n"));
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}

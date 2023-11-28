/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:23:26 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/28 10:51:35 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_parse_char(t_data *data, char c, int i, int j)
{
	if (c == TYPE_ENTRY)
	{
		if (data->entry.x != -1)
			return (ft_error(data, "Error: Multiple entry points\n"));
		data->entry.x = j;
		data->entry.y = i;
	}
	else if (c == TYPE_EXIT)
	{
		if (data->exit.x != -1)
			return (ft_error(data, "Error: Multiple exit points\n"));
		data->exit.x = j;
		data->exit.y = i;
	}
	else if (c == TYPE_ZOMBIE)
		ft_mobs_add_front(&data->mobs, ft_mobs_create(data,
				(t_vec2){j, i}, MOB_ZOMBIE, 8));
	else if (c == TYPE_ITEM)
		data->items_count++;
	else if (!ft_str_contains(TYPES, c))
		return (ft_error(data, "Error: Invalid character in map\n"));
	data->map[i][j].type = c;
	return (0);
}

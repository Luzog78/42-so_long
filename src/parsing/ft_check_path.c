/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:49:49 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/22 19:33:46 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_path(t_data *data)
{
	t_list_vec2	*list;
	t_vec2		pos;

	list = NULL;
	if (!ft_check_dfs(data, data->entry, data->exit, &list))
		return (ft_error(data, "Error: Exit is unreachable\n"));
	pos = (t_vec2){0, 0};
	while (pos.y < data->map_height)
	{
		pos.x = 0;
		while (pos.x < data->map_width)
		{
			list = NULL;
			if (data->map[pos.y][pos.x] == TYPE_ITEM
				&& !ft_check_dfs(data, data->entry, pos, &list))
				return (ft_error(data, "Error: Some items are unreachable\n"));
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}

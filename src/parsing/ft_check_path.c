/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:49:49 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/29 23:33:22 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_clean(t_data *data, t_list_vec2 **list, char *error_msg)
{
	ft_free_list_vec2(list);
	return (ft_error(data, error_msg));
}

int	ft_check_path(t_data *data)
{
	t_list_vec2	*list;
	t_vec2		pos;

	list = NULL;
	if (!ft_check_dfs(data, data->entry, data->exit, &list))
		return (ft_clean(data, &list, "Error\nExit is unreachable\n"));
	ft_free_list_vec2(&list);
	pos = (t_vec2){0, 0};
	while (pos.y < data->map_height)
	{
		pos.x = 0;
		while (pos.x < data->map_width)
		{
			list = NULL;
			if (data->map[pos.y][pos.x].type == TYPE_ITEM
				&& !ft_check_dfs(data, data->entry, pos, &list))
				return (ft_clean(data, &list, "Error\nItem unreachable\n"));
			ft_free_list_vec2(&list);
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}

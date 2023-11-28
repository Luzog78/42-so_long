/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_inverse_dfs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:32:37 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/28 11:17:24 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	ft_check_inverse_dfs(t_data *data, t_vec2 curr,
			t_vec2 to, t_list_vec2 **list)
{
	if (curr.x == to.x && curr.y == to.y)
		return (TRUE);
	if (curr.x < 0 || curr.y < 0
		|| curr.x >= data->map_width
		|| curr.y >= data->map_height
		|| data->map[curr.y][curr.x].type != TYPE_WALL
		|| ft_list_vec2_contains(*list, curr))
		return (FALSE);
	ft_list_vec2_add_front(list, curr);
	return (ft_check_inverse_dfs(data, (t_vec2){curr.x + 1, curr.y}, to, list)
		|| ft_check_inverse_dfs(data, (t_vec2){curr.x - 1, curr.y}, to, list)
		|| ft_check_inverse_dfs(data, (t_vec2){curr.x, curr.y + 1}, to, list)
		|| ft_check_inverse_dfs(data, (t_vec2){curr.x, curr.y - 1}, to, list));
}

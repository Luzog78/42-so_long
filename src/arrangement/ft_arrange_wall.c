/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrange_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:07:22 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/28 11:18:05 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_arrange_wall(t_data *data, t_vec2 pos)
{
	t_list_vec2	*list;
	int			result_asset_idx;

	list = NULL;
	if (ft_check_inverse_dfs(data, pos, (t_vec2){0, 0}, &list))
		result_asset_idx = 1;
	else
		result_asset_idx = 2;
	ft_free_list_vec2(&list);
	return (result_asset_idx);
}

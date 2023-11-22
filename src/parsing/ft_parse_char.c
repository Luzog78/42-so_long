/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:23:26 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/22 19:33:55 by ysabik           ###   ########.fr       */
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
	else if (c == TYPE_ITEM)
		data->items++;
	else if (!ft_str_contains(TYPES, c))
		return (ft_error(data, "Error: Invalid character in map\n"));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand_mob.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:31:06 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/29 17:50:05 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_rand_mob(t_data *data)
{
	int		i;
	t_vec2	pos;

	i = 0;
	ft_calc_difficulty(data);
	while (i < data->difficulty)
	{
		pos = (t_vec2){rand() % data->map_width, rand() % data->map_height};
		if (data->map[pos.y][pos.x].type != TYPE_WALL
			&& data->map[pos.y][pos.x].type != TYPE_ENTRY
			&& sqrt(pow(pos.x - data->entry.x, 2)
				+ pow(pos.y - data->entry.y, 2)) > 3)
		{
			ft_mobs_add_front(&data->mobs, ft_mobs_create(data,
					pos, MOB_ZOMBIE, 8));
			i++;
		}
	}
}

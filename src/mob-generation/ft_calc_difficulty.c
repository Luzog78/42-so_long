/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_difficulty.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:32:26 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/29 22:04:09 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_calc_difficulty(t_data *data)
{
	int	i;
	int	j;
	int	difficulty;

	i = 0;
	difficulty = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j].type != TYPE_WALL)
				difficulty++;
			j++;
		}
		i++;
	}
	if (difficulty < 7)
		difficulty = 0;
	else if (difficulty >= 7 && difficulty < 15)
		difficulty = 1;
	else
		difficulty /= 15;
	data->difficulty = difficulty;
}

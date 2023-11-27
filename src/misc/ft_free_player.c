/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 06:14:17 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/25 12:43:29 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (!data->player_assets)
		return ;
	while (i < 4 && data->player_assets[i].frames)
	{
		j = 0;
		while (j < data->player_assets[i].tot_frames
			&& data->player_assets[i].frames[j].img)
		{
			mlx_destroy_image(data->mlx, data->player_assets[i].frames[j].img);
			j++;
		}
		free(data->player_assets[i].frames);
		i++;
	}
	free(data->player_assets);
}

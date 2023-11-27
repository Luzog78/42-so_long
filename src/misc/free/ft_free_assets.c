/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 06:14:17 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/27 07:41:19 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_assets(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (!data->assets)
		return ;
	while (i < ASSETS_COUNT)
	{
		if (data->assets[i].frames)
		{
			j = 0;
			while (j < data->assets[i].tot_frames
				&& data->assets[i].frames[j].img)
			{
				mlx_destroy_image(data->mlx, data->assets[i].frames[j].img);
				j++;
			}
			free(data->assets[i].frames);
		}
		i++;
	}
	free(data->assets);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_player_assets.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:57:01 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/25 12:59:15 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_load_simple_player_asset(t_data *data, int idx, char *path)
{
	data->player_assets[idx].tot_frames = 1;
	data->player_assets[idx].frames = ft_calloc(2, sizeof(t_frame));
	if (!data->player_assets[idx].frames)
		return (ft_error(data, "Error: Can't allocate memory for frames\n"));
	data->player_assets[idx].frames[0].img = mlx_xpm_file_to_image(data->mlx,
		path, &data->player_assets[idx].frames[0].width,
		&data->player_assets[idx].frames[0].height);
	if (!data->player_assets[idx].frames[0].img)
		return (ft_error(data, "Error: Can't load asset\n"));
	data->player_assets[idx].frames[0].addr = mlx_get_data_addr(
		data->player_assets[idx].frames[0].img,
		&data->player_assets[idx].frames[0].bits_per_pixel,
		&data->player_assets[idx].frames[0].line_size,
		&data->player_assets[idx].frames[0].endian);
	if (!data->player_assets[idx].frames[0].addr)
		return (ft_error(data, "Error: Can't get asset address\n"));
	return (0);
}

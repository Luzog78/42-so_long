/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_player_assets.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:57:01 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/27 21:28:44 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_load(t_data *data, int idx, int i, char *path);

int	ft_load_player_asset(t_data *data, int idx,
		char *path0, char *path1, char *path2)
{
	data->player_assets[idx].tot_frames = 3;
	data->player_assets[idx].frames = ft_calloc(4, sizeof(t_frame));
	if (!data->player_assets[idx].frames)
		return (ft_error(data, "Error: Can't allocate memory for frames\n"));
	if (ft_load(data, idx, 0, path0) == -1
		|| ft_load(data, idx, 1, path1) == -1
		|| ft_load(data, idx, 2, path2) == -1)
		return (-1);
	return (0);
}

static int	ft_load(t_data *data, int idx, int i, char *path)
{
	data->player_assets[idx].frames[i].img = mlx_xpm_file_to_image(data->mlx,
			path, &data->player_assets[idx].frames[i].width,
			&data->player_assets[idx].frames[i].height);
	if (!data->player_assets[idx].frames[i].img)
		return (ft_error(data, "Error: Can't load asset\n"));
	data->player_assets[idx].frames[i].addr = mlx_get_data_addr(
			data->player_assets[idx].frames[i].img,
			&data->player_assets[idx].frames[i].bits_per_pixel,
			&data->player_assets[idx].frames[i].line_size,
			&data->player_assets[idx].frames[i].endian);
	if (!data->player_assets[idx].frames[i].addr)
		return (ft_error(data, "Error: Can't get asset address\n"));
	return (0);
}
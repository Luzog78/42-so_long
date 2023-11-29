/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_simple_asset.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 03:23:52 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/29 23:33:22 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_load_simple_asset(t_data *data, int idx, char *path)
{
	data->assets[idx].tot_frames = 1;
	data->assets[idx].frames = ft_calloc(2, sizeof(t_frame));
	if (!data->assets[idx].frames)
		return (ft_error(data, "Error\nCan't allocate memory for frames\n"));
	data->assets[idx].frames[0].img = mlx_xpm_file_to_image(data->mlx,
			path, &data->assets[idx].frames[0].width,
			&data->assets[idx].frames[0].height);
	if (!data->assets[idx].frames[0].img)
		return (ft_error(data, "Error\nCan't load asset\n"));
	data->assets[idx].frames[0].addr = mlx_get_data_addr(
			data->assets[idx].frames[0].img,
			&data->assets[idx].frames[0].bits_per_pixel,
			&data->assets[idx].frames[0].line_size,
			&data->assets[idx].frames[0].endian);
	if (!data->assets[idx].frames[0].addr)
		return (ft_error(data, "Error\nCan't get asset address\n"));
	return (0);
}

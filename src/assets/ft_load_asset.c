/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_asset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 03:23:52 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/29 23:33:22 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_load(t_data *data, int idx, int i, char *path);

int	ft_load_asset(t_data *data, int idx, char *path, int amount)
{
	int		i;
	char	*itoa;
	char	*complete_path;

	data->assets[idx].tot_frames = amount;
	data->assets[idx].frames = ft_calloc(amount + 1, sizeof(t_frame));
	if (!data->assets[idx].frames)
		return (ft_error(data, "Error\nCan't allocate memory for frames\n"));
	i = 0;
	while (i < amount)
	{
		itoa = ft_itoa(i, 2);
		if (!itoa)
			return (ft_error(data, "Error\nCan't allocate memory for itoa\n"));
		complete_path = ft_strjoin(path, itoa);
		free(itoa);
		if (ft_load(data, idx, i, complete_path) == -1)
		{
			free(complete_path);
			return (-1);
		}
		free(complete_path);
		i++;
	}
	return (0);
}

static int	ft_load(t_data *data, int idx, int i, char *path)
{
	char	*complete_path;

	complete_path = ft_strjoin(path, ".xpm");
	if (!complete_path)
		return (ft_error(data, "Error\nCan't allocate memory for path\n"));
	data->assets[idx].frames[i].img = mlx_xpm_file_to_image(data->mlx,
			complete_path, &data->assets[idx].frames[i].width,
			&data->assets[idx].frames[i].height);
	free(complete_path);
	if (!data->assets[idx].frames[i].img)
		return (ft_error(data, "Error\nCan't load asset\n"));
	data->assets[idx].frames[i].addr = mlx_get_data_addr(
			data->assets[idx].frames[i].img,
			&data->assets[idx].frames[i].bits_per_pixel,
			&data->assets[idx].frames[i].line_size,
			&data->assets[idx].frames[i].endian);
	if (!data->assets[idx].frames[i].addr)
		return (ft_error(data, "Error\nCan't get asset address\n"));
	return (0);
}

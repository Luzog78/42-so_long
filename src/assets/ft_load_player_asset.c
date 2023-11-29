/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_player_asset.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:57:01 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/29 23:53:34 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_load(t_data *data, int idx, int i, char *path);

int	ft_load_player_asset(t_data *data, int idx, char *path, int amount)
{
	char	*complete_path;
	char	*itoa;
	int		i;

	data->player_assets[idx].tot_frames = amount;
	data->player_assets[idx].frames = ft_calloc(amount + 1, sizeof(t_frame));
	if (!data->player_assets[idx].frames)
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
	data->player_assets[idx].frames[i].img = mlx_xpm_file_to_image(data->mlx,
			complete_path, &data->player_assets[idx].frames[i].width,
			&data->player_assets[idx].frames[i].height);
	free(complete_path);
	if (!data->player_assets[idx].frames[i].img)
		return (ft_error(data, "Error\nCan't load player asset\n"));
	data->player_assets[idx].frames[i].addr = mlx_get_data_addr(
			data->player_assets[idx].frames[i].img,
			&data->player_assets[idx].frames[i].bits_per_pixel,
			&data->player_assets[idx].frames[i].line_size,
			&data->player_assets[idx].frames[i].endian);
	if (!data->player_assets[idx].frames[i].addr)
		return (ft_error(data, "Error\nCan't get player asset address\n"));
	return (0);
}

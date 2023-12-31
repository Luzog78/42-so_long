/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_player_assets.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 03:03:08 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/29 23:33:22 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_load_player_assets(t_data *data)
{
	data->player_assets = ft_calloc(5, sizeof(t_asset));
	if (!data->assets)
		return (ft_error(data, "Error\nCan't allocate memory for player\n"));
	if (ft_load_player_asset(data, 0, "textures/front32-", 3) == -1
		|| ft_load_player_asset(data, 1, "textures/left32-", 3) == -1
		|| ft_load_player_asset(data, 2, "textures/right32-", 3) == -1
		|| ft_load_player_asset(data, 3, "textures/back32-", 3) == -1)
		return (-1);
	return (0);
}

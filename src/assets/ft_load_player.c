/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 03:03:08 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/25 13:24:06 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_load_player(t_data *data)
{
	data->player_assets = ft_calloc(5, sizeof(t_asset));
	if (!data->assets)
		return (ft_error(data, "Error: Can't allocate memory for player\n"));
	if (ft_load_simple_player_asset(data, 0, "img/tile001.xpm") == -1
		|| ft_load_simple_player_asset(data, 1, "img/tile016.xpm") == -1
		|| ft_load_simple_player_asset(data, 2, "img/tile031.xpm") == -1
		|| ft_load_simple_player_asset(data, 3, "img/tile046.xpm") == -1)
		return (-1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 03:03:08 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/27 21:15:16 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_load_player(t_data *data)
{
	data->player_assets = ft_calloc(5, sizeof(t_asset));
	if (!data->assets)
		return (ft_error(data, "Error: Can't allocate memory for player\n"));
	if (ft_load_player_asset(data, 0,
			"img/tile001.xpm", "img/tile000.xpm", "img/tile002.xpm") == -1
		|| ft_load_player_asset(data, 1,
			"img/tile016.xpm", "img/tile015.xpm", "img/tile017.xpm") == -1
		|| ft_load_player_asset(data, 2,
			"img/tile031.xpm", "img/tile030.xpm", "img/tile032.xpm") == -1
		|| ft_load_player_asset(data, 3,
			"img/tile046.xpm", "img/tile045.xpm", "img/tile047.xpm") == -1)
		return (-1);
	return (0);
}

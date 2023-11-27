/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 03:03:08 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/25 12:01:54 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_load_assets(t_data *data)
{
	data->assets = ft_calloc(ASSETS_COUNT + 1, sizeof(t_asset));
	if (!data->assets)
		return (ft_error(data, "Error: Can't allocate memory for assets\n"));
	// if (ft_load_cliff(data) == -1)
	if (
		ft_load_simple_asset(data, 0, "img/brick64.xpm") == -1
		|| ft_load_simple_asset(data, 1, "img/grass64.xpm") == -1
		|| ft_load_simple_asset(data, 2, "img/diamond64.xpm") == -1
		|| ft_load_simple_asset(data, 3, "img/craft64.xpm") == -1
	)
		return (-1);
	return (0);
}
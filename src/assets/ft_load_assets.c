/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 03:03:08 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/29 23:33:22 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_load_assets(t_data *data)
{
	data->assets = ft_calloc(ASSETS_COUNT + 1, sizeof(t_asset));
	if (!data->assets)
		return (ft_error(data, "Error\nCan't allocate memory for assets\n"));
	if (ft_load_simple_asset(data, 0, "textures/grass48-00.xpm") == -1
		|| ft_load_simple_asset(data, 1, "textures/bricks48-00.xpm") == -1
		|| ft_load_asset(data, 2, "textures/water48-", 9) == -1
		|| ft_load_asset(data, 3, "textures/diams32-", 6) == -1
		|| ft_load_simple_asset(data, 4, "textures/spawn48-00.xpm") == -1
		|| ft_load_simple_asset(data, 5, "textures/portal48-00.xpm") == -1
		|| ft_load_simple_asset(data, 6, "textures/portal48-01.xpm") == -1
		|| ft_load_simple_asset(data, 7, "textures/portal48-02.xpm") == -1
		|| ft_load_asset(data, 8, "textures/zombie48-", 5) == -1
		|| ft_load_asset(data, 9, "textures/zombie48-", 5) == -1
		|| ft_load_asset(data, 10, "textures/zombie48-", 5) == -1
		|| ft_load_asset(data, 11, "textures/zombie48-", 5) == -1
		|| ft_load_simple_asset(data, 12, "textures/display24-00.xpm") == -1
		|| ft_load_asset(data, 13, "textures/numsw16-", 11) == -1
		|| ft_load_asset(data, 14, "textures/numsr16-", 11) == -1
		|| ft_load_asset(data, 15, "textures/numsg16-", 11) == -1
		|| ft_load_asset(data, 16, "textures/numsy16-", 11) == -1)
		return (-1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 03:03:08 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/29 13:26:53 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_load_assets(t_data *data)
{
	data->assets = ft_calloc(ASSETS_COUNT + 1, sizeof(t_asset));
	if (!data->assets)
		return (ft_error(data, "Error: Can't allocate memory for assets\n"));
	if (ft_load_simple_asset(data, 0, "img/grass48-00.xpm") == -1
		|| ft_load_simple_asset(data, 1, "img/bricks48-00.xpm") == -1
		|| ft_load_asset(data, 2, "img/water48-", 9) == -1
		|| ft_load_asset(data, 3, "img/diams32-", 6) == -1
		|| ft_load_simple_asset(data, 4, "img/spawn48-00.xpm") == -1
		|| ft_load_simple_asset(data, 5, "img/portal48-00.xpm") == -1
		|| ft_load_simple_asset(data, 6, "img/portal48-01.xpm") == -1
		|| ft_load_simple_asset(data, 7, "img/portal48-02.xpm") == -1
		|| ft_load_asset(data, 8, "img/zombie48-", 5) == -1
		|| ft_load_asset(data, 9, "img/zombie48-", 5) == -1
		|| ft_load_asset(data, 10, "img/zombie48-", 5) == -1
		|| ft_load_asset(data, 11, "img/zombie48-", 5) == -1
		|| ft_load_simple_asset(data, 12, "img/display24-00.xpm") == -1
		|| ft_load_asset(data, 13, "img/numsw16-", 11) == -1
		|| ft_load_asset(data, 14, "img/numsr16-", 11) == -1
		|| ft_load_asset(data, 15, "img/numsg16-", 11) == -1
		|| ft_load_asset(data, 16, "img/numsy16-", 11) == -1)
		return (-1);
	return (0);
}

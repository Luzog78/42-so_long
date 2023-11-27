/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 07:07:27 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/27 03:30:48 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_data	data;

	ft_data_init(&data);
	if (ft_parse(&data, "map.ber") == -1
		|| ft_game_init(&data) == -1)
		return (-1);
	if (ft_load_assets(&data) == -1
		|| ft_load_player(&data) == -1)
	{
		ft_game_quit(&data);
		return (-1);
	}
	ft_arrange_map(&data);
	for (int i = 0; i < data.map_height; i++)
	{
		for (int j = 0; j < data.map_width; j++)
			printf("%c", data.map[i][j].type);
		printf("\n");
	}
	mlx_loop(data.mlx);
}

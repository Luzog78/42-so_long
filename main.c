/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 07:07:27 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/27 15:15:46 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_data	data;

	ft_data_init(&data);
	if (ft_parse(&data, "1.ber") == -1
		|| ft_game_init(&data) == -1)
		return (-1);
	if (ft_load_assets(&data) == -1
		|| ft_load_player(&data) == -1)
	{
		ft_game_quit(&data);
		return (-1);
	}
	ft_arrange_map(&data);
	mlx_loop(data.mlx);
}

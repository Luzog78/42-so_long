/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 07:07:27 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/30 01:08:37 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac <= 1)
	{
		write(1, "Error\nNo map file specified\n", 28);
		return (-1);
	}
	if (ac > 2)
	{
		write(1, "Error\nToo many arguments\n", 25);
		return (-1);
	}
	ft_data_init(&data);
	if (ft_parse(&data, av[1]) == -1
		|| ft_game_init(&data) == -1
		|| ft_load_assets(&data) == -1
		|| ft_load_player_assets(&data) == -1)
	{
		ft_game_quit(&data);
		return (-1);
	}
	ft_arrange_map(&data);
	ft_rand_mob(&data);
	mlx_loop(data.mlx);
}

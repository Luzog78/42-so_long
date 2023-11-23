/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 07:07:27 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/23 10:19:07 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_data	data;

	ft_data_init(&data);
	if (ft_parse(&data, "map.ber") == -1)
		return (-1);
	ft_game_init(&data);
	mlx_loop(data.mlx);
}

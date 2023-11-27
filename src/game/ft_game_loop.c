/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 07:14:05 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/27 05:32:46 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	ft_game_loop(t_data *data)
{
	t_vec2 point;

	ft_put_tiles(data);
	ft_put_player(data);
	if (data->frames % 100 == 0)
		ft_put_score(data);
	data->frames++;
	printf("frames: %llu\n", data->frames);
	return (0);
}

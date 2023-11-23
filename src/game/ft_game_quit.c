/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_quit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 07:16:15 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/23 11:05:04 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_game_quit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_image(data->mlx, data->frame.img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_free_map(data->map);
	exit(0);
	return (0);
}

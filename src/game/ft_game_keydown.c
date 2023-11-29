/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_keydown.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:50:32 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/29 15:45:23 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_game_keydown(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		ft_game_quit(data);
	else if (keycode == XK_w || keycode == XK_Up)
		ft_move_player(data, DIR_UP);
	else if (keycode == XK_s || keycode == XK_Down)
		ft_move_player(data, DIR_DOWN);
	else if (keycode == XK_a || keycode == XK_Left)
		ft_move_player(data, DIR_LEFT);
	else if (keycode == XK_d || keycode == XK_Right)
		ft_move_player(data, DIR_RIGHT);
	return (0);
}

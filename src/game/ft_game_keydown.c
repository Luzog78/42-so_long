/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_keydown.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:50:32 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/22 10:19:23 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_game_keydown(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		ft_game_quit(data);
	return (0);
}

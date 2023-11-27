/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_mobs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 06:49:27 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/27 07:29:23 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_direction	*ft_get_dir(t_mob *mob);

void	ft_move_mobs(t_data *data)
{
	t_mob		*mob;
	t_direction	*dirs;
	t_bool		moved;
	int			i;

	mob = data->mobs;
	while (mob)
	{
		dirs = ft_get_dir(mob);
		moved = FALSE;
		i = 0;
		while (!moved && i < 4)
		{
			mob->dir = dirs[i];
			moved = ft_move_mob(data, mob);
			i++;
		}
		free(dirs);
		if (mob->pos.x == data->player.x
			&& mob->pos.y == data->player.y)
			ft_game_quit(data); // GAME OVER
		mob = mob->next;
	}
}

static t_direction	*ft_get_dir(t_mob *mob)
{
	t_direction dir;
	t_direction *dirs;
	int i;
	
	dirs = ft_calloc(4, sizeof(t_direction));
	if (dirs == NULL)
		return (NULL);
	dirs[3] = DIR_LEFT;
	if (mob->dir == DIR_UP)
		dirs[3] = DIR_DOWN;
	else if (mob->dir == DIR_DOWN)
		dirs[3] = DIR_UP;
	else if (mob->dir == DIR_LEFT)
		dirs[3] = DIR_RIGHT;
	i = 0;
	dir = rand() % 4;
	while (i < 3)
	{
		if (dir == dirs[3])
			dir = (dir + 1) % 4;
		dirs[i] = dir;
		dir = (dir + 1) % 4;
		i++;
	}
	return (dirs);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_mobs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 06:49:27 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/29 22:36:58 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_direction	*ft_get_dir(t_mob *mob);
static void			ft_fill_dirs(t_direction **dirs);

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
		mob = mob->next;
	}
}

static t_direction	*ft_get_dir(t_mob *mob)
{
	t_direction	*dirs;

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
	ft_fill_dirs(&dirs);
	return (dirs);
}

static void	ft_fill_dirs(t_direction **dirs)
{
	int			i;
	t_direction	dir;

	i = 0;
	while (i < 3)
	{
		while (1)
		{
			dir = rand() % 4;
			if (dir == (*dirs)[3]
				|| (i > 0 && dir == (*dirs)[0])
				|| (i > 1 && dir == (*dirs)[1])
				|| (i > 2 && dir == (*dirs)[2]))
				continue ;
			(*dirs)[i] = dir;
			break ;
		}
		i++;
	}
}

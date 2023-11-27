/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_mobs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 06:37:31 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/27 06:38:37 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_mobs(t_data *data)
{
	t_mob	*mob;

	mob = data->mobs;
	while (mob)
	{
		ft_put_mob(data, mob);
		mob = mob->next;
	}
}

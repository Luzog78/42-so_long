/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mobs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 07:38:14 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/27 07:38:44 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_mobs(t_mob *mobs)
{
	t_mob	*tmp;

	while (mobs)
	{
		tmp = mobs;
		mobs = mobs->next;
		free(tmp);
	}
}
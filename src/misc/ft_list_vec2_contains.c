/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_vec2_contains.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:44:10 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/22 19:37:03 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	ft_list_vec2_contains(t_list_vec2 *list, t_vec2 vec)
{
	if (!list)
		return (FALSE);
	while (list)
	{
		if (list->x == vec.x && list->y == vec.y)
			return (TRUE);
		list = list->next;
	}
	return (FALSE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_vec2_add_front.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:44:10 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/22 18:52:46 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_list_vec2_add_front(t_list_vec2 **list, t_vec2 vec)
{
	t_list_vec2	*new;

	new = malloc(sizeof(t_list_vec2));
	if (!new)
		return ;
	new->x = vec.x;
	new->y = vec.y;
	if (!*list)
		*list = new;
	else
	{
		new->next = *list;
		*list = new;
	}
}

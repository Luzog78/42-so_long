/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list_vec2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:11:21 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/23 11:11:27 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_list_vec2(t_list_vec2 **list)
{
	t_list_vec2	*tmp;

	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
	}
}
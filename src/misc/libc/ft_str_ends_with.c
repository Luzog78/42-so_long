/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_ends_with.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 23:23:34 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/29 23:25:28 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	ft_str_ends_with(char *str, char *end)
{
	int	str_len;
	int	end_len;

	str_len = ft_strlen(str);
	end_len = ft_strlen(end);
	if (str_len < end_len)
		return (FALSE);
	return (!ft_strncmp(str + str_len - end_len, end, end_len));
}

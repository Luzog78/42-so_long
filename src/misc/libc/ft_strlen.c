/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:28:14 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/27 04:20:21 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(char const *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

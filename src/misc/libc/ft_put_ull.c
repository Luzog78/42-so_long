/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ull.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:31:13 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/29 17:33:02 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_ull(t_ull ull)
{
	if (ull >= 10)
		ft_put_ull(ull / 10);
	write(1, &(char){ull % 10 + '0'}, 1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_progression.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 07:25:15 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/23 21:46:43 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * This function is used to create a color progression.
 * It takes an integer i and an integer max as parameters.
 * 
 * The pattern is as follows:
 * > color = 0xFFFFFFFF, i = 0
 * > color = 0xFF0000FF, i = max / 7
 * > color = 0xFF00FFFF, i = max * 2 / 7
 * > color = 0xFF00FF00, i = max * 3 / 7
 * > color = 0xFFFFFF00, i = max * 4 / 7
 * > color = 0xFFFF0000, i = max * 5 / 7
 * > color = 0xFFFF00FF, i = max * 6 / 7
 * > color = 0xFFFFFFFF, i = max
*/
t_ui	ft_color_progression(int i, int max)
{
	if (i < max / 7)
		return (ft_grad_color(i, max / 7, 0xFFFFFFFF, 0xFF0000FF));
	else if (i < max * 2 / 7)
		return (ft_grad_color(
			i - max / 7, max / 7, 0xFF0000FF, 0xFF00FFFF));
	else if (i < max * 3 / 7)
		return (ft_grad_color(
			i - max * 2 / 7, max / 7, 0xFF00FFFF, 0xFF00FF00));
	else if (i < max * 4 / 7)
		return (ft_grad_color(
			i - max * 3 / 7, max / 7, 0xFF00FF00, 0xFFFFFF00));
	else if (i < max * 5 / 7)
		return (ft_grad_color(
			i - max * 4 / 7, max / 7, 0xFFFFFF00, 0xFFFF0000));
	else if (i < max * 6 / 7)
		return (ft_grad_color(
			i - max * 5 / 7, max / 7, 0xFFFF0000, 0xFFFF00FF));
	else
		return (ft_grad_color(
			i - max * 6 / 7, max / 7, 0xFFFF00FF, 0xFFFFFFFF));
}

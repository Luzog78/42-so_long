/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blend.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:44:52 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/23 21:28:32 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Create an alpha blended color from two colors.
 * (Thanxx to `https://en.wikipedia.org/wiki/Alpha_compositing` for the formula)
*/
t_ui	ft_blend(t_ui a, t_ui b)
{
	t_ui	a_color;
	double	a_aplha;
	t_ui	b_color;
	double	b_alpha;
	t_ui	result;

	a_aplha = (a >> 24) / 255.0;
	b_alpha = (b >> 24) / 255.0;
	if (a_aplha == 1.0 || b_alpha == 0.0)
		return (a);
	if (a_aplha == 0.0)
		return (b);
	a_color = a & 0x00FFFFFF;
	b_color = b & 0x00FFFFFF;
	result = (a_color * a_aplha + (b_color * b_alpha) * (1.0 - a_aplha))
			/ (a_aplha + b_alpha * (1.0 - a_aplha));
	result |= ((a >> 24) + (b >> 24) * (255 - (a >> 24))) << 24;
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grad_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 07:21:26 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/22 07:23:46 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_grad_color_r(int i, int max, int color1, int color2);
static int	ft_grad_color_g(int i, int max, int color1, int color2);
static int	ft_grad_color_b(int i, int max, int color1, int color2);

int	ft_grad_color(int i, int max, int color1, int color2)
{
	int	r;
	int	g;
	int	b;

	r = ft_grad_color_r(i, max, color1, color2);
	g = ft_grad_color_g(i, max, color1, color2);
	b = ft_grad_color_b(i, max, color1, color2);
	return (ft_argb(0, r, g, b));
}

static int	ft_grad_color_r(int i, int max, int color1, int color2)
{
	int	r1;
	int	r2;
	int	r;

	r1 = (color1 >> 16) & 0xFF;
	r2 = (color2 >> 16) & 0xFF;
	r = r1 + ((r2 - r1) * i / max);
	return (r);
}

static int	ft_grad_color_g(int i, int max, int color1, int color2)
{
	int	g1;
	int	g2;
	int	g;

	g1 = (color1 >> 8) & 0xFF;
	g2 = (color2 >> 8) & 0xFF;
	g = g1 + ((g2 - g1) * i / max);
	return (g);
}

static int	ft_grad_color_b(int i, int max, int color1, int color2)
{
	int	b1;
	int	b2;
	int	b;

	b1 = color1 & 0xFF;
	b2 = color2 & 0xFF;
	b = b1 + ((b2 - b1) * i / max);
	return (b);
}

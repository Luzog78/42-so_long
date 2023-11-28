/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:44:01 by luzog             #+#    #+#             */
/*   Updated: 2023/11/28 06:48:52 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill(char *str, int idx, int integer);
static int	int_len(int i);

char	*ft_itoa(int integer, int min_len)
{
	int		i;
	int		len;
	char	*alpha;

	len = ft_max(int_len(integer), min_len);
	alpha = ft_calloc(len + 1, sizeof(char));
	if (alpha == NULL)
		return (NULL);
	if (integer == -2147483648)
	{
		i = 0;
		while (i < 11)
		{
			alpha[i] = "-2147483648"[i];
			i++;
		}
		return (alpha);
	}
	fill(alpha, len - 1, integer);
	alpha[len] = '\0';
	return (alpha);
}

static void	fill(char *str, int idx, int integer)
{
	if (integer < 0)
	{
		str[0] = '-';
		integer = -integer;
	}
	if (integer != 0)
	{
		str[idx] = '0' + (integer % 10);
		integer /= 10;
	}
	else
		str[idx] = '0';
	if (idx > 0)
		fill(str, idx - 1, integer);
}

static int	int_len(int i)
{
	int	len;

	if (i == 0)
		return (1);
	len = 0;
	if (i < 0)
		len++;
	while (i != 0)
	{
		len++;
		i /= 10;
	}
	return (len);
}

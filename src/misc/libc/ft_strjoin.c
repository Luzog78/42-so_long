/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:43:53 by luzog             #+#    #+#             */
/*   Updated: 2023/11/27 04:18:31 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strcopy(char *dest, char const *src);

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l1;
	int		l2;
	char	*s;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	s = malloc(sizeof(char) * (l1 + l2 + 1));
	if (s == NULL)
		return (NULL);
	ft_strcopy(s, s1);
	ft_strcopy(s + l1, s2);
	s[l1 + l2] = '\0';
	return (s);
}

static char	*ft_strcopy(char *dest, char const *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

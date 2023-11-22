/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 06:59:41 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/22 13:28:01 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*gnl_ft_realloc_join(char *s1, char *s2)
{
	char	*new_str;
	size_t	i;

	new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	free(s1);
	while (*s2)
	{
		new_str[i] = *s2;
		i++;
		s2++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*gnl_ft_realloc_skip(char *str, size_t n)
{
	char	*new_str;
	size_t	len;
	size_t	i;

	len = ft_strlen(str) - n;
	if (len <= 0)
	{
		free(str);
		return (NULL);
	}
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = str[n + i];
		i++;
	}
	new_str[i] = '\0';
	free(str);
	return (new_str);
}

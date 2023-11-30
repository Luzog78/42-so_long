/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:21:45 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/30 00:59:23 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_clean_gnl(int fd);

int	ft_parse_map(t_data *data, int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (i >= data->map_height)
		{
			free(line);
			ft_clean_gnl(fd);
			return (ft_error(data, "Error\nLine count error\n"));
		}
		if (ft_parse_line(data, line, i) == -1)
		{
			free(line);
			ft_clean_gnl(fd);
			return (-1);
		}
		free(line);
		i++;
	}
	return (0);
}

static void	ft_clean_gnl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

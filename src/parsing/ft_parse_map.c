/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:21:45 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/25 01:43:53 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			return (ft_error(data, "Error: Line count error\n"));
		}
		if (ft_parse_line(data, line, i) == -1)
		{
			free(line);
			return (-1);
		}
		free(line);
		i++;
	}
	return (0);
}

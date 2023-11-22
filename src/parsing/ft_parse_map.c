/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:21:45 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/22 19:34:18 by ysabik           ###   ########.fr       */
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
			return (ft_error(data, "Error: ... Stop trolling bro\n"));
		}
		if (ft_parse_line(data, line, i) == -1)
		{
			free(line);
			return (-1);
		}
		i++;
	}
	return (0);
}
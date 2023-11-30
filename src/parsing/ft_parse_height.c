/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_height.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:30:04 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/30 01:30:43 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_parse_height(t_data *data, char *map_path)
{
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (ft_error(data, "Error\nCannot open the map file\n"));
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		data->map_height++;
	}
	close(fd);
	return (0);
}

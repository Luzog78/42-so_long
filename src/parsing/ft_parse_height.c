/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_height.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:30:04 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/29 23:33:22 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_parse_height(t_data *data, char *map_path)
{
	int		fd;
	char	buf;
	int		result;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (ft_error(data, "Error\nCannot open the map file\n"));
	result = 1;
	while (result)
	{
		result = read(fd, &buf, 1);
		if (result == -1)
		{
			close(fd);
			return (ft_error(data, "Error\nCannot read the map file\n"));
		}
		if (result && buf == '\n')
			data->map_height++;
	}
	close(fd);
	return (0);
}

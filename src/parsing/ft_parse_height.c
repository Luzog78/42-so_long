/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_height.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:30:04 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/22 19:34:28 by ysabik           ###   ########.fr       */
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
		return (ft_error(data, "Error: Cannot open the map file\n"));
	result = 1;
	while (result)
	{
		result = read(fd, &buf, 1);
		if (result && buf == '\n')
			data->map_height++;
	}
	close(fd);
	return (0);
}

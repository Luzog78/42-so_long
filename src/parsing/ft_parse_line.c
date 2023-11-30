/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:21:03 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/30 01:27:26 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_get_length(char *line);

int	ft_parse_line(t_data *data, char *line, int i)
{
	int	j;

	j = ft_get_length(line);
	if (data->map_width == -1)
		data->map_width = j;
	if (data->map_width != j)
		return (ft_error(data, "Error\nMap is not rectangular\n"));
	data->map[i] = ft_calloc(data->map_width + 1, sizeof(t_tile));
	if (!data->map)
		return (ft_error(data, "Error\nCannot allocate memory for the map\n"));
	j = 0;
	while (line[j] && line[j] != '\n')
	{
		if (ft_parse_char(data, line[j], i, j) == -1)
			return (-1);
		j++;
	}
	if (data->map_width != j)
		return (ft_error(data, "Error\nMap is not rectangular\n"));
	return (1);
}

static int	ft_get_length(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

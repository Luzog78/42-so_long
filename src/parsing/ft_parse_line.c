/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:21:03 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/25 01:47:24 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_get_length(char *line);

int	ft_parse_line(t_data *data, char *line, int i)
{
	int	j;

	j = 0;
	if (ft_get_length(line) != data->map_width)
		return (ft_error(data, "Error: Map is not rectangular\n"));
	data->map = ft_calloc(data->map_width + 1, sizeof(t_tile));
	if (!data->map)
		return (ft_error(data, "Error: Cannot allocate memory for the map\n"));
	while (line[j] && line[j] != '\n')
	{
		if (ft_parse_char(data, line[j], i, j) == -1)
			return (-1);
		j++;
	}
	if (data->map_width == -1)
		data->map_width = j;
	if (data->map_width != j || line[j] != '\n')
		return (ft_error(data, "Error: Map is not rectangular\n"));
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

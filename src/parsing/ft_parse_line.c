/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:21:03 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/22 19:33:50 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_parse_line(t_data *data, char *line, int i)
{
	int	j;

	j = 0;
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
	data->map[i] = line;
	return (1);
}
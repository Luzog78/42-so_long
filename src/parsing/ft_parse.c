/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:21:45 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/22 19:34:44 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_parse(t_data *data, char *map_path)
{
	int			fd;

	if (ft_parse_height(data, map_path) == -1)
		return (-1);
	data->map = malloc(sizeof(char *) * data->map_height);
	if (!data->map)
		return (ft_error(data, "Error: Cannot allocate memory for the map\n"));
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (ft_error(data, "Error: Cannot open the map file\n"));
	if (ft_parse_map(data, fd) == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	if (ft_check_map(data) == -1 || ft_check_path(data) == -1)
		return (-1);
	return (0);
}
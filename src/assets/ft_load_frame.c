/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_frame.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:02:49 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/27 15:01:47 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_frame	ft_load_frame(t_data *data, char *path)
{
	t_frame	frame;

	frame.img = mlx_xpm_file_to_image(data->mlx, path,
			&frame.width, &frame.height);
	frame.addr = mlx_get_data_addr(frame.img, &frame.bits_per_pixel,
			&frame.line_size, &frame.endian);
	return (frame);
}

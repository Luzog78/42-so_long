/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_frame.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:02:49 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/24 11:04:00 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_frame	*ft_load_frame(t_data *data)
{
	t_frame	*frame;
	
	frame = malloc(sizeof(t_frame));
	if (!frame)
		return (NULL);
	frame->img = mlx_xpm_file_to_image(data->mlx, "./assets/resized/cliff_01.xpm", &data->img.width, &data->img.height);
	frame->addr = mlx_get_data_addr(
		data->img.img, &data->img.bits_per_pixel,
		&data->img.line_size, &data->img.endian);
}
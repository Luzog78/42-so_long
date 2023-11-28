/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_score.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 04:14:42 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/28 06:33:56 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_clear_tile(t_data *data, t_vec2 point);
static int	ft_int_len(int i);

void	ft_put_score(t_data *data)
{
	char	*moves;
	char	*collected;
	char	*count;
	int		len;
	t_ui	color;

	ft_clear_tile(data, (t_vec2){0, 0});
	ft_clear_tile(data, (t_vec2){1, 0});
	ft_clear_tile(data, (t_vec2){2, 0});
	moves = ft_itoa(data->moves, 1);
	collected = ft_itoa(data->items_collected, 1);
	count = ft_itoa(data->items_count, 1);
	len = ft_int_len(data->items_collected);
	color = 0xFFFF00;
	if (data->items_collected == data->items_count)
		color = 0x00FF00;
	mlx_string_put(data->mlx, data->mlx_win, 16, 16, 0xFFFFFF, "Moves :");
	mlx_string_put(data->mlx, data->mlx_win, 64, 16, 0x00FFFF, moves);
	mlx_string_put(data->mlx, data->mlx_win, 16, 32, 0xFFFFFF, "Items :");
	mlx_string_put(data->mlx, data->mlx_win, 64, 32, color, collected);
	mlx_string_put(data->mlx, data->mlx_win, 66 + len * 6, 32, 0xFF0000, "/");
	mlx_string_put(data->mlx, data->mlx_win, 74 + len * 6, 32, 0xFF0000, count);
	free(moves);
	free(collected);
	free(count);
}

static int	ft_int_len(int i)
{
	int	len;

	if (i == 0)
		return (1);
	len = 0;
	if (i < 0)
		len++;
	while (i != 0)
	{
		len++;
		i /= 10;
	}
	return (len);
}

static void	ft_clear_tile(t_data *data, t_vec2 point)
{
	data->map[point.y][point.x].has_changed = TRUE;
	ft_put_tile(data, point);
}

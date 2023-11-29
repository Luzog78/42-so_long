/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_score.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 04:14:42 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/29 23:52:58 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_display
{
	t_vec2	point;
	int		len;
	int		asset;
}	t_display;

static void	ft_put_case(t_data *data, t_display d);
static void	ft_put_nbr(t_data *data, t_display d, int n);
static void	ft_put_slash(t_data *data, t_display d);

void	ft_put_score(t_data *data)
{
	int	line;
	int	asset_collected;
	int	asset_count;

	line = data->map_width * TILE_SIZE;
	asset_collected = 16;
	if (data->items_collected == data->items_count)
		asset_collected = 15;
	asset_count = 14;
	if (data->items_collected == data->items_count)
		asset_count = 15;
	ft_put_case(data, (t_display){(t_vec2){5, 5}, 3, 12});
	ft_put_case(data, (t_display){
		(t_vec2){line - 5 * GUI_CASE_SIZE - 5, 5}, 5, 12});
	ft_put_nbr(data, (t_display){(t_vec2){5, 5}, 3, 13}, data->moves);
	ft_put_nbr(data, (t_display){
		(t_vec2){line - 5 * GUI_CASE_SIZE - 5, 5},
		2, asset_collected}, data->items_collected);
	ft_put_slash(data, (t_display){
		(t_vec2){line - 3 * GUI_CASE_SIZE - 5, 5}, 1, 13});
	ft_put_nbr(data, (t_display){
		(t_vec2){line - 2 * GUI_CASE_SIZE - 5, 5},
		2, asset_count}, data->items_count);
}

static void	ft_put_case(t_data *data, t_display d)
{
	int	i;

	i = 0;
	while (i < d.len)
	{
		ft_put_frame(data, &data->assets[d.asset].frames[0],
			(t_vec2){d.point.x + GUI_CASE_SIZE * i, d.point.y});
		i++;
	}
}

static void	ft_put_nbr(t_data *data, t_display d, int n)
{
	t_vec2	p;
	int		i;

	p = (t_vec2){d.point.x + (GUI_CASE_SIZE - GUI_NBR_SIZE) / 2 + 2,
		d.point.y + (GUI_CASE_SIZE - GUI_NBR_SIZE) / 2 + 1};
	i = d.len - 1;
	while (i >= 0)
	{
		ft_put_frame(data, &data->assets[d.asset].frames[n % 10],
			(t_vec2){p.x + GUI_CASE_SIZE * i, p.y});
		n /= 10;
		i--;
	}
}

static void	ft_put_slash(t_data *data, t_display d)
{
	t_vec2	p;
	int		i;

	p = (t_vec2){d.point.x + (GUI_CASE_SIZE - GUI_NBR_SIZE) / 2 + 2,
		d.point.y + (GUI_CASE_SIZE - GUI_NBR_SIZE) / 2 + 1};
	i = d.len - 1;
	while (i >= 0)
	{
		ft_put_frame(data, &data->assets[d.asset].frames[10],
			(t_vec2){p.x + GUI_CASE_SIZE * i, p.y});
		i--;
	}
}

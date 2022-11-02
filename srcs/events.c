/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:39:41 by bcoenon           #+#    #+#             */
/*   Updated: 2022/11/02 19:35:46 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	events(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		free_ptr(&data->p);
	}
	data->size = player(data->map);
	if (key == 'w')
		move_up(*data);
	if (key == 'a')
		move_left(*data);
	if (key == 's')
		move_down(*data);
	if (key == 'd')
		move_right(*data);
	return (0);
}

void	move_up(t_data data)
{
	if (data.map[data.size.x - 1][data.size.y] != '1')
	{
		data.map[data.size.x - 1][data.size.y] = 'P';
		data.map[data.size.x][data.size.y] = '0';
		create_map(data.p.mlx_p, data.p.window, data.map);
	}
}

void	move_left(t_data data)
{
	if (data.map[data.size.x][data.size.y - 1] != '1')
	{
		data.map[data.size.x][data.size.y - 1] = 'P';
		data.map[data.size.x][data.size.y] = '0';
		create_map(data.p.mlx_p, data.p.window, data.map);
	}
}

void	move_down(t_data data)
{
	if (data.map[data.size.x + 1][data.size.y] != '1')
	{
		data.map[data.size.x + 1][data.size.y] = 'P';
		data.map[data.size.x][data.size.y] = '0';
		create_map(data.p.mlx_p, data.p.window, data.map);
	}
}

void	move_right(t_data data)
{
	if (data.map[data.size.x][data.size.y + 1] != '1')
	{
		data.map[data.size.x][data.size.y + 1] = 'P';
		data.map[data.size.x][data.size.y] = '0';
		create_map(data.p.mlx_p, data.p.window, data.map);
	}
}


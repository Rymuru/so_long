/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:39:41 by bcoenon           #+#    #+#             */
/*   Updated: 2022/11/10 18:57:44 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	events(int key, t_data *data)
{
	char		*steps;
	t_vector	pos;

	pos.x = 0;
	pos.y = 0;
	if (key == XK_Escape)
	{
		close_map(data);
	}
	data->size = find_player(data->map);
	if (key == 'w' || key == 65362)
		move_up(data);
	if (key == 'a' || key == 65361)
		move_left(data);
	if (key == 's' || key == 65364)
		move_down(data);
	if (key == 'd' || key == 65363)
		move_right(data);
	create_image(data->p.mlx_p, data->p.window, pos, WALL);
	steps = ft_itoa(data->move);
	mlx_string_put(data->p.mlx_p, data->p.window, 10, 10, 0xffffff, steps);
	free(steps);
	if (find_things(data->map, 'C') == 0 && find_things(data->map, 'E') == 0)
		close_map(data);
	return (0);
}

void	move_up(t_data *data)
{
	if (data->map[data->size.x - 1][data->size.y] != '1')
	{
		++data->move;
		printf("%d\n", data->move);
		if (find_things(data->map, 'E') == 0)
		{
			data->map[data->size.x][data->size.y] = 'E';
			create_image(data->p.mlx_p, data->p.window, data->size, EXIT);
		}
		else
		{
			data->map[data->size.x][data->size.y] = '0';
			create_image(data->p.mlx_p, data->p.window, data->size, GROUND);
		}
		--data->size.x;
		data->map[data->size.x][data->size.y] = 'P';
		create_image(data->p.mlx_p, data->p.window, data->size, RED_RIGHT);
	}
}

void	move_left(t_data *data)
{
	if (data->map[data->size.x][data->size.y - 1] != '1')
	{
		++data->move;
		printf("%d\n", data->move);
		if (find_things(data->map, 'E') == 0)
		{
			data->map[data->size.x][data->size.y] = 'E';
			create_image(data->p.mlx_p, data->p.window, data->size, EXIT);
		}
		else
		{
			data->map[data->size.x][data->size.y] = '0';
			create_image(data->p.mlx_p, data->p.window, data->size, GROUND);
		}
		--data->size.y;
		data->map[data->size.x][data->size.y] = 'P';
	}
	create_image(data->p.mlx_p, data->p.window, data->size, RED_LEFT);
}

void	move_down(t_data *data)
{
	if (data->map[data->size.x + 1][data->size.y] != '1')
	{
		++data->move;
		printf("%d\n", data->move);
		if (find_things(data->map, 'E') == 0)
		{
			data->map[data->size.x][data->size.y] = 'E';
			create_image(data->p.mlx_p, data->p.window, data->size, EXIT);
		}
		else
		{
			data->map[data->size.x][data->size.y] = '0';
			create_image(data->p.mlx_p, data->p.window, data->size, GROUND);
		}
		++data->size.x;
		data->map[data->size.x][data->size.y] = 'P';
		create_image(data->p.mlx_p, data->p.window, data->size, RED_LEFT);
	}
}

void	move_right(t_data *data)
{
	if (data->map[data->size.x][data->size.y + 1] != '1')
	{
		++data->move;
		printf("%d\n", data->move);
		if (find_things(data->map, 'E') == 0)
		{
			data->map[data->size.x][data->size.y] = 'E';
			create_image(data->p.mlx_p, data->p.window, data->size, EXIT);
		}
		else
		{
			data->map[data->size.x][data->size.y] = '0';
			create_image(data->p.mlx_p, data->p.window, data->size, GROUND);
		}
		++data->size.y;
		data->map[data->size.x][data->size.y] = 'P';
	}
	create_image(data->p.mlx_p, data->p.window, data->size, RED_RIGHT);
}

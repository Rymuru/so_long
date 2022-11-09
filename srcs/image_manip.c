/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:13:51 by bcoenon           #+#    #+#             */
/*   Updated: 2022/11/09 16:04:03 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_map(void *mlx, void *windows, char **map)
{
	t_vector	pos;

	pos.x = 0;
	pos.y = 0;
	while (map[pos.x])
	{
		while (map[pos.x][pos.y])
		{
			if (map[pos.x][pos.y] == '1')
				create_image(mlx, windows, pos, WALL);
			else if (map[pos.x][pos.y] == 'P')
				create_image(mlx, windows, pos, RED_RIGHT);
			else if (map[pos.x][pos.y] == 'E')
				create_image(mlx, windows, pos, EXIT);
			else if (map[pos.x][pos.y] == 'C')
				create_image(mlx, windows, pos, KEY);
			else
				create_image(mlx, windows, pos, GROUND);
			++pos.y;
		}
		++pos.x;
		pos.y = 0;
	}
}

void	create_image(void *mlx, void *window, t_vector pos, char *path)
{
	t_image	img;

	img = ft_new_sprite(mlx, path);
	mlx_put_image_to_window(mlx, window, img.ptr, pos.y * 100, pos.x * 100);
	free_image(mlx, img);
}

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels = mlx_get_data_addr(img.ptr, &img.bits, &img.line, &img.endian);
	return (img);
}

t_vector	window_size(char **map)
{
	t_vector	map_size;

	map_size.x = 0;
	map_size.y = 0;
	while (map[map_size.x] || map[0][map_size.y] != '\n')
	{
		if (map[map_size.x])
			++map_size.x;
		if (map[0][map_size.y] && map[0][map_size.y] != '\n')
			++map_size.y;
	}
	map_size.x *= 100;
	map_size.y *= 100;
	return (map_size);
}

t_vector	find_player(char **map)
{
	t_vector	pos;

	pos.x = 0;
	pos.y = 0;
	while (map[pos.x])
	{
		while (map[pos.x][pos.y])
		{
			if (map[pos.x][pos.y] == 'P')
			{
				return (pos);
			}
			++pos.y;
		}
		pos.y = 0;
		++pos.x;
	}
	return (pos);
}

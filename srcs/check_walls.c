/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 03:26:46 by bcoenon           #+#    #+#             */
/*   Updated: 2022/11/10 17:53:34 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	strlen_map(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	seems_weird(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[x])
	{
		while (map[x][y])
		{
			if (map[x][y] != '0' && map[x][y] != '1'
				&& map[x][y] != 'P' && map[x][y] != 'C'
				&& map[x][y] != 'E' && map[x][y] != '\n')
				return (1);
			++y;
		}
		y = 0;
		++x;
	}
	return (0);
}

int	check_walls_line(char **map, int x, int y)
{
	while (map[0][y] && map[0][y] != '\n')
	{
		if (map[0][y] != '1')
			return (1);
		++y;
	}
	y = 0;
	while (map[x][y])
	{
		if (map[x][y] != '1')
			return (1);
		++y;
	}
	return (0);
}

int	check_walls_column(char **map, int x, int y)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (map[i][0] != '1')
			return (1);
		++i;
	}
	i = 0;
	while (i < x)
	{
		if (map[i][y - 1] != '1')
			return (1);
		++i;
	}
	return (0);
}

int	nice_walled_rectangle(char **map)
{
	t_vector	size;

	size.x = 0;
	size.y = strlen_map(map[0]);
	while (map[size.x])
	{
		if (strlen_map(map[size.x]) != size.y)
			return (1);
		++size.x;
	}
	--size.x;
	if (size.x > 20 || size.y > 38)
		return (1);
	if (check_walls_line(map, size.x, 0) == 1)
		return (1);
	if (check_walls_column(map, size.x, size.y) == 1)
		return (1);
	return (0);
}

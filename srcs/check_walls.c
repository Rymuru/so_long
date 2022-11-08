/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 03:26:46 by bcoenon           #+#    #+#             */
/*   Updated: 2022/11/08 18:03:48 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls_line(char **map, int x, int y)
{
	while (map[0][y])
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
		if (map[i][y] != '1')
			return (1);
		++i;
	}
	return (0);
}

int	nice_walled_rectangle(char **map)
{
	t_vector	size;
	t_vector	pos;

	pos.x = 0;
	pos.y = 0;
	size.x = 0;
	size.y = ft_strlen(map[0]);
	while (map[pos.x])
	{
		while (map[pos.x][pos.y])
		{
			++pos.y;
		}
		if (pos.y > size.y || pos.y < size.y)
			return (1);
		pos.y = 0;
		++pos.x;
	}
	size.x = pos.x;
	//if (check_walls_line(map, size.x, 0) == 1)
		//return (1);
	//if (check_walls_column(map, size.x, size.y) == 1)
		//return (1);
	return (0);
}

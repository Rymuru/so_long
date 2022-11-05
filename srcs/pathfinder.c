/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 01:50:23 by bcoenon           #+#    #+#             */
/*   Updated: 2022/11/05 06:21:05 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_chuck(char **map)
{
	int collectibles;
	char **copy;
	t_vector player;

	copy = map;
	if (find_things(copy, 'P') != 1)
		return (1);
	if (find_things(copy, 'E') != 1)
		return (1);
	if (find_things(copy, 'C') < 1)
		return (1);
	player = ft_player(map);
	collectibles = find_things(map, 'C');
	if (nice_walled_rectangle == 1)
		return (1);
	return (0);
}

int	find_things(char **map, char c)
{
	int			things;
	t_vector	pos;

	pos.x = 0;
	pos.y = 0;
	things = 0;
	while (map[pos.x])
	{
		while (map[pos.x][pos.y])
		{
			if (map[pos.x][pos.y] == c)
			{
				++things;
			}
			++pos.y;
		}
		pos.y = 0;
		++pos.x;
	}
	return (things);
}

int try_hard(char **map, int collectibles, int ex, t_vector player)
{
	if (map[player.x][player.y] == 'C')
	{
		map[player.x][player.y] == '0';
		--collectibles;
	}
	if (map[player.x][player.y] == 'E')
	{
		map[player.x][player.y] == '0';
		--ex;
	}
	if (collectibles == 0 && ex == 0)
	{
		return 0;
	}
	if (path(map, player) == 0)
		return (1);
	if (path(map, player) == 1)
		map[player.x][player.y] = '1';
	if (map[player.x][player.y + 1] != 1)
	{
		++player.y;
		try_hard(map, collectibles, ex, player);
	}
	else if (map[player.x + 1][player.y])
	{
		++player.x;
		try_hard(map, collectibles, ex, player);
	}
	else if (map[player.x][player.y - 1])
	{
		--player.y;
		try_hard(map, collectibles, ex, player);
	}
	else if (map[player.x - 1][player.y])
	{
		--player.x;
		try_hard(map, collectibles, ex, player);
	}
}

int check_pos(char **map, t_vector player)
{
	int path;

	path = 0;
	if (map[player.x][player.y + 1] != 1)
		++path;
	if (map[player.x + 1][player.y])
		++path;
	if (map[player.x][player.y - 1])
		++path;
	if (map[player.x - 1][player.y])
		++path;
	return (path);
}

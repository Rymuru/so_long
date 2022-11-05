/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 01:50:23 by bcoenon           #+#    #+#             */
/*   Updated: 2022/11/05 03:38:32 by bcoenon          ###   ########.fr       */
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

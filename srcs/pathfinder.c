/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 01:50:23 by bcoenon           #+#    #+#             */
/*   Updated: 2022/11/08 15:50:16 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_path(char **copy, int x, int y)
{
	copy[x][y] = 'P';
	if (copy[x + 1][y] == 'C' || copy[x + 1][y] == '0' || copy[x + 1][y] == 'E')
		valid_path(copy, x + 1, y);
	if (copy[x - 1][y] == 'C' || copy[x - 1][y] == '0' || copy[x - 1][y] == 'E')
		valid_path(copy, x - 1, y);
	if (copy[x][y + 1] == 'C' || copy[x][y + 1] == '0' || copy[x][y + 1] == 'E')
		valid_path(copy, x, y + 1);
	if (copy[x][y - 1] == 'C' || copy[x][y - 1] == '0' || copy[x][y - 1] == 'E')
		valid_path(copy, x, y - 1);
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

char	*ft_strdup(char *s1)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = ft_strlen(s1) + 1;
	if (i - 1 == 0)
		return (NULL);
	str = malloc(len * sizeof(const char));
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**copy_map(char **map)
{
	int		x;
	int		y;
	char	**copy;

	x = 0;
	y = 0;
	while (map[x])
		++x;
	++x;
	copy = malloc(x * sizeof(char *));
	x = 0;
	while (map[x])
	{
		/*copy[x] = malloc((ft_strlen(map[x]) + 1) * sizeof(char));
		while (map[x][y])
		{
			copy[x][y] = map[x][y];
			++y;
		}
		copy[x][y] = '\0';
		y = 0;*/
		copy[x] = ft_strdup(map[x]);
		ft_printf("%s", copy[x]);
		++x;
	}
	copy[x] = NULL;
	return (copy);
}

int	ft_chuck(char **map)
{
	char		**copy;
	t_vector	player;

	if (find_things(map, 'P') != 1 || find_things(map, 'E') != 1
		|| find_things(map, 'C') < 1)
		return (1);
	//if (nice_walled_rectangle(map) == 1)
	//	return (1);
	copy = copy_map(map);
	player = find_player(map);
	valid_path(copy, player.x, player.y);
	if (find_things(copy, 'C') > 0 || find_things(copy, 'E') > 0)
		return (1);
	return (0);
}

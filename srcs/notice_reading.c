/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notice_reading.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:26:24 by bcoenon           #+#    #+#             */
/*   Updated: 2022/11/10 18:22:25 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*need to check if file or dir*/
/*need to check if .ber*/
/*need to check if map is valid*/

char	**read_map(char *path)
{
	int		i;
	int		file;
	char	**map;

	i = 0;
	file = open(path, O_RDONLY);
	map = malloc(sizeof(char *) * 22);
	if (!map)
		return (NULL);
	map[i] = get_map(file);
	while (map[i++] != NULL)
	{
		if (i > 21)
		{
			while (--i >= 0)
			{
				free(map[i]);
			}
			free(map);
			return (NULL);
		}
		map[i] = get_map(file);
	}
	close(file);
	return (map);
}

char	*out(char *line, char *buffer, int read_status)
{
	if (read_status == 0 && !line)
	{
		return (NULL);
	}
	line = ft_strnjoin_gnl(line, buffer);
	if (buffer)
	{
		resizer(buffer);
	}
	return (line);
}

int	end_of_line(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*resizer(char *buffer)
{
	int	i;
	int	bis;

	i = 0;
	bis = 0;
	while (buffer[bis] != '\n' && buffer[bis])
		bis++;
	if (buffer[bis] == '\n')
		bis++;
	while (buffer[bis])
	{
		buffer[i] = buffer[bis];
		i++;
		bis++;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*get_map(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			read_status;

	read_status = read(fd, buffer, 0);
	if (BUFFER_SIZE < 1 || fd < 0 || read_status == -1)
		return (NULL);
	line = NULL;
	if (ft_strlen(buffer) <= BUFFER_SIZE && ft_strlen(buffer) != 0)
		read_status = BUFFER_SIZE;
	else
	{
		read_status = read(fd, buffer, BUFFER_SIZE);
		buffer[read_status] = '\0';
	}
	while (read_status == BUFFER_SIZE && end_of_line(buffer) == 0)
	{
		line = ft_strnjoin_gnl(line, buffer);
		read_status = read(fd, buffer, BUFFER_SIZE);
		if (read_status == -1)
			return (NULL);
		buffer[read_status] = '\0';
	}
	return (out(line, buffer, read_status));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notice_reading_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:02:39 by bcoenon           #+#    #+#             */
/*   Updated: 2022/11/09 16:04:41 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strnjoin_gnl(char *line, char *buffer)
{
	int		i;
	int		j;
	char	*mem;

	if (!buffer)
		return (line);
	else if (!line)
		return (ft_strdup_gnl(buffer));
	i = -1;
	j = -1;
	mem = malloc(sizeof(char) * (ft_strlen(line) + ft_strlen (buffer) + 1));
	if (!mem)
		return (NULL);
	while (line[++i])
		mem[i] = line[i];
	while (buffer[++j] && buffer[j - 1] != '\n')
		mem[i + j] = buffer[j];
	free(line);
	mem[i + j] = '\0';
	return (mem);
}

char	*ft_strdup_gnl(char *s1)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1) + 1;
	str = malloc(len * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[i] && s1[i - 1] != '\n')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

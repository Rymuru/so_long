/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:30:49 by bcoenon           #+#    #+#             */
/*   Updated: 2022/11/08 18:46:20 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_image(void *mlx, t_image img)
{
	mlx_destroy_image(mlx, img.ptr);
	img.ptr = NULL;
	img.pixels = NULL;
}

void	free_ptr(t_program *p)
{
	if (p->mlx_p)
	{
		if (p->window)
		{
			mlx_destroy_window(p->mlx_p, p->window);
		}
		mlx_destroy_display(p->mlx_p);
		free(p->mlx_p);
		p->mlx_p = NULL;
	}
}

void	free_map(char **map)
{
	int	x;

	x = 0;
	while (map[x])
	{
		free(map[x]);
		++x;
	}
	free(map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:13:51 by bcoenon           #+#    #+#             */
/*   Updated: 2022/10/21 06:10:02 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*create_image(void *mlx, void *window)
{
	t_image	img;
	int		x_pos;
	int		y_pos;

	x_pos = 0;
	y_pos = 0;
	img = ft_new_sprite(mlx, "./assets/tree_cube.xpm");
	mlx_put_image_to_window(mlx, window, img.ptr, x_pos, y_pos);
	return (img.ptr);
}

/*void *create_map()
{
	
}*/

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels = mlx_get_data_addr(img.ptr, &img.bits, &img.line, &img.endian);
	return (img);
}

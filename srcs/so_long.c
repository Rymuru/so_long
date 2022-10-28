/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 03:08:59 by bcoenon           #+#    #+#             */
/*   Updated: 2022/10/28 11:25:44 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void	free_image(t_program *x)
{
	mlx_destroy_image(x->window.mlx_ptr, x->window.img.img);
	x->window.img.img = NULL;
	x->window.img.adr = NULL;
}*/

void	free_ptr(t_program *x)
{
	if (x->mlx_pointer)
	{
		if (x->window)
		{
			/*if (x->window.img.img)
				free_image(g);*/
			mlx_destroy_window(x->mlx_pointer, x->window);
		}
		mlx_destroy_display(x->mlx_pointer);
		free(x->mlx_pointer);
		x->mlx_pointer = NULL;
	}
}

int	close_map(t_program *x)
{
	free_ptr(x);
	exit(0);
}

int	main()
{
	t_program	x;

	x.width = 1000;
	x.height = 1000;
	x.name = "so_long";
	x.mlx_pointer = mlx_init();
	x.window = mlx_new_window(x.mlx_pointer, x.width, x.height, x.name);
	check_map("./maps/small_map.ber");
	create_image(x.mlx_pointer, x.window);
	mlx_hook(x.window, 33, 1L << 17, &close_map, &x);
	mlx_loop(x.mlx_pointer);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 03:08:59 by bcoenon           #+#    #+#             */
/*   Updated: 2022/11/02 19:37:57 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void	free_image(t_program *x)
{
	mlx_destroy_image(x->window.mlx_ptr, x->window.img.img);
	x->window.img.img = NULL;
	x->window.img.adr = NULL;
}*/

void	free_ptr(t_program *p)
{
	if (p->mlx_p)
	{
		if (p->window)
		{
			/*if (x->window.img.img)
				free_image(g);*/
			mlx_destroy_window(p->mlx_p, p->window);
		}
		mlx_destroy_display(p->mlx_p);
		free(p->mlx_p);
		p->mlx_p = NULL;
	}
}

int	close_map(t_program *x)
{
	free_ptr(x);
	exit(0);
}

int	main()
{
	t_data		x;

	x.map = check_map("./maps/small_map.ber");
	x.size = window_size(x.map);
	x.p.name = "so_long";
	x.p.mlx_p = mlx_init();
	x.p.window = mlx_new_window(x.p.mlx_p, x.size.y, x.size.x, x.p.name);
	create_map(x.p.mlx_p, x.p.window, x.map);
	mlx_hook(x.p.window, 33, 1L << 17, &close_map, &x.p);
	mlx_key_hook(x.p.window, &events, &x);
	mlx_loop(x.p.mlx_p);
}

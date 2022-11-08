/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 03:08:59 by bcoenon           #+#    #+#             */
/*   Updated: 2022/11/08 18:39:28 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_map(t_data *data)
{
	free_map(data->map);
	free_ptr(&data->p);
	exit(0);
}

int	main()
{
	t_data		x;

	x.map = check_map("./maps/small_map.ber");
	if (ft_chuck(x.map) == 1)
	{
		printf("bad map\n");
		exit (0);
	}
	x.size = window_size(x.map);
	x.p.name = "so_long";
	x.p.mlx_p = mlx_init();
	x.p.window = mlx_new_window(x.p.mlx_p, x.size.y, x.size.x, x.p.name);
	create_map(x.p.mlx_p, x.p.window, x.map);
	x.move = 0;
	mlx_hook(x.p.window, 33, 1L << 17, &close_map, &x.p);
	mlx_key_hook(x.p.window, &events, &x);
	mlx_loop(x.p.mlx_p);
}

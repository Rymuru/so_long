/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 03:08:59 by bcoenon           #+#    #+#             */
/*   Updated: 2022/11/09 15:22:59 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_map(t_data *data)
{
	free_map(data->map);
	free_ptr(&data->p);
	exit(0);
}

int	check_name(char *name)
{
	int	i;

	i = ft_strlen(name) - 1;
	if (i < 5)
		return (1);
	if (name[i] != 'r')
		return (1);
	--i;
	if (name[i] != 'e')
		return (1);
	--i;
	if (name[i] != 'b')
		return (1);
	--i;
	if (name[i] != '.')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data		x;

	if (ac != 2 || check_name(av[1]) != 0)
	{
		write(2, "usage: ./so_long <your_map>.ber\n", 33);
		return (1);
	}
	x.map = read_map(av[1]);
	if (ft_chuck(x.map) == 1)
	{
		write(2, "bad map\n", 8);
		exit (0);
	}
	x.size = window_size(x.map);
	x.p.name = "so_long";
	x.p.mlx_p = mlx_init();
	x.p.window = mlx_new_window(x.p.mlx_p, x.size.y, x.size.x, x.p.name);
	create_map(x.p.mlx_p, x.p.window, x.map);
	x.move = 0;
	mlx_hook(x.p.window, 33, 1L << 17, &close_map, &x);
	mlx_key_hook(x.p.window, &events, &x);
	mlx_loop(x.p.mlx_p);
}

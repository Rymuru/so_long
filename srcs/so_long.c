/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 03:08:59 by bcoenon           #+#    #+#             */
/*   Updated: 2022/11/10 18:33:48 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_manager(int error)
{
	write(2, "Error\n", 6);
	if (error == 1)
		write(2, "usage: ./so_long <your_map>.ber\n", 33);
	else if (error == 2)
		write(2, "missing asset\n", 14);
	else if (error == 3)
		write(2, "can't read map\n", 16);
	else if (error == 4)
		write(2, "bad map\n", 8);
	exit (0);
}

int	close_map(t_data *data)
{
	free_map(data->map);
	free_ptr(&data->p);
	exit(0);
}

int	check_name(char *name)
{
	int	i;
	int	fd;

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
	fd = open(name, O_DIRECTORY);
	close(fd);
	if (fd != -1)
		return (1);
	return (0);
}

int	check_assets(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	close(fd);
	if (fd == -1)
		return (1);
	fd = open(path, O_DIRECTORY);
	close(fd);
	if (fd != -1)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data		x;

	if (ac != 2 || check_name(av[1]) != 0)
		error_manager(1);
	if (check_assets(WALL) == 1 || check_assets(GROUND) == 1
		|| check_assets(KEY) == 1 || check_assets(EXIT) == 1
		|| check_assets(RED_LEFT) == 1 || check_assets(RED_RIGHT) == 1)
		error_manager(2);
	x.map = read_map(av[1]);
	if (x.map == NULL)
		error_manager(3);
	if (ft_chuck(x.map) == 1)
		error_manager(4);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 03:08:59 by bcoenon           #+#    #+#             */
/*   Updated: 2022/10/12 07:03:24 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main()
{
	t_program	x;

	x.width = 720;
	x.height = 480;
	x.name = "so_long";
	x.mlx_pointer = mlx_init;
	x.window = mlx_new_window(x.mlx_pointer, x.width, x.height, x.name);
	mlx_loop(x.mlx_pointer);
}

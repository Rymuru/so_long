/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 05:40:36 by bcoenon           #+#    #+#             */
/*   Updated: 2022/10/21 06:00:25 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "../libs/minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdint.h>
# include <fcntl.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <X11/Xlib.h>
# include <stdlib.h>

typedef struct s_program
{
	void	*mlx_pointer;
	void	*window;
	char	*name;
	int		width;
	int		height;
}	t_program;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_image
{
	void		*ptr;
	t_vector	size;
	char		*pixels;
	int			bits;
	int			line;
	int			endian;
}	t_image;

t_image	ft_new_sprite(void *mlx, char *path);
void	*create_image(void *mlx, void *window);

#endif
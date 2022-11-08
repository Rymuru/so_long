/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 05:40:36 by bcoenon           #+#    #+#             */
/*   Updated: 2022/11/08 18:37:49 by bcoenon          ###   ########.fr       */
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

# define BUFFER_SIZE 1024
# define WALL "./assets/tree.xpm"
# define GROUND "./assets/ground.xpm"
# define RED_LEFT "./assets/red-left.xpm"
# define RED_RIGHT "./assets/red-right.xpm"
# define EXIT "./assets/house-0.xpm"
# define KEY "./assets/key.xpm"

typedef struct s_program
{
	void	*mlx_p;
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

typedef struct s_data
{
	int			move;
	char		**map;
	t_program	p;
	t_vector	size;
	t_image		img;
}	t_data;

t_image		ft_new_sprite(void *mlx, char *path);
t_vector	window_size(char **map);
t_vector	find_player(char **map);

char		*out(char *line, char *buffer, int read_status);
char		*ft_strnjoin_gnl(char *line, char *buffer);
char		*resizer(char *buffer);
char		*get_map(int fd);
char		*ft_strdup_gnl(char *s1);
char		**check_map(char *path);

void		move_up(t_data *data);
void		move_left(t_data *data);
void		move_down(t_data *data);
void		move_right(t_data *data);
void		free_ptr(t_program *x);
void		free_map(char **map);
void		free_image(void *mlx, t_image img);
void		create_map(void *mlx, void *windows, char **map);
void		create_image(void *mlx, void *window, t_vector pos, char *path);

int			ft_chuck(char **map);
int			close_map(t_data *data);
int			end_of_line(char *buffer);
int			events(int key, t_data *data);
int			find_things(char **map, char c);
int			nice_walled_rectangle(char **map);

#endif
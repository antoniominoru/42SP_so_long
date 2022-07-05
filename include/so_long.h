/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 23:12:17 by aminoru-          #+#    #+#             */
/*   Updated: 2022/07/05 16:36:36 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// lib of 42 projects
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# define GAMEBITS 16
# define ESCAPE_KEY 0xff1b
# define W_KEY 0x0077
# define S_KEY 0x0073
# define A_KEY 0x0061
# define D_KEY 0x0064

typedef struct s_lines
{
	char			*line;
	struct s_lines	*next;
}	t_lines;

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	*map;
	size_t	map_width;
	size_t	map_height;
	size_t	map_length;
	size_t	player_pos;
	size_t	coins_left;
	size_t	move_count;
	t_img	tile;
	t_img	wall;
	t_img	coin;
	t_img	exit;
	t_img	player;
}	t_data;

char	*map_load(char *name_map, t_data *data);
void	map_check(t_data *data);
void	load_imgs(void *mlx, t_data *data);
int		handle_close(t_data *data);
int		handle_escape(int key, t_data *data);
int		player_move(int key, t_data *data);
int		render(t_data *data);

#endif

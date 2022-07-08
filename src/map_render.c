/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 02:55:39 by aminoru-          #+#    #+#             */
/*   Updated: 2022/07/08 15:39:55 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render(t_data *data)
{
	int		i;
	char	current_char;
	void	*img_ptr;

	i = -1;
	while (data->map[++i])
	{
		current_char = data->map[i];
		if (current_char == C_FLOOR)
			img_ptr = data->floor.img;
		if (current_char == C_WALL)
			img_ptr = data->wall.img;
		if (current_char == C_COIN)
			img_ptr = data->coin.img;
		if (current_char == C_EXIT)
			img_ptr = data->exit.img;
		if (current_char == C_PLAYER)
			img_ptr = data->player.img;
		mlx_put_image_to_window(data->mlx, data->win, img_ptr,
			i % data->map_width * GAMEBITS, i / data->map_width * GAMEBITS);
	}
	return (0);
}

void	load_imgs(void *mlx, t_data *data)
{
	data->floor.img = mlx_xpm_file_to_image(mlx, "assets/floor.xpm",
			&data->floor.width, &data->floor.height);
	data->wall.img = mlx_xpm_file_to_image(mlx, "assets/wall.xpm",
			&data->wall.width, &data->wall.height);
	data->coin.img = mlx_xpm_file_to_image(mlx, "assets/coin.xpm",
			&data->coin.width, &data->coin.height);
	data->player.img = mlx_xpm_file_to_image(mlx, "assets/player.xpm",
			&data->player.width, &data->player.height);
	data->exit.img = mlx_xpm_file_to_image(mlx, "assets/exit.xpm",
			&data->exit.width, &data->exit.height);
}

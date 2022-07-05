/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 02:55:39 by aminoru-          #+#    #+#             */
/*   Updated: 2022/07/05 14:29:30 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long"

int	render(t_data *data)
{
	
}

void	load_imgs(void *mlx, t_data *data)
{
	data->tile.img = mlx_xpm_file_to_image(mlx, "assets/tile.xpm", 
			&data->tile.width, &data->tile.height);
	data->wall.img = mlx_xpm_file_to_image(mlx, "assets/wall.xpm", 
			&data->wall.width, &data->wall.height);
	data->coin.img = mlx_xpm_file_to_image(mlx, "assets/coin.xpm", 
			&data->coin.width, &data->coin.height);
	data->player.img = mlx_xpm_file_to_image(mlx, "assets/player.xpm", 
			&data->player.width, &data->player.height);
	data->exit.img = mlx_xpm_file_to_image(mlx, "assets/exit.xpm", 
			&data->exit.width, &data->exit.height);
}
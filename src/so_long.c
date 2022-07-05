/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:25:40 by aminoru-          #+#    #+#             */
/*   Updated: 2022/07/05 14:40:21 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void clean_data(t_data *data);

int main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("ERROR\n The program receive one argument.\n");
		exit(1);
	}
	data->map = map_load(argv[1], &data);
	map_check(&data);
	data->move_count = 0;
	data.mlx = mlx_init();
	load_imgs(data.mlx, &data);
	data.win = mlx_new_window(data.mlx, data.map_width * GAMEBITS,
			data.map_height * GAMEBITS, argv[0])
	clean_data(&data);
}

void clean_data(t_data *data)
{
	mlx_destroy_image(data->mlx, data->tile.img);
	mlx_destroy_image(data->mlx, data->wall.img);
	mlx_destroy_image(data->mlx, data->coin.img);
	mlx_destroy_image(data->mlx, data->player.img);
	mlx_destroy_image(data->mlx, data->exit.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->map);
	free(data->mlx);
}
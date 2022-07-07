/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:25:40 by aminoru-          #+#    #+#             */
/*   Updated: 2022/07/07 19:06:54 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clean_data(t_data *data);
void		initial_error(int error);

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		initial_error(1);
	data.map = map_load(argv[1], &data);
	map_check(&data);
	data.move_count = 0;
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		initial_error(2);
	load_imgs(data.mlx, &data);
	data.win = mlx_new_window(data.mlx, data.map_width * GAMEBITS,
			data.map_height * GAMEBITS, argv[0]);
	if (data.win == NULL)
	{
		free(data.win);
		initial_error(3);
	}		
	mlx_hook(data.win, KEYPRESS, KEYPRESSMASK, player_move, &data);
	mlx_hook(data.win, KEYRELEASE, KEYRELEASEMASK, handle_escape, &data);
	mlx_hook(data.win, DESTROYNOTIFY, STRUCTURENOTIFYMASK, handle_close, &data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
	clean_data(&data);
}

static void	clean_data(t_data *data)
{
	mlx_destroy_image(data->mlx, data->floor.img);
	mlx_destroy_image(data->mlx, data->wall.img);
	mlx_destroy_image(data->mlx, data->coin.img);
	mlx_destroy_image(data->mlx, data->player.img);
	mlx_destroy_image(data->mlx, data->exit.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->map);
	free(data->mlx);
}

void	initial_error(int error)
{
	if (error == 1)
	{
		ft_printf("ERROR\n The program receive one argument.\n");
		exit(1);
	}
	else if (error == 2)
	{
		ft_printf("ERROR\n The program not initializer.\n");
		exit(1);
	}
	else if (error == 3)
	{
		ft_printf("ERROR\n Problem to create new window.\n");
		exit(1);
	}
}

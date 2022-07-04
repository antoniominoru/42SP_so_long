/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:25:40 by aminoru-          #+#    #+#             */
/*   Updated: 2022/07/04 22:57:54 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}
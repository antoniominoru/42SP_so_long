/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:44:07 by aminoru-          #+#    #+#             */
/*   Updated: 2022/07/08 15:39:42 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_close(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

int	handle_escape(int key, t_data *data)
{
	if (key == ESCAPE_KEY)
		mlx_loop_end(data->mlx);
	return (0);
}

int	player_move(int key, t_data *data)
{
	size_t	pos_new;

	pos_new = data->player_pos;
	if (key == W_KEY)
		pos_new += -data->map_width;
	else if (key == S_KEY)
		pos_new += data->map_width;
	else if (key == A_KEY)
		pos_new += -1;
	else if (key == D_KEY)
		pos_new += 1;
	if (pos_new == data->player_pos || data-> map[pos_new] == C_WALL
		|| (data->map[pos_new] == C_EXIT && data->coins_left))
		return (0);
	ft_printf("Count: %d\n", ++data->move_count);
	if (data->map[pos_new] == C_EXIT)
		mlx_loop_end(data->mlx);
	if (data->map[pos_new] == C_COIN)
		data->coins_left--;
	data->map[data->player_pos] = C_FLOOR;
	data->map[pos_new] = C_PLAYER;
	data->player_pos = pos_new;
	return (0);
}

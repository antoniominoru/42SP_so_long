/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:29:02 by aminoru-          #+#    #+#             */
/*   Updated: 2022/07/04 22:27:20 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_border_wall(t_data *data);
void	check_map_chars(t_data *data);
void	check_count(int p_count, int e_count, int c_count, char *map);
void	perror_exit(char *msg, char *map);

void	map_check(t_data *data)
{
	check_border_wall(data);
	check_map_chars(data);
}

void	check_border_wall(t_data *data)
{
	size_t	first_row;
	size_t	last_row;
	size_t	first_col;
	size_t	last_col;

	first_col = 0;
	last_row = data->map_length -1;
	while (first_row < data->map_width)
	{
		if (data->map[first_row++] != '1' || data->map[last_row--] != '1')
			perror_exit("Map should be surrounded by wall.", data->map);
	}
	first_col = 0;
	last_col = data->map_width - 1;
	while (first_col < data->map_length)
	{
		if (data->map[first_col] != '1' || data->map[last_col] != '1')
			perror_exit("Map should be surrounded by wall.", data->map);
		first_col += data->map_width;
		last_col += data->map_width;
	}
}

void	check_map_chars(t_data *data)
{
	size_t	pos;
	int		p_count;
	int		e_count;

	data->player_pos = 0;
	data->coins_left = 0;
	p_count = 0;
	e_count = 0;
	pos = 0;
	while (pos < data->map_length)
	{
		if (data->map[pos] == 'P')
		{
			data->player_pos = pos;
			p_count++;
		}
		else if (data->map[pos] == 'E')
			e_count++;
		else if (data->map[pos] == 'C')
			data->coins_left++;
		else if (data->map[pos] != '1' && data->map[pos] != '0')
			perror_exit("Invalid character found.", data->map);
		pos++;
	}	
	check_count(p_count, e_count, data->coins_left, data->map);
	
}

void	check_count(int p_count, int e_count, int c_count, char *map)
{
	if (!p_count)
		perror_exit("There should be one stating position.", map);
	if (!e_count)
		perror_exit("There should be one exit position.", map);
	if (!c_count)
		perror_exit("There should be at least one coin.", map);
	if (p_count > 1)
		perror_exit("Multiple starting positions.", map);
	if (e_count > 1)
		perror_exit("Multiple exit points.", map);
}

void	perror_exit(char *msg, char *map)
{
	ft_printf("Error\n%s\n", msg);
	free(map);
	exit(1);
}

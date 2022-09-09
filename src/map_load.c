/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:09:52 by aminoru-          #+#    #+#             */
/*   Updated: 2022/07/08 22:47:49 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int				open_map(char *name);
t_lines			*read_map(int fd, t_data *data);
char			*list_to_str(t_lines *list, t_data *data);
void			perror_exit(char *msg, t_lines *list, t_lines *last);

char	*map_load(char *name_map, t_data *data)
{
	int		fd;
	t_lines	*lines;
	char	*map;

	fd = open_map(name_map);
	lines = read_map(fd, data);
	map = list_to_str(lines, data);
	return (map);
}

int	open_map(char *name)
{
	size_t	nlen;
	int		fd;

	nlen = ft_strlen(name);
	if (ft_strncmp(&name[nlen -4], ".ber", 4))
	{
		ft_printf("Error\nWrong file extension.\n");
		exit(1);
	}
	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nUnable to open given map file.\n");
		exit(1);
	}
	return (fd);
}

t_lines	*read_map(int fd, t_data *data)
{
	t_lines		*list;
	t_lines		*current;

	data->error = 0;
	data->map_height = 0;
	data->map_length = 0;
	list = malloc(sizeof(t_lines));
	list->line = get_next_line(fd);
	if (!list->line)
		perror_exit("Empty map.", list, list);
	data->map_width = ft_strlen(list->line) - 1;
	current = list;
	while (current->line)
	{
		if (data->map_width != ft_strlen(current->line) - 1)
			data->error = 1;
		data->map_height++;
		data->map_length += data->map_width;
		current->next = malloc(sizeof(t_lines));
		current = current->next;
		current->line = get_next_line(fd);
	}
	if (data->error == 1)
		perror_exit("Map should be a rectangle.", list, current);
	return (list);
}

char	*list_to_str(t_lines *list, t_data *data)
{
	char	*str;
	size_t	i;
	t_lines	*current;

	str = malloc(data->map_length + 1);
	i = 0;
	current = list;
	while (current->line)
	{
		ft_strlcpy(str + i, current->line, data->map_width + 1);
		i += data->map_width;
		list = list->next;
		free(current->line);
		free(current);
		current = list;
	}
	free(current);
	return (str);
}

void	perror_exit(char *msg, t_lines *list, t_lines *last)
{
	t_lines	*current;

	ft_printf("Error\n%s\n", msg);
	current = list;
	while (current != last)
	{
		list = list->next;
		free(current->line);
		free(current);
		current = list;
	}
	free(current->line);
	free(current);
	exit(1);
}

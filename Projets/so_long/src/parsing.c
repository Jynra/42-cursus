/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <ellucas@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:17:26 by ellucas           #+#    #+#             */
/*   Updated: 2025/02/04 16:49:57 by ellucas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	read_map(char *path, t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	if (!map_size(path, data))
		return (0);
	if (!allocate_map(data))
		return (0);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		ft_strlcpy(data->map[i], line, data->map_width + 1);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	count_collectibles(data);
	check_map(data);
	return (1);
}

void	get_width(char *line, t_data *data)
{
	if (line[ft_strlen(line) - 1] == '\n')
		data->map_width = ft_strlen(line) - 1;
	else
		data->map_width = ft_strlen(line);
}

int	map_size(char *path, t_data *data)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	data->map_height = 0;
	line = get_next_line(fd);
	if (line)
		get_width(line, data);
	while (line)
	{
		if (!check_rect(line, data->map_width))
		{
			free(line);
			clear_buffer(fd);
			err("Error : Map non rectangulaire\n");
		}
		data->map_height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	allocate_map(t_data *data)
{
	int	i;

	data->map = malloc(sizeof(char *) * (data->map_height + 1));
	if (!data->map)
		return (0);
	i = 0;
	while (i < data->map_height)
	{
		data->map[i] = malloc(sizeof(char) * (data->map_width + 1));
		if (!data->map[i])
		{
			while (i > 0)
			{
				i--;
				free(data->map[i]);
			}
			free(data->map);
			return (0);
		}
		i++;
	}
	data->map[data->map_height] = NULL;
	return (1);
}

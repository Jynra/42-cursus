/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <ellucas@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:27:25 by ellucas           #+#    #+#             */
/*   Updated: 2025/01/28 16:13:16 by ellucas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(t_data *data)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (data->map_height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < data->map_height)
	{
		copy[i] = ft_strdup(data->map[i]);
		if (!copy[i])
		{
			while (i > 0)
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[data->map_height] = NULL;
	return (copy);
}

void	flood_fill(char **map, int x, int y, t_data *data)
{
	if (x < 0 || x >= data->map_width || y < 0 || y >= data->map_height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, data);
	flood_fill(map, x - 1, y, data);
	flood_fill(map, x, y + 1, data);
	flood_fill(map, x, y - 1, data);
}

void	find_player(t_data *data, int *x, int *y)
{
	*x = 0;
	*y = 0;
	while (*y < data->map_height)
	{
		*x = 0;
		while (*x < data->map_width)
		{
			if (data->map[*y][*x] == 'P')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

void	check_path(t_data *data)
{
	char	**temp_map;
	int		player_x;
	int		player_y;
	int		i;
	int		j;

	temp_map = copy_map(data);
	find_player(data, &player_x, &player_y);
	flood_fill(temp_map, player_x, player_y, data);
	i = -1;
	while (++i < data->map_height)
	{
		j = -1;
		while (++j < data->map_width)
		{
			if ((temp_map[i][j] == 'C' || temp_map[i][j] == 'E'))
			{
				ft_printf("ERROR : Path impossible\n");
				free_map(temp_map, data);
				free_map(data->map, data);
				exit(1);
			}
		}
	}
	free_map(temp_map, data);
}

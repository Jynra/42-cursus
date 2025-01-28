/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <ellucas@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:14:09 by ellucas           #+#    #+#             */
/*   Updated: 2025/01/28 16:14:48 by ellucas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_data *data)
{
	int	i;
	int	j;
	int	player;
	int	out;

	i = 0;
	player = 0;
	out = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j] == 'P')
				player++;
			if (data->map[i][j] == 'E')
				out++;
			j++;
		}
		i++;
	}
	check_elements(player, out, data);
	check_walls(data);
	check_path(data);
}

void	check_elements(int player, int out, t_data *data)
{
	int	i;
	int	j;

	if (player != 1 || out != 1 || data->coin == 0)
	{
		ft_printf("ERROR : Invalid map elements\n");
		free_map(data->map, data);
		exit(1);
	}
	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (!ft_strchr("01PEC", data->map[i][j]))
			{
				ft_printf("ERROR : Caractere non valide\n");
				free_map(data->map, data);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	check_walls(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_width)
	{
		if (data->map[0][i] != '1' ||
		data->map[data->map_height - 1][i] != '1')
		{
			ft_printf("ERROR : La map doit etre entoure de mur\n");
			free_map(data->map, data);
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < data->map_height)
	{
		if (data->map[i][0] != '1' ||
		data->map[i][data->map_width - 1] != '1')
		{
			ft_printf("ERROR : La map doit etre entoure de mur\n");
			free_map(data->map, data);
			exit(1);
		}
		i++;
	}
}

int	check_rect(char *line, int width)
{
	int	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		len--;
	return (len == width);
}

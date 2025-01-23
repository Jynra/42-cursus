/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <ellucas@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:14:09 by ellucas           #+#    #+#             */
/*   Updated: 2025/01/23 15:19:19 by ellucas          ###   ########.fr       */
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
}

void	check_elements(int player, int out, t_data *data)
{
	if (player != 1 || out != 1 || data->collectibles == 0)
	{
		ft_printf("Error : Invalid map elements\n");
		exit(1);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <ellucas@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:30:48 by ellucas           #+#    #+#             */
/*   Updated: 2025/01/28 13:27:45 by ellucas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_game(t_data *data)
{
	mlx_destroy_image(data->mlx, data->player_img);
	mlx_destroy_image(data->mlx, data->wall_img);
	mlx_destroy_image(data->mlx, data->floor_img);
	mlx_destroy_image(data->mlx, data->collect_img);
	mlx_destroy_image(data->mlx, data->exit_img);
	mlx_destroy_image(data->mlx, data->close_img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free_map(data->map, data);
	free(data->mlx);
}

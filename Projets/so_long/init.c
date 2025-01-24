/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <ellucas@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:47:45 by ellucas           #+#    #+#             */
/*   Updated: 2025/01/24 02:06:48 by ellucas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		exit(1);
	data->win = mlx_new_window(data->mlx, data->map_width * SPRITE_SIZE,
			data->map_height * SPRITE_SIZE, "so_long");
	if (data->win == NULL)
		exit(2);
}

void	init_textures(t_data *data)
{
	data->player_img = mlx_xpm_file_to_image(data->mlx, "resources/player.xpm",
			&data->assets_width, &data->assets_height);
	if (data->player_img == NULL)
		exit(3);
	data->floor_img = mlx_xpm_file_to_image(data->mlx, "resources/floor.xpm",
			&data->assets_width, &data->assets_height);
	if (data->floor_img == NULL)
		exit(1);
	data->wall_img = mlx_xpm_file_to_image(data->mlx, "resources/wall.xpm",
			&data->assets_width, &data->assets_height);
	if (data->wall_img == NULL)
		exit(1);
	data->collect_img = mlx_xpm_file_to_image(data->mlx,
			"resources/collect.xpm", &data->assets_width, &data->assets_height);
	if (data->collect_img == NULL)
		exit(1);
	data->exit_img = mlx_xpm_file_to_image(data->mlx, "resources/exit.xpm",
			&data->assets_width, &data->assets_height);
	if (data->exit_img == NULL)
		exit(1);
	data->exit_close_img = mlx_xpm_file_to_image(data->mlx,
			"resources/exit_close.xpm",
			&data->assets_width, &data->assets_height);
	if (data->exit_close_img == NULL)
		exit(1);
}

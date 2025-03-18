/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <ellucas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:17:08 by ellucas           #+#    #+#             */
/*   Updated: 2025/03/18 14:28:35 by ellucas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_sprite(t_data *data, int x, int y)
{
	if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall_img,
			x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->floor_img,
			x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (data->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->collect_img,
			x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (data->map[y][x] == 'E' && data->collected != data->coin)
		mlx_put_image_to_window(data->mlx, data->win, data->close_img,
			x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (data->map[y][x] == 'E' && data->collected == data->coin)
		mlx_put_image_to_window(data->mlx, data->win, data->exit_img,
			x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (data->map[y][x] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->player_img,
			x * SPRITE_SIZE, y * SPRITE_SIZE);
		data->pos_x = x * SPRITE_SIZE;
		data->pos_y = y * SPRITE_SIZE;
	}
}

void	render(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	mlx_clear_window(data->mlx, data->win);
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			put_sprite(data, x, y);
			x++;
		}
		y++;
	}
}

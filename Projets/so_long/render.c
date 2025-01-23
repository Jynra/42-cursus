/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <ellucas@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:17:08 by ellucas           #+#    #+#             */
/*   Updated: 2025/01/23 21:05:37 by ellucas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render(t_data *data)
{
	int	x;
	int	y;

	//ft_printf("DEBUG: Starting render\n");
	y = 0;
	mlx_clear_window(data->mlx, data->win);
	//ft_printf("DEBUG: Clear window\n");
	while (y < data->map_height)
	{
		x = 0;
		//ft_printf("DEBUG: Line %d\n", y);
		while (x < data->map_width)
		{
			//ft_printf("DEBUG: Position %d,%d = %c\n", x, y, data->map[y][x]);
			if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->wall_img, x * SPRITE_SIZE, y * SPRITE_SIZE);
			else if (data->map[y][x] == '0') 
				mlx_put_image_to_window(data->mlx, data->win, data->floor_img, x * SPRITE_SIZE, y * SPRITE_SIZE);
			else if (data->map[y][x] == 'C') 
				mlx_put_image_to_window(data->mlx, data->win, data->collect_img, x * SPRITE_SIZE, y * SPRITE_SIZE);
			else if (data->map[y][x] == 'E' && data->collected != data->collectibles) 
				mlx_put_image_to_window(data->mlx, data->win, data->exit_close_img, x * SPRITE_SIZE, y * SPRITE_SIZE);
			else if (data->map[y][x] == 'E' && data->collected == data->collectibles)
				mlx_put_image_to_window(data->mlx, data->win, data->exit_img, x * SPRITE_SIZE, y * SPRITE_SIZE);
			else if (data->map[y][x] == 'P')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->player_img, x * SPRITE_SIZE, y * SPRITE_SIZE);
				data->pos_x = x * SPRITE_SIZE;
				data->pos_y = y * SPRITE_SIZE;
			}
			x++;
		}
		y++;
	}
	//ft_printf("DEBUG: Rendu complet\n");
	//mlx_put_image_to_window(data->mlx, data->win, data->player_img, data->pos_x, data->pos_y);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <ellucas@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:57:58 by ellucas           #+#    #+#             */
/*   Updated: 2025/01/23 14:24:51 by ellucas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_data *data, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = data->pos_x / SPRITE_SIZE + dx;
	new_y = data->pos_y / SPRITE_SIZE + dy;
	if (data->map[new_y][new_x] != '1') //Si c'est pas un mur le player peu avancer
	{
		if (data->map[new_y][new_x] == 'E')
		{
			if (data->collected == data->collectibles)
			{
				ft_printf("SUCCESS\n");
				close_window(data);
			}
			ft_printf("Collect all COINS before leave\n");
			return ;
		}
		if (data->map[new_y][new_x] == 'C')
			data->collected++;
		data->map[data->pos_y / SPRITE_SIZE][data->pos_x / SPRITE_SIZE] = '0'; //Remplace le bloc traverser par un bloc de sol
		data->map[new_y][new_x] = 'P';
		data->pos_x = new_x * SPRITE_SIZE;
		data->pos_y = new_y * SPRITE_SIZE;
		data->moves++;
		ft_printf("Moves: %d\n", data->moves);
	}
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		move_player(data, 0, -1);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(data, 0, 1);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(data, -1, -0);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(data, 1, 0);
	if (keycode == KEY_ESC)
		close_window(data);
	render(data);
	//ft_printf("Touche = %d  Position : x = %d, y = %d\n", keycode, data->pos_x, data->pos_y);
	return (0);
}

void	count_collectibles(t_data *data)
{
	int	x;
	int	y;

	data->collectibles = 0;
	data->collected = 0;
	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->map[y][x] == 'C')
				data->collectibles++;
			x++;
		}
		y++;
	}
}

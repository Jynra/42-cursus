/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <ellucas@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:57:58 by ellucas           #+#    #+#             */
/*   Updated: 2025/01/21 20:53:32 by ellucas          ###   ########.fr       */
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
		data->map[data->pos_y / SPRITE_SIZE][data->pos_x / SPRITE_SIZE] = '0'; //Remplace le bloc traverser par un bloc de sol
		data->map[new_y][new_x] = 'P';
		data->pos_x = new_x * SPRITE_SIZE;
		data->pos_y = new_y * SPRITE_SIZE;
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
	ft_printf("Touche = %d  Position : x = %d, y = %d\n", keycode, data->pos_x, data->pos_y);
	return (0);
}

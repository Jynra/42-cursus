/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <ellucas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:57:58 by ellucas           #+#    #+#             */
/*   Updated: 2025/03/18 16:11:18 by ellucas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	handle_exit(t_data *data)
{
	if (data->collected == data->coin)
	{
		ft_printf("SUCCESS\n");
		close_window(data);
	}
	ft_printf("Collect all COINS before leave\n");
}

void	update_exit(t_data *data)
{
	if (data->collected == data->coin)
		mlx_put_image_to_window(data->mlx, data->win, data->exit_img,
			data->pos_x, data->pos_y);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->close_img,
			data->pos_x, data->pos_y);
}

void	update_player_pos(t_data *data, int new_x, int new_y)
{
	int			is_exit;
	static int	on_exit = 0;

	is_exit = (data->map[new_y][new_x] == 'E');
	if (on_exit && !is_exit)
		update_exit(data);
	else
	{
		data->map[data->pos_y / SPRITE_SIZE][data->pos_x / SPRITE_SIZE] = '0';
		mlx_put_image_to_window(data->mlx, data->win, data->floor_img,
			data->pos_x, data->pos_y);
	}
	data->pos_x = new_x * SPRITE_SIZE;
	data->pos_y = new_y * SPRITE_SIZE;
	mlx_put_image_to_window(data->mlx, data->win, data->player_img,
		data->pos_x, data->pos_y);
	if (!is_exit)
		data->map[new_y][new_x] = 'P';
	on_exit = is_exit;
	data->moves++;
	ft_printf("Moves: %d\n", data->moves);
}

void	move_player(t_data *data, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = data->pos_x / SPRITE_SIZE + dx;
	new_y = data->pos_y / SPRITE_SIZE + dy;
	if (data->map[new_y][new_x] != '1')
	{
		if (data->map[new_y][new_x] == 'E')
		{
			handle_exit(data);
			if (data->collected != data->coin)
				update_player_pos(data, new_x, new_y);
			return ;
		}
		if (data->map[new_y][new_x] == 'C')
			data->collected++;
		update_player_pos(data, new_x, new_y);
	}
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		move_player(data, 0, -1);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(data, 0, 1);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(data, -1, 0);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(data, 1, 0);
	if (keycode == KEY_ESC)
		close_window(data);
	if (data->collected == data->coin)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->exit_img,
			data->exit_x * SPRITE_SIZE, data->exit_y * SPRITE_SIZE);
	}
	return (0);
}

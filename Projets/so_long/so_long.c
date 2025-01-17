/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <ellucas@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:59:29 by ellucas           #+#    #+#             */
/*   Updated: 2025/01/18 13:46:28 by ellucas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		if (data->pos_y - 10 >= 0)
			data->pos_y -= 10;
	}
	if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		if (data->pos_y + 10 + data->player_height <= WIDTH)
			data->pos_y += 10;
	}
	if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		if (data->pos_x - 10 >= 0)
			data->pos_x -= 10;
	}
	if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		if (data->pos_x + 10 + data->player_width <= LENGTH)
			data->pos_x += 10;
	}
	if (keycode == KEY_ESC)
		close_window(data);
	render(data);
	printf("Position : x = %d, y = %d\n", data->pos_x, data->pos_y);
	return (0);
	
}

void	render(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->player_img, data->pos_x, data->pos_y);
}

int	main(void)
{
	t_data	data;

	if (!read_map("maps/map.ber"))
	{
		ft_printf("Error\nCannot read map file\n");
		return (1);
	}
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (1);
	data.win = mlx_new_window(data.mlx, LENGTH, WIDTH, "so_long");
	if (data.win == NULL)
		return (2);
	data.player_img = mlx_xpm_file_to_image(data.mlx, "resources/player.xpm", &data.player_width, &data.player_height);
	if (data.player_img == NULL)
		return (3);
	data.pos_x = 900;
	data.pos_y = 200;
	render(&data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_hook(data.win, 2, 1L<<0, handle_keypress, &data);
	mlx_loop(data.mlx);
	return (0);
}

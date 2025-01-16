/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <ellucas@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:59:29 by ellucas           #+#    #+#             */
/*   Updated: 2025/01/16 17:00:40 by ellucas          ###   ########.fr       */
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
		data->pos_y -= 10;
	if (keycode == KEY_S || keycode == KEY_DOWN)
		data->pos_y += 10;
	if (keycode == KEY_A || keycode == KEY_LEFT)
		data->pos_x -= 10;
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		data->pos_x += 10;
	if (keycode == KEY_ESC)
		close_window(data);
	printf("Position : x = %d, y = %d\n", data->pos_x, data->pos_y);
	return (0);
	
}

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (1);
	data.win = mlx_new_window(data.mlx, LENGTH, WIDTH, "la fenetre du jeu");
	if (data.win == NULL)
		return (2);
	data.player_img = mlx_xpm_file_to_image(data.mlx, "resources/player.xpm", &data.player_width, &data.player_height);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_hook(data.win, 2, 1L<<0, handle_keypress, &data);
	mlx_loop(data.mlx);
	return (0);
}

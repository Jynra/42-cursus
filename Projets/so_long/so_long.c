/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <ellucas@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:59:29 by ellucas           #+#    #+#             */
/*   Updated: 2025/01/23 15:07:20 by ellucas          ###   ########.fr       */
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

int	main(int ac, char **av)
{
	(void)	ac;
	t_data	data;

	data.moves = 0;
/* tests de bon fonctionnement */
	if (!read_map(av[1],&data))
	{
		ft_printf("Error\nCannot read map file\n");
		return (1);
	}
	//check_map(&data);
	//ft_printf("\nmap dimensions : L= %d , H= %d\n", data.map_width, data.map_height);
	if (data.map)
		ft_printf("Allocation de la map reussi\n");
	else
		ft_printf("Allocation de la map echoue\n");
/* debut du main */
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (1);
	data.win = mlx_new_window(data.mlx, data.map_width * SPRITE_SIZE, data.map_height * SPRITE_SIZE, "so_long");
	if (data.win == NULL)
		return (2);
	data.player_img = mlx_xpm_file_to_image(data.mlx, "resources/player.xpm", &data.assets_width, &data.assets_height);
	if (data.player_img == NULL)
		return (3);
	data.floor_img = mlx_xpm_file_to_image(data.mlx, "resources/floor.xpm", &data.assets_width, &data.assets_height);
	if (data.floor_img == NULL)
		return (1);
	data.wall_img = mlx_xpm_file_to_image(data.mlx, "resources/wall.xpm", &data.assets_width, &data.assets_height);
	if (data.wall_img == NULL)
		return (1);
	data.collect_img = mlx_xpm_file_to_image(data.mlx, "resources/collect.xpm", &data.assets_width, &data.assets_height);
	if (data.collect_img == NULL)
		return (1);
	data.exit_img = mlx_xpm_file_to_image(data.mlx, "resources/exit.xpm", &data.assets_width, &data.assets_height);
	if (data.exit_img == NULL)
		return (1);
	data.exit_close_img = mlx_xpm_file_to_image(data.mlx, "resources/exit_close.xpm", &data.assets_width, &data.assets_height);
	if (data.exit_close_img == NULL)
		return (1);
	//data.pos_x = 900;
	//data.pos_y = 200;
	render(&data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_hook(data.win, 2, 1L<<0, handle_keypress, &data);
	mlx_loop(data.mlx);
	return (0);
}

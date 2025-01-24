/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <ellucas@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:59:29 by ellucas           #+#    #+#             */
/*   Updated: 2025/01/24 01:55:37 by ellucas          ###   ########.fr       */
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
	t_data	data;

	(void) ac;
	data.moves = 0;
/* tests de bon fonctionnement */
	if (!read_map(av[1], &data))
	{
		ft_printf("Error : Cannot read map file\n");
		return (1);
	}
	//check_map(&data);
	//ft_printf("\nmap dimensions : L= %d , H= %d\n", data.map_width, data.map_height);
	if (data.map)
		ft_printf("Allocation de la map reussi\n");
	else
		ft_printf("Allocation de la map echoue\n");
	//data.pos_x = 900;
	//data.pos_y = 200;
	init_mlx(&data);
	init_textures(&data);
	render(&data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_hook(data.win, 2, 1L << 0, handle_keypress, &data);
	mlx_loop(data.mlx);
	return (0);
}

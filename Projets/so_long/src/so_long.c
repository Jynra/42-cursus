/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <ellucas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:59:29 by ellucas           #+#    #+#             */
/*   Updated: 2025/03/18 12:54:10 by ellucas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(t_data *data)
{
	free_game(data);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	(void) ac;
	data.moves = 0;
	if (ac != 2)
		err("ERROR : Syntax must be -> ./so_long 'map_file.ber'\n");
	check_filetype(av[1]);
	if (!read_map(av[1], &data))
	{
		ft_printf("Error : Cannot read this map file\n");
		return (1);
	}
	if (data.map)
		ft_printf("Map allocation sucess\n");
	else
		err("Map allocation failed\n");
	init_mlx(&data);
	init_textures(&data);
	render(&data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_hook(data.win, 2, 1L << 0, handle_keypress, &data);
	mlx_loop(data.mlx);
	return (0);
}

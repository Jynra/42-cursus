/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <ellucas@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:58:10 by ellucas           #+#    #+#             */
/*   Updated: 2025/01/23 20:26:24 by ellucas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

/* Resolution */
//# define LENGTH			1280
//# define WIDTH			720

/* Sprites infod=s */
# define SPRITE_SIZE	80

/* Keybind */
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100
# define KEY_UP			65362
# define KEY_DOWN		65364
# define KEY_LEFT		65361
# define KEY_RIGHT		65363
# define KEY_ESC		65307

/* Map file */
//# define MAP			"maps/wrong_map.ber"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*player_img;
	void	*wall_img;
	void	*floor_img;
	void	*collect_img;
	void	*exit_img;
	void	*exit_close_img;
	int		pos_x;
	int		pos_y;
	int		assets_width;
	int		assets_height;
	char	**map;
	int		map_width;
	int		map_height;
	int		collectibles;
	int		collected;
	int		moves;

}				t_data;

int	close_window(t_data *data);
void	render(t_data *data);
int	read_map(char *path, t_data *data);
int	map_size(char *path, t_data *data);
int	allocate_map(t_data *data);
void	check_map(t_data *data);
int	handle_keypress(int keycode, t_data *data);
void	count_collectibles(t_data *data);
void	check_elements(int player, int out, t_data *data);
void	check_walls(t_data *data);
void	init_textures(t_data *data);
void	init_mlx(t_data *data);

#endif
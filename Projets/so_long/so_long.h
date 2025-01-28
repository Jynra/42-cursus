/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <ellucas@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:58:10 by ellucas           #+#    #+#             */
/*   Updated: 2025/01/28 16:43:28 by ellucas          ###   ########.fr       */
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

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*player_img;
	void	*wall_img;
	void	*floor_img;
	void	*collect_img;
	void	*exit_img;
	void	*close_img;
	int		pos_x;
	int		pos_y;
	int		assets_width;
	int		assets_height;
	char	**map;
	int		map_width;
	int		map_height;
	int		coin;
	int		collected;
	int		moves;
}				t_data;

int		close_window(t_data *data);
void	render(t_data *data);
int		read_map(char *path, t_data *data);
int		map_size(char *path, t_data *data);
int		allocate_map(t_data *data);
void	check_map(t_data *data);
int		handle_keypress(int keycode, t_data *data);
void	count_collectibles(t_data *data);
void	check_elements(int player, int out, t_data *data);
void	check_walls(t_data *data);
void	init_textures(t_data *data);
void	init_mlx(t_data *data);
void	handle_exit(t_data *data);
int		check_rect(char *line, int width);
char	**copy_map(t_data *data);
void	flood_fill(char **map, int x, int y, t_data *data);
void	find_player(t_data *data, int *x, int *y);
void	check_path(t_data *data);
void	free_map(char **map, t_data *data);
void	free_game(t_data *data);
void	put_sprite(t_data *data, int x, int y);
void	err(char *str);

#endif
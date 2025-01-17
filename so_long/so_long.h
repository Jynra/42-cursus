/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <ellucas@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:58:10 by ellucas           #+#    #+#             */
/*   Updated: 2025/01/17 17:57:27 by ellucas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

/* Resolution */
# define LENGTH			1280
# define WIDTH			720

/* Keybind */
# define KEY_W          119
# define KEY_A          97
# define KEY_S          115
# define KEY_D          100
# define KEY_UP         65362
# define KEY_DOWN       65364
# define KEY_LEFT       65361
# define KEY_RIGHT      65363
# define KEY_ESC        65307

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		pos_x;
	int		pos_y;
	void	*player_img;
	int		player_width;
	int		player_height;
}				t_data;

int	close_window(t_data *data);
void	render(t_data *data);

#endif
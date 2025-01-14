# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ellucas <ellucas@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 13:35:27 by ellucas           #+#    #+#              #
#    Updated: 2025/01/14 15:14:21 by ellucas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = window

MLX_PATH = minilibx-linux
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lX11 -lXext

SRC = main.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -I$(MLX_PATH) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_PATH) -c $< -o $@
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
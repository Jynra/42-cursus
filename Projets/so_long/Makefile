# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ellucas <ellucas@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 13:35:27 by ellucas           #+#    #+#              #
#    Updated: 2025/01/18 13:34:13 by ellucas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

MLX_PATH = minilibx-linux
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lX11 -lXext

SRC = so_long.c parsing.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	$(CC) $(OBJ) -I$(MLX_PATH) -I$(LIBFT_PATH) $(MLX_FLAGS) -L$(LIBFT_PATH) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_PATH)$(LIBFT_PATH) -c $< -o $@
clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
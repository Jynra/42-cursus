# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ellucas <ellucas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 13:35:27 by ellucas           #+#    #+#              #
#    Updated: 2025/03/12 14:28:06 by ellucas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = includes/
MLX_DIR = $(INC_DIR)minilibx-linux/
LIBFT_DIR = $(INC_DIR)libft/
LIBFT = $(LIBFT_DIR)/libft.a
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext
INCLUDES = -I$(INC_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR)

CC = gcc
SRC_FILES = so_long.c render.c parsing.c move.c init.c free.c flood_fill.c errors.c check_map.c

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJ)
	make -C $(LIBFT_DIR)
	$(CC) $(OBJ) $(INCLUDES) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
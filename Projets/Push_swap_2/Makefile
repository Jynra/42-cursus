# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ellucas <ellucas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/24 14:44:44 by ellucas           #+#    #+#              #
#    Updated: 2025/03/26 13:19:13 by ellucas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# Directories
INC_DIR = inc/
LIBFT_DIR = $(INC_DIR)libft/
LIBFT = $(LIBFT_DIR)libft.a
SRC_DIR = srcs/
OBJ_DIR = obj/

CFLAGS = -Wall -Wextra -Werror -g

CC = gcc

OPTIONS_DIR = $(wildcard $(SRC_DIR)options/*.c)

ACTIONS_DIR = $(wildcard $(SRC_DIR)actions/*.c) #wildcard permet de trouver les fichier source in DIR

PUSH_SWAP_DIR = $(wildcard $(SRC_DIR)*.c)

SRCS = $(OPTIONS_DIR) $(ACTIONS_DIR) $(PUSH_SWAP_DIR)
OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
		@mkdir -p $(@D)
		$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJS)
		make -C $(LIBFT_DIR)
		$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
		make -C $(LIBFT_DIR)

#wasm: 
#	docker run --rm -v $(shell pwd):/src emscripten/emsdk emcc $(SRCS) -o $(NAME).wasm

clean:
		make -C $(LIBFT_DIR) clean
		rm -rf $(OBJ_DIR)

fclean: clean
		make -C $(LIBFT_DIR) fclean
		rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
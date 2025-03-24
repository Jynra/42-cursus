# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ellucas <ellucas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/24 14:44:44 by ellucas           #+#    #+#              #
#    Updated: 2025/03/24 15:59:30 by ellucas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# Directories
INC_DIR = inc/
LIBFT_DIR = $(INC_DIR)libft/
LIBFT = $(LIBFT_DIR)libft.a
SRC_DIR = srcs/
OBJ_DIR = obj/

CFLAGS = -Wall -Wextra -Werror

CC = gcc

ACTIONS_DIR = $(wildcard $(SRC_DIR)actions/*.c) #wildcard permet de trouver les fichier source in DIR

PUSH_SWAP_DIR = $(wildcard $(SRC_DIR)*.c)

SRCS = $(ACTIONS_DIR) $(PUSH_SWAP_DIR)
OBJ = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)



clean:
		make -c $(LIBFT_DIR) clean
		rm -rf $(OBJ_DIR)
fclean: clean
		make -c $(LIBFT_DIR) fclean
		rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
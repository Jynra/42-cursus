# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ellucas <ellucas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 12:03:54 by ellucas           #+#    #+#              #
#    Updated: 2025/02/24 15:55:27 by ellucas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= server
CLIENT	= client
SRC_DIR = src/
INC_DIR = includes/
LIBFT_DIR = $(INC_DIR)libft/
LIBFT	= $(LIBFT_DIR)libft.a
SRC_SERVER = $(SRC_DIR)server.c $(SRC_DIR)error.c
SRC_CLIENT = $(SRC_DIR)client.c $(SRC_DIR)error.c

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME) $(CLIENT)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_SERVER) -L$(LIBFT_DIR) -lft -o $(NAME)

$(CLIENT): $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_CLIENT) -L$(LIBFT_DIR) -lft -o $(CLIENT)

clean:
	make -C $(LIBFT_DIR) clean

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
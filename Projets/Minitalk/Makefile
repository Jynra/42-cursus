# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ellucas <ellucas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 12:03:54 by ellucas           #+#    #+#              #
#    Updated: 2025/03/06 13:59:59 by ellucas          ###   ########.fr        #
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
INCLUDES = -I$(INC_DIR)

all: $(NAME) $(CLIENT)

$(NAME):
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC_SERVER) -L$(LIBFT_DIR) -lft -o $(NAME)

$(CLIENT):
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC_CLIENT) -L$(LIBFT_DIR) -lft -o $(CLIENT)

clean:
	@echo "Cleaning object files..."

fclean: clean
	rm -f $(NAME) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
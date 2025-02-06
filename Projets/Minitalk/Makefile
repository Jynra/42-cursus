# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ellucas <ellucas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 12:03:54 by ellucas           #+#    #+#              #
#    Updated: 2025/02/06 12:38:17 by ellucas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
CLIENT = client
LIBFT = libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME) $(CLIENT)

$(LIBFT):
	make -C libft

$(NAME): $(LIBFT)
	$(CC) $(CFLAGS) server.c - L./libft -lft -o $(NAME)

$(CLIENT): $(LIBFT)
	$(CC) $(CFLAGS) client.c - L./libft -lft -o $(CLIENT)

clean:
	make -C libft clean

fclean: clean
	make -C libft fclean
	rm -f $(NAME) $(CLIENT)

re: fclean

.PHONY: all clean fclean re
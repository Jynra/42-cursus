# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jynra <jynra@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 12:03:54 by ellucas           #+#    #+#              #
#    Updated: 2025/02/10 00:41:25 by jynra            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= server
CLIENT	= client
LIBFT	= libft/libft.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME) $(CLIENT)

$(LIBFT):
	make -C libft

$(NAME): $(LIBFT)
	$(CC) $(CFLAGS) server.c -L./libft -lft -o $(NAME)

$(CLIENT): $(LIBFT)
	$(CC) $(CFLAGS) client.c -L./libft -lft -o $(CLIENT)

clean:
	make -C libft clean

fclean: clean
	make -C libft fclean
	rm -f $(NAME) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
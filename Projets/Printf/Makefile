# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ellucas <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 17:04:25 by ellucas           #+#    #+#              #
#    Updated: 2024/11/27 14:02:11 by ellucas          ###   LAUSANNE.ch        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFTNAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBFTDIR = libft

SRCS = 	ft_printf.c \
		ft_printchar.c ft_printint.c ft_printstr.c ft_uprintnbr.c \
		ft_printhex_lower.c ft_printhex_up.c ft_printptr.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

makelibft:
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)


%.o: %.c
	@$(CC) $(CFLAGS) -I. -c $< -o $@

$(NAME): $(OBJS) $(makelibft)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	@cd $(LIBFTDIR) && make clean
	
fclean: clean
	rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean
	
re: fclean all


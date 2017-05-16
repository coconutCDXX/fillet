# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elopez <elopez@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/24 15:42:02 by elopez            #+#    #+#              #
#    Updated: 2017/04/24 15:55:26 by elopez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -c
FILES	= ./srcs/main.c ./srcs/check.c ./srcs/xy.c ./srcs/solve.c
OBJ		= main.o check.o xy.o solve.o

LIBFT	= ./libft/libft.a
LIBINC	= -I./libft
LIBLINK	= -L./libft -lft

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LIBLINK) -o $(NAME) $(OBJ)

$(OBJ): $(LIBFT)
	$(CC) $(CFLAGS) $(FILES) $(LIBINC)

$(LIBFT):
	make -C ./libft

clean:
	rm -f $(OBJ)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: clean fclean all re

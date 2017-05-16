# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elopez <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/18 23:40:47 by elopez            #+#    #+#              #
#    Updated: 2017/03/24 21:27:57 by elopez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I. -c
FILES		= ft_strdup.c ft_strlen.c ft_strcpy.c ft_strcat.c ft_strncpy.c \
			  ft_strncat.c ft_memset.c ft_memcpy.c ft_bzero.c ft_memccpy.c \
			  ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlcat.c ft_strchr.c \
			  ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
			  ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			  ft_isprint.c ft_toupper.c ft_tolower.c ft_islower.c ft_isupper.c \
			  ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
			  ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
			  ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
			  ft_countwords.c ft_word_len.c ft_itoa.c ft_putchar.c ft_putchar_fd.c\
			  ft_putstr.c ft_putstr_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c\
			  ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
			  ft_lstiter.c ft_lstmap.c ft_sum.c ft_module.c
OBJ			= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): $(FILES)
	$(CC) $(CFLAGS) $(FILES)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re

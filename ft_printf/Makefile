# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khotah <khotah@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/22 18:25:38 by khotah            #+#    #+#              #
#    Updated: 2020/12/06 13:12:15 by khotah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRC		= ft_printf.c ft_parser.c libft_len.c libft_put.c ft_type.c\
		if_percent.c if_char.c if_string.c if_uns_int.c if_hex.c if_pointer.c if_int.c

S_OBJ	= $(SRC:.c=.o)
INCL	= ft_printf.h
CC		= gcc
RM		= rm -f
FLAGS	= -Wall -Wextra -Werror -c

all:	$(NAME)

$(NAME): $(S_OBJ)
		ar rcs $(NAME) $(S_OBJ)

%.o: %.c $(INCL)
		$(CC) $(FLAGS) $< -o $@

clean:
		$(RM) $(S_OBJ)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all, clean, fclean, re

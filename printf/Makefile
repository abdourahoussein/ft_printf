# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abhousse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 22:39:51 by abhousse          #+#    #+#              #
#    Updated: 2021/12/09 22:39:55 by abhousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_printf_utlis.c
OBJS = $(SRC:.c=.o)

NAME = libftprintf.a
HEADER = ft_printf.h

%.o: %.c
	$(CC) $(CLFAGS) -c $^ -o $@ -I $(HEADER)

$(NAME): $(OBJS)
	ar -rcs $@ $^

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

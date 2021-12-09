# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abhousse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 16:33:21 by abhousse          #+#    #+#              #
#    Updated: 2021/12/08 16:33:22 by abhousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER = ft_printf.h

CC = cc

CFLAGS = -Wall -Wextra -Werror -I.

SRCS = ft_printf.c ft_printf_utils.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

$(NAME):    ${OBJS}
			ar -rcs $@ $^

%.o : %.c $(HEADER)
			$(CC) $(CFLAGS) -c $< -o $@
 
all:    $(NAME)

clean:    
		rm -f ${OBJS}

fclean:    clean
		rm -f ${NAME}
		
re:        fclean all
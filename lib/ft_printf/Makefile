# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ifadhli <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/21 03:12:50 by ifadhli           #+#    #+#              #
#    Updated: 2024/12/21 03:19:49 by ifadhli          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = ft_putchar.c	\
       ft_puthex.c	\
       ft_putnbr.c	\
       ft_putptr.c	\
       ft_putstr.c	\
       ft_putunint.c	\
       ft_printf.c	\

    
OBJECTS = $(SRCS:.c=.o)

all:  $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re:  fclean all

.PHONY: all fclean clean re

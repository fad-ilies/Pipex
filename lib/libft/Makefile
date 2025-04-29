# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ifadhli <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 03:32:09 by ifadhli           #+#    #+#              #
#    Updated: 2024/11/20 03:32:15 by ifadhli          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = ft_calloc.c    \
    ft_memchr.c    \
    ft_memmove.c    \
    ft_memcpy.c    \
    ft_memset.c    \
    ft_putchar_fd.c    \
    ft_putendl_fd.c    \
    ft_putnbr_fd.c    \
    ft_putstr_fd.c    \
    ft_bzero.c    \
    ft_strlcat.c    \
    ft_strlcpy.c    \
    ft_strlen.c    \
    ft_atoi.c    \
    ft_isalnum.c    \
    ft_isalpha.c    \
    ft_isascii.c    \
    ft_isdigit.c    \
    ft_isprint.c    \
    ft_tolower.c    \
    ft_toupper.c    \
    ft_memcmp.c    \
    ft_strncmp.c    \
    ft_strdup.c    \
    ft_strjoin.c    \
    ft_strnstr.c    \
    ft_strrchr.c    \
    ft_strtrim.c    \
    ft_substr.c    \
    ft_strchr.c    \
    ft_split.c    \
    ft_itoa.c    \
    ft_strmapi.c    \
    ft_striteri.c    \
    
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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apergens <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/09/25 08:56:14 by apergens          #+#    #+#              #
#   Updated: 2013/12/06 11:33:04 by apergens           ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

CC		= gcc

LIBNAME	= get_next_line

NAME	= lib$(LIBNAME).a

SRC		= ft_get_next_line.c ft_get_nbr_lines.c

OBJ		= $(patsubst %.c,srcs/%.o,$(SRC))

HEADER = ../includes

CFLAGS = -Wall -Wextra -Werror -pedantic -ansi -I$(HEADER) -O3

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

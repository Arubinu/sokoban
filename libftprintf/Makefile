# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apergens <apergens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/17 13:48:08 by apergens          #+#    #+#              #
#    Updated: 2013/12/21 07:45:19 by apergens           ###   ########.fr      #
#                                                                              #
# **************************************************************************** #

CC = gcc

LIBNAME	= ftprintf

NAME	= lib$(LIBNAME).a

SRC		= ft_printf.c ft_printf_fd.c ft_printf_arg.c ft_get_v_arg.c \
		ft_pf_c.c ft_pf_d.c ft_pf_f.c ft_pf_s.c ft_pf_x.c

OBJ		= $(patsubst %.c,srcs/%.o,$(SRC))

HEADER	= ../includes

CFLAGS	= -Wall -Wextra -Werror -I$(HEADER) -O3

all: $(NAME)

$(NAME): $(LOBJ) $(OBJ)
	ar rc $(NAME) $(LOBJ) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(LOBJ) $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

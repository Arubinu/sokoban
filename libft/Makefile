# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apergens <apergens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/09/25 08:56:14 by apergens          #+#    #+#              #
#    Updated: 2014/01/19 23:40:42 by apergens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc

LIBNAME	= ft

NAME	= lib$(LIBNAME).a

SRC		= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isgraph.c ft_islower.c ft_isprint.c ft_ispunct.c \
		ft_isupper.c ft_isxdigit.c ft_itoa.c ft_memalloc.c ft_memccpy.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
		ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
		ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c \
		ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c \
		ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
		ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
		ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
		ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
		ft_tolower.c ft_toupper.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
		ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_ilen.c ft_strclen.c \
		ft_strfjoin.c ft_strfsub.c ft_free_return.c ft_strcchr.c \
		ft_strftrim.c ft_strfsplit.c ft_lstcmp.c ft_ftoa.c ft_xtoa.c \
		ft_strins.c ft_argtrim.c ft_putlst.c ft_free_strtab.c ft_lstaddend.c \
		ft_lstlen.c ft_lsttoa.c ft_putchar_loop.c ft_putchar_loop_fd.c \
		ft_tablen.c ft_ctoa.c

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

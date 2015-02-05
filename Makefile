# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apergens <apergens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/09/25 08:56:14 by apergens          #+#    #+#              #
#    Updated: 2014/01/24 14:39:04 by apergens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc

NAME	= sokoban

LNAME	= ft ftprintf get_next_line

DIR		= $(patsubst %,lib%,$(LNAME))

HDR		= $(patsubst %,%/%.a,$(DIR))

SRC		= main.c ft_sdkn_background.c ft_sdkn_call_game.c ft_sdkn_call_map.c \
		ft_sdkn_call_menu.c ft_sdkn_create_cube.c ft_sdkn_filelevel.c \
		ft_sdkn_free_cube.c ft_sdkn_loadlevel.c ft_sdkn_mapsize.c \
		ft_sdkn_menu.c ft_sdkn_putimg.c ft_sdkn_putrect.c ft_sdkn_rect.c \
		ft_sdkn_move.c ft_sdkn_check.c ft_sdkn_puttitle.c ft_sdkn_putcmt.c \
		ft_sdkn_putinfos.c ft_sdkn_zoom.c ft_sdkn_next.c ft_sdkn_end.c \
		ft_sdkn_render.c ft_sdkn_winsize.c ft_sdkn_create.c

OBJ		= $(patsubst %.c,srcs/%.o,$(SRC))

LFLAGS3 = `sdl-config --cflags --libs`
LFLAGS2 = -lSDL2 -lSDL2_image -lSDL2_gfx -lSDL2_ttf -lSDL2_mixer -lm
LFLAGS	= $(patsubst %,-L%,$(DIR)) $(patsubst %,-l%,$(LNAME)) $(LFLAGS2)

CFLAGS	= -Wall -Wextra -Werror -pedantic -I./includes -g

all: lib sdl $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LFLAGS) -o $(NAME) $(OBJ)

sdl:
	brew install sdl2 sdl2_image sdl2_gfx sdl2_ttf SDL2_mixer

lib:
	$(foreach var,$(DIR),make -C $(var);)

libclean:
	$(foreach var,$(DIR),make -C $(var) clean;)

binclean:
	rm -f $(OBJ)

clean: libclean binclean

libfclean: libclean
	$(foreach var,$(DIR),make -C $(var) fclean;)

binfclean: binclean
	rm -f $(NAME)

fclean: libfclean binfclean

binre: binfclean $(NAME)

re: fclean all

.PHONY: all libclean binclean clean libfclean binfclean fclean binre re lib sdl

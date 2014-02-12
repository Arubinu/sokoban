/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sokoban.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 21:49:42 by apergens          #+#    #+#             */
/*   Updated: 2014/01/24 14:17:40 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_SDL_H
# define TEST_SDL_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_mixer.h>
# include <SDL2/SDL2_rotozoom.h>
# include <SDL2/SDL_ttf.h>

# include "libft.h"
# include "libftprintf.h"
# include "libget_next_line.h"

# define DIR_MAPS	"content/maps/level_"

# define WIN_W		800
# define WIN_H		450
# define WIN_F		0
# define WIN_P		SDL_WINDOWPOS_CENTERED
# define WIN_R		SDL_RENDERER_ACCELERATED
# define WIN_S		SDL_WINDOW_INPUT_FOCUS

# define GAME_X		0
# define GAME_Y		10

# define MINI_X		12
# define MINI_Y		80
# define MINI_W		460
# define MINI_H		260

# define CUBE_W		20
# define CUBE_H		20

typedef struct	s_surf
{
	SDL_Surface		*surf;
	SDL_Rect		rect;
	Uint32			color;
}				t_surf;

typedef struct	s_game
{
	SDL_Window		*win;
	SDL_Renderer	*render;
	SDL_Surface		*icon;
	SDL_Surface		**cube;
	SDL_Event		event;
	t_surf			image;
}				t_game;

typedef struct	s_rgba
{
	Uint8	r;
	Uint8	g;
	Uint8	b;
	Uint8	a;
}				t_rgba;

/*
** Map (320 x 240) blocks :
**  0 void,
**  1 wall,
**  2 player,
**  3 cube,
**  4 checkpoint,
**  5 player + checkpoint,
**  6 cube + checkpoint.
*/

void		ft_sdkn_background(t_game *game, SDL_Surface **win, int refresh);
int			ft_sdkn_call_menu(t_game *game, int level, int view);
void		ft_sdkn_call_game(t_game *game);
int			ft_sdkn_call_map(t_game *game, int level, int reset, int refresh);
int			ft_sdkn_check(void);
void		ft_sdkn_create(SDL_Surface **surf, int width, int height, int pfree);
int			ft_sdkn_create_cube(SDL_Surface ***cube, int nbr);
void		ft_sdkn_end(t_game *game, int *level, int *wait);
char		***ft_sdkn_filelevel(int level, int reset, char *****out);
void		ft_sdkn_free_cube(SDL_Surface ***cube, int nbr);
t_surf		ft_sdkn_loadlevel(t_game *game, int level, int move, int reset);
char		****ft_sdkn_mapsave(void);
int			ft_sdkn_mapsize(int w, int h, int set);
SDL_Surface	*ft_sdkn_menu(t_game *game, int level, int *move, int pfree);
char		***ft_sdkn_move(int move);
void		ft_sdkn_next(t_game *game, int *level);
void		ft_sdkn_putcmt(SDL_Surface *surf, char *str, int x, int y);
void		ft_sdkn_putimg(SDL_Surface *win, SDL_Surface *image, SDL_Rect rect, int alpha);
int			ft_sdkn_putinfos(t_game *game, int hits, int reset, int val);
void		ft_sdkn_putrect(SDL_Surface *win, t_surf surface);
void		ft_sdkn_puttitle(SDL_Surface *surf, char *str, int x, int y);
SDL_Rect	ft_sdkn_rect(int x, int y, int width, int height);
void		ft_sdkn_render(t_game *game);
SDL_Rect	ft_sdkn_winsize(t_game *game, int width, int height);
double		ft_sdkn_zoom(int w, int h, int wmax, int hmax);

#endif

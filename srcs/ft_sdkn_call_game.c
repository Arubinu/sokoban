/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdkn_call_game.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/20 01:02:27 by apergens          #+#    #+#             */
/*   Updated: 2014/01/24 14:08:03 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sokoban.h"

static void		ft_sdkn_call_game_w1(t_game *game, int *wait, int *level);
static void		ft_sdkn_call_game_w2(t_game *game, int *wait, int *move, int level);

void	ft_sdkn_call_game(t_game *game)
{
	int		full;
	int		move;
	int		wait;
	int		level;

	/*SDL_EnableKeyRepeat(150, 150);*/
	SDL_ShowCursor(SDL_DISABLE);
	full = WIN_F;
	move = 0;
	wait = 2;
	level = 1;
	ft_sdkn_menu(game, level, NULL, 0);
	while (wait)
	{
		SDL_WaitEvent(&game->event);
		if (game->event.type == SDL_QUIT)
			wait = 0;
		if (game->event.type == SDL_KEYUP || game->event.type == SDL_QUIT)
			continue ;
		else if (game->event.key.keysym.sym == SDLK_f)
		{
			full = !full ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0;
			SDL_SetWindowFullscreen(game->win, full);
		}
		else if (wait == 2)
			ft_sdkn_call_game_w2(game, &wait, &move, level);
		else if (wait == 1)
			ft_sdkn_call_game_w1(game, &wait, &level);
		if (wait == 1)
			ft_sdkn_call_map(game, level, 0, 1);
		ft_sdkn_render(game);
	}
	ft_sdkn_menu(game, level, NULL, 1);
	return ;
}

static void		ft_sdkn_call_game_w1(t_game *game, int *wait, int *level)
{
	char	*file;

	if (game->event.key.keysym.sym == SDLK_UP)
		ft_sdkn_call_map(game, *level, 0, 2);
	else if (game->event.key.keysym.sym == SDLK_DOWN)
		ft_sdkn_call_map(game, *level, 0, 3);
	else if (game->event.key.keysym.sym == SDLK_LEFT)
		ft_sdkn_call_map(game, *level, 0, 4);
	else if (game->event.key.keysym.sym == SDLK_RIGHT)
		ft_sdkn_call_map(game, *level, 0, 5);
	else if (game->event.key.keysym.sym == SDLK_z)
		ft_sdkn_call_map(game, *level, 0, 2);
	else if (game->event.key.keysym.sym == SDLK_s)
		ft_sdkn_call_map(game, *level, 0, 3);
	else if (game->event.key.keysym.sym == SDLK_q)
		ft_sdkn_call_map(game, *level, 0, 4);
	else if (game->event.key.keysym.sym == SDLK_d)
		ft_sdkn_call_map(game, *level, 0, 5);
	else if (game->event.key.keysym.sym == SDLK_r)
	{
		ft_sdkn_putinfos(NULL, 0, 0, 1);
		ft_sdkn_putinfos(NULL, 0, 1, -3);
		ft_sdkn_call_map(game, *level, 1, 0);
	}
	else if (game->event.key.keysym.sym == SDLK_ESCAPE
		|| game->event.window.event == SDL_WINDOWEVENT_FOCUS_LOST)
		*wait = ft_sdkn_call_menu(game, *level, 1) + 2;
	if (ft_sdkn_check())
	{
		file = ft_itoa(*level + 1);
		file = ft_strfjoin2(DIR_MAPS, &file, 1);
		if (access(file, R_OK) > -1)
			ft_sdkn_next(game, level);
		else
			ft_sdkn_end(game, level, wait);
	}
	return ;
}

static void		ft_sdkn_call_game_w2(t_game *game, int *wait, int *move, int level)
{
	if (game->event.key.keysym.sym == SDLK_UP && (*move = -1))
		ft_sdkn_menu(game, level, move, 0);
	else if (game->event.key.keysym.sym == SDLK_DOWN && (*move = 1))
		ft_sdkn_menu(game, level, move, 0);
	else if (game->event.key.keysym.sym == SDLK_z && (*move = -1))
		ft_sdkn_menu(game, level, move, 0);
	else if (game->event.key.keysym.sym == SDLK_s && (*move = 1))
		ft_sdkn_menu(game, level, move, 0);
	else if (game->event.key.keysym.sym == SDLK_RETURN && !*move)
		*wait = ft_sdkn_call_menu(game, level, 0);
	else if (game->event.key.keysym.sym == SDLK_RETURN && *move == 2)
		*wait = 0;
	else if (game->event.key.keysym.sym == SDLK_RETURN && *move == 1)
	{
		ft_sdkn_putinfos(NULL, 0, 0, 1);
		ft_sdkn_putinfos(NULL, 0, 1, -3);
		ft_sdkn_call_map(game, level, 1, 0);
		ft_sdkn_call_menu(game, level, 0);
		*wait = 1;
	}
	else if (game->event.key.keysym.sym == SDLK_ESCAPE)
		*wait = 0;
	return ;
}

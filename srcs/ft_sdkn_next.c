/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdkn_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 03:08:11 by apergens          #+#    #+#             */
/*   Updated: 2014/01/24 14:28:42 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sokoban.h"

static void	ft_sdkn_next_score(SDL_Surface *next);
static void	ft_sdkn_next_while(t_game *game, int *lvl, SDL_Surface *n, int v);

void		ft_sdkn_next(t_game *game, int *level)
{
	SDL_Rect		rect;
	SDL_Surface		*tmp;
	SDL_Surface		*next;

	rect = ft_sdkn_rect(0, 0, WIN_W, WIN_H);
	SDL_SetWindowTitle(game->win, "Sokoban - Niveau Fini");
	tmp = IMG_Load("content/images/next.png");
	ft_sdkn_create(&next, WIN_W, WIN_H, 0);
	ft_sdkn_putimg(next, game->image.surf, rect, -1);
	ft_sdkn_putimg(next, tmp, rect, -1);
	ft_sdkn_next_score(next);
	SDL_FreeSurface(tmp);
	ft_sdkn_next_while(game, level, next, 1);
	SDL_WaitEvent(&game->event);
	while (game->event.type != SDL_KEYDOWN)
		SDL_WaitEvent(&game->event);
	*level += 1;
	ft_sdkn_putinfos(NULL, 0, 0, 1);
	ft_sdkn_putinfos(NULL, 0, 0, 2);
	ft_sdkn_next_while(game, level, next, 0);
	SDL_FreeSurface(next);
	return ;
}

static void	ft_sdkn_next_score(SDL_Surface *next)
{
	char			*tmp;

	tmp = ft_itoa(ft_sdkn_putinfos(NULL, 0, 0, 4));
	ft_sdkn_putcmt(next, tmp, 635, 165 + 48);
	free(tmp);
	tmp = ft_itoa(ft_sdkn_putinfos(NULL, 0, 0, 3));
	ft_sdkn_putcmt(next, tmp, 635, 165);
	free(tmp);
	/*
	tmp = ft_itoa(h);
	ft_sdkn_putcmt(next, tmp, 635, 165 + (48 * 2));
	free(str);
	*/
	return ;
}

static void	ft_sdkn_next_while(t_game *game, int *lvl, SDL_Surface *n, int v)
{
	int				alpha;
	SDL_Rect		rect;

	alpha = v ? 1 : 254;
	rect = ft_sdkn_rect(0, 0, WIN_W, WIN_H);
	if (!v)
		ft_sdkn_putimg(n, game->image.surf, rect, -1);
	while (42)
	{
		if (alpha >= 255 || alpha <= 0)
			break ;
		alpha += v ? 10 : -10;
		alpha = (alpha < 0) ? 0 : alpha;
		alpha = (alpha > 255) ? 255 : alpha;
		ft_sdkn_call_map(game, *lvl, 0, 0);
		ft_sdkn_putimg(game->image.surf, n, rect, alpha);
		ft_sdkn_render(game);
	}
	return ;
}

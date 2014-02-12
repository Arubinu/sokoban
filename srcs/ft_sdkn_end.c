/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdkn_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 03:08:11 by apergens          #+#    #+#             */
/*   Updated: 2014/01/24 14:28:26 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sokoban.h"

static void	ft_sdkn_end_while(t_game *game, int *lvl, SDL_Surface *end, int v);

void		ft_sdkn_end(t_game *game, int *level, int *wait)
{
	SDL_Rect		rect;
	SDL_Surface		*tmp;
	SDL_Surface		*end;

	rect = ft_sdkn_rect(0, 0, WIN_W, WIN_H);
	SDL_SetWindowTitle(game->win, "Sokoban - Game Over");
	tmp = IMG_Load("content/images/end.png");
	ft_sdkn_create(&end, WIN_W, WIN_H, 0);
	ft_sdkn_putimg(end, game->image.surf, rect, -1);
	ft_sdkn_putimg(end, tmp, rect, -1);
	SDL_FreeSurface(tmp);
	ft_sdkn_end_while(game, level, end, 1);
	SDL_WaitEvent(&game->event);
	while (game->event.type != SDL_KEYDOWN)
		SDL_WaitEvent(&game->event);
	ft_sdkn_end_while(game, level, end, 0);
	*wait = 2;
	*level = 1;
	SDL_FreeSurface(end);
	return ;
}

static void	ft_sdkn_end_while(t_game *game, int *lvl, SDL_Surface *end, int v)
{
	int				alpha;
	SDL_Rect		rect;

	alpha = v ? 1 : 254;
	rect = ft_sdkn_rect(0, 0, WIN_W, WIN_H);
	if (!v)
		ft_sdkn_putimg(end, game->image.surf, rect, -1);
	while (42)
	{
		if (alpha >= 255 || alpha <= 0)
			break ;
		alpha += v ? 10 : -10;
		alpha = (alpha < 0) ? 0 : alpha;
		alpha = (alpha > 255) ? 255 : alpha;
		if (v)
			ft_sdkn_call_map(game, *lvl, 0, 0);
		else
			ft_sdkn_menu(game, *lvl, NULL, 0);
		ft_sdkn_putimg(game->image.surf, end, rect, alpha);
		ft_sdkn_render(game);
	}
	return ;
}

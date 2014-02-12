/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdkn_call_menu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/20 01:03:22 by apergens          #+#    #+#             */
/*   Updated: 2014/01/24 14:26:28 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sokoban.h"

int		ft_sdkn_call_menu(t_game *game, int level, int view)
{
	int				alpha;
	char			*title;
	t_game			game2;
	SDL_Rect		rect;
	SDL_Surface		*temp;

	alpha = view ? 1 : 204;
	rect = ft_sdkn_rect(0, 0, WIN_W, WIN_H);
	ft_sdkn_create(&temp, WIN_W, WIN_H, 0);
	ft_sdkn_background(game, &temp, 0);
	game2 = *game;
	game2.image.surf = temp;
	ft_sdkn_putimg(temp, ft_sdkn_menu(&game2, level, NULL, 0), rect, -1);
	ft_sdkn_call_map(&game2, level, 0, -2);
	while (42)
	{
		if (alpha >= 205 || alpha <= 0)
			break ;
		alpha += view ? 10 : -10;
		alpha = (alpha < 0) ? 0 : alpha;
		alpha = (alpha > 205) ? 205 : alpha;
		ft_sdkn_call_map(game, level, 0, 0);
		ft_sdkn_putimg(game->image.surf, temp, rect, alpha);
		ft_sdkn_render(game);
	}
	SDL_FreeSurface(temp);
	if (!view)
	{
		if (level)
		{
			title = ft_itoa(level);
			title = ft_strfjoin2("Sodokan - Niveau ", &title, 1);
			SDL_SetWindowTitle(game->win, title);
			free(title);
		}
		ft_sdkn_menu(game, level, NULL, 1);
	}
	else if (ft_sdkn_menu(game, level, NULL, 0))
		SDL_SetWindowTitle(game->win, "Sokoban - Pause");
	view = view ? 0 : 1;
	return (view);
}

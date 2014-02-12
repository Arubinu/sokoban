/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdkn_call_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/20 00:58:43 by apergens          #+#    #+#             */
/*   Updated: 2014/01/24 14:22:04 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sokoban.h"

static int	ft_sdkn_call_map_mini(t_game *game, t_surf *map);

int			ft_sdkn_call_map(t_game *game, int level, int reset, int refresh)
{
	int				ratio;
	char			*title;
	t_surf			map;
	SDL_Surface		*resize;

	if (!(map = ft_sdkn_loadlevel(game, level, refresh - 1, reset)).surf)
		return (0);
	if (refresh == -2)
		return (ft_sdkn_call_map_mini(game, &map));
	ft_sdkn_background(game, &game->image.surf, 0);
	ratio = ft_sdkn_zoom(map.surf->w, map.surf->h, 690, 325);
	resize = rotozoomSurface(map.surf, 0, ratio, SMOOTHING_ON);
	map.rect.x = (WIN_W - resize->w) / 2 + GAME_X;
	map.rect.y = (WIN_H - resize->h) / 2 + GAME_Y;
	map.rect = ft_sdkn_rect(map.rect.x, map.rect.y, resize->w, resize->h);
	SDL_SetColorKey(resize, SDL_TRUE, SDL_MapRGB(resize->format, 29, 29, 29));
	ft_sdkn_putimg(game->image.surf, resize, map.rect, -1);
	SDL_FreeSurface(resize);
	title = ft_itoa(level);
	title = ft_strfjoin2("Niveau", &title, 1);
	ft_sdkn_puttitle(game->image.surf, title, 25, 10);
	free(title);
	ft_sdkn_putinfos(game, 0, 0, 0);
	if (refresh == 1)
		ft_sdkn_render(game);
	return (1);
}

static int	ft_sdkn_call_map_mini(t_game *game, t_surf *map)
{
	int				x;
	int				y;
	double			ratio;
	SDL_Surface		*mini;
	SDL_Surface		*temp;

	ratio = ft_sdkn_zoom(map->surf->w, map->surf->h, MINI_W, MINI_H);
	temp = rotozoomSurface(map->surf, 3, ratio, SMOOTHING_ON);
	SDL_SetColorKey(temp, SDL_TRUE, SDL_MapRGB(temp->format, 0, 0, 0));
	ft_sdkn_create(&mini, temp->w, temp->h, 0);
	SDL_FillRect(mini, NULL, SDL_MapRGB(mini->format, 29, 29, 29));
	ft_sdkn_putimg(mini, temp, ft_sdkn_rect(0, 0, temp->w, temp->h), -1);
	SDL_SetColorKey(mini, SDL_TRUE, SDL_MapRGB(mini->format, 29, 29, 29));
	x = MINI_X + (MINI_W - mini->w) / 2;
	y = MINI_Y + (MINI_H - mini->h) / 2;
	ft_sdkn_putimg(game->image.surf, mini, ft_sdkn_rect(x, y, mini->w, mini->h), -1);
	SDL_FreeSurface(temp);
	SDL_FreeSurface(mini);
	return (1);
}

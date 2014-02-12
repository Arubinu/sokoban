/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdkn_call_minimap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/20 00:58:43 by apergens          #+#    #+#             */
/*   Updated: 2014/01/23 04:27:22 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sokoban.h"

int		ft_sdkn_call_map(t_game *game, int level, int reset, int refresh)
{
	char			*title;
	t_surf			map;
	SDL_Surface		*ratio;

	if (!(map = ft_sdkn_loadlevel(game, level, refresh - 1, reset)).surf)
		return (0);
	map.rect.x = (game->win->w - map.surf->w) / 2;
	map.rect.y = (game->win->h - map.surf->h) / 2;
	ft_sdkn_background(game, &game->image.surf, 0);
	ratio = rotozoomSurface(map.surf, 0, ft_sdkn_zoom(map.surf->w, map.surf->h, 690, 325), SMOOTHING_ON);
	ft_sdkn_putimg(game->win, ratio, ft_sdkn_rect((WIN_W - ratio->w) / 2, (WIN_H - ratio->h) / 2, ratio->w, ratio->h), -1);
	SDL_FreeSurface(ratio);
	title = ft_itoa(level);
	title = ft_strfjoin2("Niveau", &title, 1);
	ft_sdkn_puttitle(game->image.surf, title, 25, 10);
	free(title);
	ft_sdkn_putinfos(game, 0, 0, 0);
	if (refresh == 1)
		ft_sdkn_render(game);
	return (1);
}

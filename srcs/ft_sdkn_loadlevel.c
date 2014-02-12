/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdkn_loadlevel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/20 00:59:18 by apergens          #+#    #+#             */
/*   Updated: 2014/01/24 14:15:05 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sokoban.h"

t_surf	ft_sdkn_loadlevel(t_game *game, int level, int move, int reset)
{
	int				x;
	int				y;
	char			***file;
	static t_surf	map;
	SDL_Rect		rect;

	if ((file = ft_sdkn_filelevel(level, reset, NULL)) == NULL)
	{
		if (!(file = ft_sdkn_move(move)))
			return (map);
	}
	x = ft_sdkn_mapsize(0, 0, 0) * CUBE_W;
	y = ft_sdkn_mapsize(0, 0, 1) * CUBE_H;
	ft_sdkn_create(&map.surf, x, y, 1);
	SDL_FillRect(map.surf, NULL, SDL_MapRGB(map.surf->format, 29, 29, 29));
	map.rect = ft_sdkn_rect(0, 0, map.surf->w, map.surf->h);
	y = -1;
	while (++y < map.surf->h / CUBE_H && (x = -1)
		&& *(file + y) && *(*(file + y) + (x + 1)))
	{
		while (++x < map.surf->w / CUBE_W && *(*(file + y) + x))
		{
			if (!(move = ft_atoi(*(*(file + y) + x))))
				continue ;
			rect = ft_sdkn_rect(x * CUBE_W, y * CUBE_H, CUBE_W, CUBE_H);
			ft_sdkn_putimg(map.surf, *(game->cube + move), rect, -1);
		}
	}
	map.color = SDL_MapRGB(map.surf->format, 29, 29, 29);
	return (map);
}

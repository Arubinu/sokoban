/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdkn_background.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/20 00:58:06 by apergens          #+#    #+#             */
/*   Updated: 2014/01/23 01:09:10 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sokoban.h"

void	ft_sdkn_background(t_game *game, SDL_Surface **surf, int refresh)
{
	Uint32	color;

	if (!surf)
		return ;
	if (!*surf)
		*surf = SDL_CreateRGBSurface(0, WIN_W, WIN_H, 32, 0, 0, 0, 0);
	color = SDL_MapRGB((*surf)->format, 29, 29, 29);
	SDL_FillRect(*surf, NULL, color);
	if (refresh)
		ft_sdkn_render(game);
	return ;
}

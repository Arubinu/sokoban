/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdkn_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 01:11:11 by apergens          #+#    #+#             */
/*   Updated: 2014/01/23 04:18:43 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sokoban.h"

void	ft_sdkn_render(t_game *game)
{
	SDL_Rect		rect;
	SDL_Texture		*texture;

	rect = ft_sdkn_winsize(game, 0, 0);
	texture = SDL_CreateTextureFromSurface(game->render, game->image.surf);
	SDL_RenderCopy(game->render, texture, NULL, &rect);
	SDL_RenderPresent(game->render);
	SDL_DestroyTexture(texture);
	return ;
}

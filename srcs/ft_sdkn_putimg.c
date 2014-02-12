/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdkn_putimg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/20 01:01:26 by apergens          #+#    #+#             */
/*   Updated: 2014/01/23 04:25:32 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sokoban.h"

void	ft_sdkn_putimg(SDL_Surface *win, SDL_Surface *image, SDL_Rect rect, int alpha)
{
	if (alpha >= 0)
	{
		SDL_SetSurfaceBlendMode(image, SDL_BLENDMODE_BLEND);
		SDL_SetSurfaceAlphaMod(image, alpha);
	}
	SDL_BlitSurface(image, NULL, win, &rect);
	return ;
}

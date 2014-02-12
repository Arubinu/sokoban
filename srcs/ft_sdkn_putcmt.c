/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdkn_putcmt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/20 09:37:50 by apergens          #+#    #+#             */
/*   Updated: 2014/01/24 14:33:23 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sokoban.h"

void	ft_sdkn_putcmt(SDL_Surface *surf, char *str, int x, int y)
{
	int				size;
	TTF_Font		*font;
	SDL_Color		color = {109, 115, 140, 0};
	SDL_Color		color2 = {0, 0, 0, 0};
	SDL_Surface		*text;

	size = (y < (WIN_H - 25)) ? 32 : 12;
	font = TTF_OpenFont("content/fonts/south_park.ttf", size);
	text = TTF_RenderText_Blended(font, str, color2);
	x = (x == -1) ? (WIN_W - text->w) / 2 : x;
	x -= (y < (WIN_H - 25)) ? text->w : 0;
	ft_sdkn_putimg(surf, text, ft_sdkn_rect(x + 3, y + 3, text->w, text->h), -1);
	SDL_FreeSurface(text);
	text = TTF_RenderText_Blended(font, str, color);
	x = (x == -1) ? (WIN_W - text->w) / 2 : x;
	/*x -= (y < (WIN_H - 25)) ? text->w : 0;*/
	ft_sdkn_putimg(surf, text, ft_sdkn_rect(x, y, text->w, text->h), -1);
	SDL_FreeSurface(text);
	TTF_CloseFont(font);
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdkn_puttitle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/20 09:37:50 by apergens          #+#    #+#             */
/*   Updated: 2014/01/23 04:29:11 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sokoban.h"

void	ft_sdkn_puttitle(SDL_Surface *surf, char *str, int x, int y)
{
	TTF_Font		*font;
	SDL_Color		color = {109, 115, 140, 0};
	SDL_Color		color2 = {0, 0, 0, 0};
	SDL_Surface		*text;

	font = TTF_OpenFont("content/fonts/slant.ttf", 56);
	text = TTF_RenderText_Blended(font, str, color2);
	y = (y == -1) ? (WIN_W - text->w / 2) : y;
	ft_sdkn_putimg(surf, text, ft_sdkn_rect(x + 3, y + 3, text->w, text->h), -1);
	SDL_FreeSurface(text);
	text = TTF_RenderText_Blended(font, str, color);
	y = (y == -1) ? (WIN_W - text->w / 2) : y;
	ft_sdkn_putimg(surf, text, ft_sdkn_rect(x, y, text->w, text->h), -1);
	SDL_FreeSurface(text);
	TTF_CloseFont(font);
	return ;
}
